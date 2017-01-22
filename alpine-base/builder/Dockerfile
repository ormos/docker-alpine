FROM alpine:3.5

MAINTAINER elvido <ralf.hofmann@elvido.net>

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates bash tzdata

COPY scripts/mkimage-alpine scripts/apk-install /

ENTRYPOINT ["/mkimage-alpine"]
CMD ["-h"]