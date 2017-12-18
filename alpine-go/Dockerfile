FROM elvido/alpine

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"
LABEL "net.elvido.alpine-go"="3.7"

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet build-base go git openssl curl && \
    \
    echo "Cleaning up..." >&2 && \
    rm -rf /tmp/* /var/cache/apk/*
  
