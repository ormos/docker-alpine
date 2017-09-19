FROM multiarch/ubuntu-debootstrap:amd64-slim

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"

ENV GLIBC_VERSION='2.26' \
    GLIBC_ARCH='x86_64'\
    GLIBC_PREFIX='/usr/glibc-compat' \
    DATA_FOLDER='/mnt/data'

RUN apt-get -q update && \
	apt-get -qy install build-essential curl openssl gawk file && \
    apt-get -qy autoclean ; apt-get -qy clean && \
    \
    mkdir -p "${DATA_FOLDER}"

COPY rootfs /

VOLUME ["${DATA_FOLDER}"]

ENTRYPOINT ["/usr/sbin/glibc-builder"]
CMD ["-h"]
