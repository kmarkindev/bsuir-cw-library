# Build api server
FROM --platform=linux/amd64 ubuntu:22.10 as ApiServerBuild

ARG BUILD_TYPE=release

# Install all packages
RUN apt-get update -y && \
    apt-get install cmake git curl zip unzip tar build-essential pkg-config make \
    	libgtk-3-dev libsecret-1-dev libgcrypt20-dev libsystemd-dev \
    	mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev libgl1-mesa-dev libgles2-mesa-dev -y

# Copy sources into work dir
WORKDIR /Workdir
COPY . .

# Install vcpkg
WORKDIR /vcpkg
RUN git clone https://github.com/Microsoft/vcpkg.git . && \
    ./bootstrap-vcpkg.sh

# Finally configure and build
WORKDIR /Workdir/BuildResult
RUN export CC=/usr/bin/gcc && export CXX=/usr/bin/g++ && export CMAKE_MAKE_PROGRAM=/usr/bin/make && \
	cmake .. -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_SYSTEM_NAME=Linux && \
    cmake --build . --target ApiServer --config "$BUILD_TYPE"

FROM --platform=linux/amd64 ubuntu:22.10 as ClientBuild

ARG BUILD_TYPE=release

# Install all packages and add additional repos
RUN apt-get update -y && \
    apt-get install wget apt-transport-https software-properties-common -y && \
    echo "deb http://security.ubuntu.com/ubuntu impish-security main" | tee /etc/apt/sources.list.d/impish-security.list && \
	wget -q https://packages.microsoft.com/config/ubuntu/20.04/packages-microsoft-prod.deb && \
	dpkg -i packages-microsoft-prod.deb && \
    apt-get update -y && \
    apt-get install cmake make pkg-config git curl zip unzip tar libssl1.1 powershell \
    	gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64 binutils-mingw-w64-x86-64 mingw-w64-x86-64-dev -y

# Copy sources into work dir
WORKDIR /Workdir
COPY . .

# Install vcpkg
WORKDIR /vcpkg
RUN git clone https://github.com/Microsoft/vcpkg.git . && \
    ./bootstrap-vcpkg.sh

# TODO: Fix it in some more elegant way?
# Need to create symlinks since some packages can't find win32 headers without first capical letter
RUN ln -s /usr/x86_64-w64-mingw32/include/windows.h /usr/x86_64-w64-mingw32/include/Windows.h && \
	ln -s /usr/x86_64-w64-mingw32/include/winsock2.h /usr/x86_64-w64-mingw32/include/WinSock2.h && \
    ln -s /usr/x86_64-w64-mingw32/include/rpc.h /usr/x86_64-w64-mingw32/include/Rpc.h && \
# Set compiler symlink to posix since we need to support std threading library
	echo '1' | update-alternatives --config x86_64-w64-mingw32-g++ && \
    echo '1' | update-alternatives --config x86_64-w64-mingw32-gcc

# Finally run configuration and build
WORKDIR /Workdir/BuildResult
RUN export CC=/usr/bin/x86_64-w64-mingw32-gcc && export CXX=/usr/bin/x86_64-w64-mingw32-g++ && export CMAKE_MAKE_PROGRAM=/usr/bin/make && \
	cmake .. -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_SYSTEM_NAME=Windows && \
    cmake --build . --target Client --config "$BUILD_TYPE"

# Create image which holds built artifacts
FROM --platform=linux/amd64 ubuntu:22.10 as ResultImage

RUN apt-get update -y && \
    apt-get install brotli -y

# Copy all compiled binaries
COPY --from=ApiServerBuild /Workdir/BuildResult/api-server-bin /api-server-bin
COPY --from=ClientBuild /Workdir/BuildResult/client-bin /api-server-bin/client

WORKDIR api-server-bin

# Add metadata to image
VOLUME /api-server-bin/configs
VOLUME /api-server-bin/storage
EXPOSE 7788

ENTRYPOINT ./ApiServer