FROM ormos/alpine as builder

# Node Version
ENV  NODE_VERSION="11.10.0" \
     NPM_VERSION="6" \
     NPM_CONFIG_LOGLEVEL="info"

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates libstdc++ && \
    apk --no-cache add --quiet --virtual=.build-dependencies binutils-gold curl g++ gcc libgcc linux-headers make python paxctl libarchive-tools git openssh && \
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

FROM ormos/alpine

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "ormos.alpine-node"="3.9"

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates libstdc++
 
COPY --from=builder /usr/bin/node /usr/bin/
COPY --from=builder /usr/lib/node_modules /usr/lib/node_modules/

RUN ln -s /usr/lib/node_modules/npm/bin/npm-cli.js /usr/bin/npm && \
    ln -s /usr/lib/node_modules/npm/bin/npx-cli.js /usr/bin/npx && \
    \
    adduser -D -u 1000 node

CMD [ "node" ]    
