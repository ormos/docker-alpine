FROM elvido/alpine

MAINTAINER elvido <ralf.hofmann@elvido.net>

LABEL "net.elvido.alpine-abuild"="3.4"

ENV RSA_PRIVATE_KEY_NAME=ssh.rsa
ENV PACKAGER_PRIVKEY=/home/builder/${RSA_PRIVATE_KEY_NAME}
ENV REPODEST=/packages

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates alpine-sdk coreutils && \
    \
    adduser -G abuild -g "Alpine Package Builder" -s /bin/ash -D builder && \
    echo "builder ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    \
    mkdir /packages && \
    chown builder:abuild /packages

COPY scripts/abuilder /bin/

WORKDIR /home/builder/package

USER builder

ENTRYPOINT ["abuilder", "-r"]
CMD ["-help"]
