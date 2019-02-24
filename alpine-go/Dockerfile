FROM ormos/alpine

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "ormos.alpine-go"="3.9"

ENV GOPATH /go
ENV PATH $PATH:$GOPATH/bin

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet build-base go gcc g++ git musl-dev libc6-compat openssl curl && \
    \
    echo "Cleaning up..." >&2 && \
    rm -rf /tmp/* /var/cache/apk/*
  
