# Build api server
FROM --platform=linux/amd64 ubuntu:22.10 as ApiServerBuild

ARG BUILD_TYPE=release

RUN apt-get update -y && \
    apt-get install cmake git curl zip unzip tar build-essential -y

WORKDIR /vcpkg

RUN git clone https://github.com/Microsoft/vcpkg.git . && \
    ./bootstrap-vcpkg.sh

WORKDIR /Workdir

RUN apt-get install pkg-config -y

COPY . .

WORKDIR BuildResult

RUN cmake .. -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake && \
    cmake --build . --target ApiServer --config "$BUILD_TYPE"

FROM --platform=linux/amd64 ubuntu:22.10 as ClientBuild

ARG BUILD_TYPE=release

RUN apt-get update -y && \
    apt-get install cmake git curl zip unzip tar \
    	binutils-mingw-w64-x86-64 g++-mingw-w64-x86-64-win32 gcc-mingw-w64-x86-64-win32 -y

WORKDIR /vcpkg

RUN git clone https://github.com/Microsoft/vcpkg.git . && \
    ./bootstrap-vcpkg.sh

WORKDIR /Workdir

COPY . .

WORKDIR BuildResult

RUN cmake .. -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake \
    	-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=../Cmake/linux_to_win32_toolchain.cmake && \
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