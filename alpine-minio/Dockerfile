FROM elvido/alpine:edge

MAINTAINER elvido <ralf.hofmann@elvido.net>

LABEL "net.elvido.alpine-minio"="3.6"

ENV GOPATH /go
RUN mkdir -p "$GOPATH/src" "$GOPATH/bin" && chmod -R 777 "$GOPATH"
ENV PATH $GOPATH/bin:$PATH

COPY go-wrapper /

RUN MINIO_MODULE="minio" && \
    MINIO_VERSION="master" && \
    MINIO_FOLDER="${MINIO_MODULE}-${MINIO_VERSION}" && \
    MINIO_BASE_URL="https://github.com/minio/" && \
    MINIO_PACKAGE_URL="${MINIO_BASE_URL}/${MINIO_MODULE}/archive/${MINIO_VERSION}.zip" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet  ca-certificates openssl zlib go && \
    apk --no-cache add --quiet --virtual=.build-dependencies openssl-dev curl libarchive-tools build-base git go-tools && \
    \
    echo "Downloading and installing Minio package" >&2 && \
    mkdir -p "$GOPATH/src/app" && \
    curl -jkSL -# "${MINIO_PACKAGE_URL}" | bsdtar -xf- -C "$GOPATH/src/app" --strip-components=1 && \
    \
    cd "$GOPATH/src/app" && \
    chmod +x /go-wrapper && \
    /go-wrapper download && \
	/go-wrapper install -ldflags "$(go run buildscripts/gen-ldflags.go)" && \
	mkdir -p /export/docker && \
	rm -rf "$GOPATH/pkg" "$GOPATH/src" && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

VOLUME ["/export"]

EXPOSE 9000

WORKDIR $GOPATH

ENTRYPOINT ["minio"]
CMD ["-h"]

