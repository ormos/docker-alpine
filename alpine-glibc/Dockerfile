FROM elvido/alpine

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"
LABEL "net.elvido.alpine-glibc"="3.7"

# Install GNU libc (aka glibc) and set C.UTF-8 locale as default.

ENV LANG=C.UTF-8

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    rm -rf /tmp/* /var/cache/apk/*

ADD glibc-releases/alpine-glibc-2.27-x86_64.tgz /
    
RUN /usr/glibc-compat/sbin/ldconfig && \
    echo "export LANG=$LANG" > /etc/profile.d/locale.sh
