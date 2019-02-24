FROM ormos/alpine

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "ormos.alpine-dops"="3.9"

ENV WORK_FOLDER="/dops"

RUN INSTALLATION_BASE="/usr/local" && \
    \
    DOCKER_MACHINE_VERSION="0.16.1" && \
    DOCKER_MACHINE_PACKAGE_FILENAME="docker-machine-$(uname -s)-$(uname -m)" && \
    DOCKER_MACHINE_PROGRAM_FILENAME="docker-machine" && \
    DOCKER_MACHINE_BASE_URL="https://github.com/docker/machine/releases/download/v${DOCKER_MACHINE_VERSION}" && \
    DOCKER_MACHINE_PACKAGE_URL="${DOCKER_MACHINE_BASE_URL}/${DOCKER_MACHINE_PACKAGE_FILENAME}" && \
    \
    ZSH_PREZTO_PACKAGE_URL="https://github.com/sorin-ionescu/prezto.git" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet zsh bash vim git make curl jq openssh-client python docker ansible docker-py py2-pip && \
    apk --no-cache add --quiet --virtual=.build-dependencies build-base libarchive-tools zlib-dev python-dev libffi-dev && \
    \
    echo "Downloading and installing docker machine" >&2 && \
    curl -kSL -# --output ${INSTALLATION_BASE}/bin/${DOCKER_MACHINE_PROGRAM_FILENAME} "${DOCKER_MACHINE_PACKAGE_URL}" && \
    chmod +x ${INSTALLATION_BASE}/bin/${DOCKER_MACHINE_PROGRAM_FILENAME} && \
    \
    pip install --upgrade pip && \
    \
    echo "Downloading and installing docker compose" >&2 && \
    pip install docker-compose && \
    \
    echo "Downloading and installing AWS cli" >&2 && \
    pip install awscli && \
    \
    sed -i "s|root:x:0:0:root:/root:/bin/ash|root:x:0:0:root:/root:/bin/zsh|" /etc/passwd && \
    \
    echo "Downloading and installing ZSH prezto" >&2 && \
    git clone --recursive "${ZSH_PREZTO_PACKAGE_URL}" "${HOME}/.zprezto" && \
    echo 'setopt EXTENDED_GLOB ; for rcfile in "${HOME}"/.zprezto/runcoms/^README.md(.N) ; do ln -s "${rcfile}" "${HOME}"/.${rcfile:t} ; done' | zsh -s && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

ADD rootfs /

VOLUME ["${WORK_FOLDER}"]

WORKDIR ${WORK_FOLDER}/

ENTRYPOINT ["dops"]
CMD ["shell"]
