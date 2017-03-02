FROM golang:1.8-alpine

MAINTAINER elvido <ralf.hofmann@elvido.net>

LABEL "net.elvido.alpine-minio"="3.5"

ENV DEPLOYMENT_FOLDER="/var/orientdb" \
    ORIENTDB_HOME="/usr/local/orientdb" \
    ORIENTDB_PID="/var/run/orientdb.pid"

RUN MINIO_MODULE="minio" && \
    MINIO_VERSION="master" && \
    MINIO_FOLDER="${MINIO_MODULE}-${MINIO_VERSION}" && \
    MINIO_BASE_URL="https://github.com/minio/" && \
    MINIO_PACKAGE_URL="${MINIO_BASE_URL}/${MINIO_MODULE}/archive/${MINIO_VERSION}.zip" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet  ca-certificates openssl zlib go go-tools && \
    apk --no-cache add --quiet --virtual=.build-dependencies openssl-dev curl libarchive-tools git && \
    \
    echo "Downloading and installing Minio package" >&2 && \
    mkdir -p "/go/src/app" && \
    curl -jkSL -# "${MINIO_PACKAGE_URL}" | bsdtar -xf- -C "/go/src/app" --strip-components=1 && \
    \
    cd "/go/src/app" && \
    go-wrapper download && \
	go-wrapper install -ldflags "$(go run buildscripts/gen-ldflags.go)" && \
	mkdir -p /export/docker && \
	#rm -rf /go/pkg /go/src && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/* && \
    \
    rm -rf "${DEPLOYMENT_FOLDER}"/databases/*

#ENV PATH "${ORIENTDB_HOME}"/bin:$PATH

VOLUME ["/export"]
#VOLUME ["${DEPLOYMENT_FOLDER}"]

EXPOSE 9000

#WORKDIR "${DEPLOYMENT_FOLDER}/"

#ENTRYPOINT ["minio"]
#CMD ["-h"]

