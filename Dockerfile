# Build api server
FROM --platform=linux/amd64 ubuntu:22.10 as ApiServerBuild

ARG BUILD_TYPE=release

RUN apt-get update -y && \
    apt-get install aptitude -y && \
    aptitude update -y && \
    aptitude install cmake python3 python3-pip uuid-dev build-essential -y && \
    pip install conan

WORKDIR Workdir

# Copy all sources into container
COPY . .

# Copy conan profiles
COPY Build/ConanProfiles /root/.conan/profiles

WORKDIR BuildResult

RUN conan install -b=missing -pr=conan-"$BUILD_TYPE"-profile-linux32_64 .. && \
    cmake .. -DSKIP_WX=True && \
    cmake --build . --target ApiServer --config "$BUILD_TYPE"

FROM --platform=linux/amd64 ubuntu:22.10 as ClientBuild

ARG BUILD_TYPE=release

RUN apt-get update -y && \
    apt-get install aptitude -y && \
    aptitude update -y && \
    aptitude install cmake python3 python3-pip binutils-mingw-w64-x86-64 g++-mingw-w64-x86-64-win32 gcc-mingw-w64-x86-64-win32 -y && \
    pip install conan

WORKDIR Workdir

# Copy all sources into container
COPY . .

# Copy conan profiles
COPY Build/ConanProfiles /root/.conan/profiles

WORKDIR BuildResult

RUN aptitude install m4 libtool pkg-config autoconf-archive -y

RUN ls /usr/bin/
RUN m4 --version

RUN conan install -b=missing -pr=conan-"$BUILD_TYPE"-profile-crosswin32_64 .. && \
    cmake .. --toolchain ../Build/Toolchains/linux_to_win32_toolchain.cmake -DSKIP_DROGON=True && \
    cmake --build . --target Client --config "$BUILD_TYPE"

# Create image which holds built artifacts
FROM --platform=linux/amd64 ubuntu:22.10 as ResultImage

COPY --from=ApiServerBuild /Workdir/BuildResult/api-server-bin /api-server-bin
COPY --from=ClientBuild /Workdir/BuildResult/client-bin /api-server-bin/client

WORKDIR api-server-bin

# Add metadata to image
VOLUME /api-server-bin/configs
VOLUME /api-server-bin/storage
EXPOSE 7788

ENTRYPOINT ./ApiServer