FROM elvido/alpine:edge

MAINTAINER elvido <ralf.hofmann@elvido.net>

ENV PREFIX_DIR /usr/glibc-compat \
    GLIBC_VERSION 2.23

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates bash shadow coreutils findutils grep gawk perl wget openssl zlib && \
    apk --no-cache add --quiet build-base linux-headers binutils gcc make gettext texinfo libarchive-tools zlib

COPY scripts/configparams /glibc-build/configparams
COPY scripts/glibc-builder /glibc-builder

# ENTRYPOINT ["/glibc-builder"]
# CMD ["-h"]
