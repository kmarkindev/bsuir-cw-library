# Build api server
FROM --platform=linux/amd64 ubuntu:22.10 as ApiServerBuild

ARG BUILD_TYPE=release

RUN apt-get update -y && \
    apt-get install aptitude -y && \
    aptitude update -y && \
    aptitude install cmake python3 python3-pip build-essential -y && \
    pip install conan

WORKDIR Workdir

# Copy all sources into container
COPY . .

# Copy conan profiles
COPY ConanProfiles /root/.conan/profiles

WORKDIR BuildResult

RUN conan install -b=missing -pr=conan-"$BUILD_TYPE"-profile-linux32_64 .. && \
    cmake .. && \
    cmake --build . --target ApiServer --config "$BUILD_TYPE"

# TODO: Build Client and copy binaries to resulting image
# ...

# Create image which holds built artifacts
FROM ubuntu:22.10 as ResultImage

COPY --from=ApiServerBuild /Workdir/BuildResult/api-server-bin /api-server-bin

WORKDIR api-server-bin

# Add metadata to image
VOLUME /api-server-bin/configs
VOLUME /api-server-bin/storage
EXPOSE 7788

ENTRYPOINT ./ApiServer