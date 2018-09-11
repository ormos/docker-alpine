FROM ormos/alpine-go as builder

RUN MINIO_PKG="github.com/minio/minio" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet --virtual=.build-dependencies && \
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

FROM ormos/alpine

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "ormos.alpine-minio"="3.8"

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates openssl

COPY --from=builder /go/bin/* /usr/bin/
COPY --from=builder /usr/bin/docker-entrypoint.sh /usr/bin/

VOLUME ["/var/storage"]

EXPOSE 9000

ENTRYPOINT ["/usr/bin/docker-entrypoint.sh"]
CMD ["-h"]
