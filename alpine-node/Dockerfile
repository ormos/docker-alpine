FROM elvido/alpine

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"
LABEL "net.elvido.alpine-node"="3.6"

# Node Version
ENV  NODE_VERSION="8.5.0" \
     NPM_VERSION="5" \
     NPM_CONFIG_LOGLEVEL="info"

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates libstdc++ && \
    apk --no-cache add --quiet --virtual=.build-dependencies binutils-gold curl g++ gcc libgcc linux-headers make python paxctl libarchive-tools && \
    \
    adduser -D -u 1000 node && \
    \
    echo "Downloading NodeJS package archive" >&2 && \
    curl -jkSL -# \
      https://nodejs.org/dist/v${NODE_VERSION}/node-v${NODE_VERSION}.tar.gz | \
      bsdtar -xf- -C '/tmp'  && \
    \
    echo "Building and installing NodeJS package" >&2 && \
    cd /tmp/node-v${NODE_VERSION} && \
    ./configure --prefix=/usr && \
    make -j$(getconf _NPROCESSORS_ONLN) && \
    make install && \
    paxctl -cm /usr/bin/node && \
    \
    cd /tmp ; rm -rf /tmp/node-v${NODE_VERSION} && \
    \
    if [ -x /usr/bin/npm ]; then \
      echo "Installing npm" >&2 && \
      npm install -g npm@${NPM_VERSION} && \
      find /usr/lib/node_modules/npm -name test -o -name .bin -type d | xargs rm -rf; \
    fi && \
    \
    rm -rf /root/.npm /root/.node-gyp /usr/lib/node_modules/npm/man /usr/lib/node_modules/npm/doc /usr/lib/node_modules/npm/html && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

CMD [ "node" ]    
