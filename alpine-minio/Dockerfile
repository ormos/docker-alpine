FROM elvido/alpine:edge

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"
LABEL "net.elvido.alpine-minio"="3.7"

ENV GOPATH /go
ENV PATH $PATH:$GOPATH/bin
ENV CGO_ENABLED 0

RUN MINIO_PKG="github.com/minio/minio" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet  ca-certificates openssl && \
    apk --no-cache add --quiet --virtual=.build-dependencies git go musl-dev && \
    echo 'hosts: files mdns4_minimal [NOTFOUND=return] dns mdns4' >> /etc/nsswitch.conf && \
    \
    echo "Downloading and installing Minio package" >&2 && \
    go get -v -d "${MINIO_PKG}" && \
    cd "${GOPATH}/src/${MINIO_PKG}" && \
    go install -v -ldflags "$(go run buildscripts/gen-ldflags.go)" && \
    cp dockerscripts/docker-entrypoint.sh /usr/bin/ && \
    chmod +x /usr/bin/docker-entrypoint.sh && \
    \
    echo "Cleaning up..." >&2 && \
    rm -rf "${GOPATH}/pkg" "${GOPATH}/src" /usr/local/go && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

VOLUME ["/var/storage"]

EXPOSE 9000

ENTRYPOINT ["/usr/bin/docker-entrypoint.sh"]
CMD ["-h"]
