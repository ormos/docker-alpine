FROM ormos/alpine-go as builder

RUN HTTPBIN_PKG="github.com/mccutchen/go-httpbin" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet --virtual=.build-dependencies && \
    \
    echo "Downloading and installing go-bindata package" >&2 && \
    go get -v github.com/kevinburke/go-bindata/... && \
    \
    echo "Downloading and installing httpbin package" >&2 && \
    git clone "https://${HTTPBIN_PKG}" "${GOPATH}/src/${HTTPBIN_PKG}" && \
    cd "${GOPATH}/src/${HTTPBIN_PKG}" && \
    go-bindata -o httpbin/assets/assets.go -pkg=assets -prefix=static static && \
    go install -v --ldflags='-s -w -linkmode external -extldflags "-static"' ./cmd/go-httpbin && \
    \
    echo "Cleaning up..." >&2 && \
    rm -rf "${GOPATH}/pkg" "${GOPATH}/src" /usr/local/go && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

FROM ormos/alpine

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "ormos.alpine-httpbin"="3.9"

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates openssl

COPY --from=builder /go/bin/go-httpbin /usr/bin/

EXPOSE 8080

ENTRYPOINT ["go-httpbin"]
CMD ["-port", "8080"]
