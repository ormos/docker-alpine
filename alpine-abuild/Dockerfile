FROM elvido/alpine

MAINTAINER elvido <ralf.hofmann@elvido.net>

LABEL "net.elvido.alpine-abuild"="3.5"

ENV BUILDER_HOME=/home/builder
ENV PACKAGER_PRIVATE_KEY_NAME=packager.key
ENV PACKAGER_PRIVKEY=/home/builder/.abuild/${PACKAGER_PRIVATE_KEY_NAME}
ENV REPODEST=/packages

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates alpine-sdk coreutils && \
    \
    adduser -G abuild -g "Alpine Package Builder" -s /bin/ash -D builder && \
    echo "builder ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    \
    mkdir ${BUILDER_HOME}/.abuild && \
    chown builder:abuild ${BUILDER_HOME}/.abuild && \
    \
    mkdir ${BUILDER_HOME}/package && \
    chown builder:abuild ${BUILDER_HOME}/package && \
    \ 
    mkdir -p ${REPODEST}/builder && \
    chown builder:abuild ${REPODEST}/builder

COPY scripts/abuilder /bin/

WORKDIR ${BUILDER_HOME}/package

USER builder

ENTRYPOINT ["abuilder", "-r"]
CMD ["-help"]
