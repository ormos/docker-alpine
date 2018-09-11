FROM ormos/alpine

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "net.ormos.alpine-glibc"="3.8"

# Install GNU libc (aka glibc) and set C.UTF-8 locale as default.

ENV LANG=C.UTF-8

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet --virtual=.build-dependencies curl libarchive-tools binutils
    
ADD glibc-releases/alpine-glibc-2.28-x86_64.tgz /

RUN echo "Installing addtional runtime libs..." >&2 && \
    curl -jkSL -# \
    https://www.archlinux.org/packages/core/x86_64/gcc-libs/download | \
    bsdtar -xf- --strip-components 2 -C "/usr/glibc-compat/lib" 'usr/lib/libgcc*' 'usr/lib/libstdc++*' && \
    strip /usr/glibc-compat/lib/libgcc_s.so.* /usr/glibc-compat/lib/libstdc++.so* && \
    curl -jkSL -# \
    https://www.archlinux.org/packages/core/x86_64/zlib/download | \
    bsdtar -xf- --strip-components 2 -C "/usr/glibc-compat/lib" 'usr/lib/libz.so*' && \
    \
    /usr/glibc-compat/sbin/ldconfig && \
    echo "export LANG=$LANG" > /etc/profile.d/locale.sh && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*
