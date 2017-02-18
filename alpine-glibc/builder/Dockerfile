FROM elvido/alpine:edge

MAINTAINER elvido <ralf.hofmann@elvido.net>

ENV PREFIX_DIR /usr/glibc-compat \
    GLIBC_VERSION 2.23

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates bash shadow coreutils findutils grep gawk perl curl openssl && \
    apk --no-cache add --quiet build-base linux-headers gettext-dev zlib-dev binutils gcc make texinfo libarchive-tools

COPY scripts/configparams /glibc-build/configparams
COPY scripts/glibc-builder /glibc-builder

# ENTRYPOINT ["/glibc-builder"]
# CMD ["-h"]
