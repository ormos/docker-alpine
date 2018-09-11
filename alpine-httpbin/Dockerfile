FROM ormos/alpine-go as builder

RUN HTTPBIN_PKG="github.com/mccutchen/go-httpbin" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet --virtual=.build-dependencies && \
    \
    echo "Downloading and installing httpbin package" >&2 && \
    go get -v -d "${HTTPBIN_PKG}" && \
    cd "${GOPATH}/src/${HTTPBIN_PKG}" && \
    go install -v -ldflags "$(go run buildscripts/gen-ldflags.go)" && \
    \
    echo "Cleaning up..." >&2 && \
    rm -rf "${GOPATH}/pkg" "${GOPATH}/src" /usr/local/go && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

FROM ormos/alpine

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "net.ormos.alpine-httpbin"="3.8"

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates openssl

COPY --from=builder /go/bin/* /usr/bin/

EXPOSE 8080

ENTRYPOINT ["go-httpbin"]
CMD ["-h"]
