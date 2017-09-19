FROM alpine:3.6

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"

ENV DATA_FOLDER="/mnt/data"

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates tzdata && \
    \
    mkdir -p "${DATA_FOLDER}"

COPY rootfs /

ENTRYPOINT ["/usr/sbin/mkimage-alpine"]
CMD ["-h"]
