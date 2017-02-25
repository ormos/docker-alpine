FROM elvido/alpine-node

MAINTAINER elvido <ralf.hofmann@elvido.net>

LABEL "net.elvido.alpine-node-openui5"="3.5"

ENV  DEPLOYMENT_FOLDER="/var/webapp" \
     NODE_ENV="production"

COPY rootfs /

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates libstdc++ && \
    apk --no-cache add --quiet --virtual=.build-dependencies binutils-gold curl g++ gcc libgcc linux-headers make libarchive-tools && \
    \
    echo "Deploying web app" >&2 && \
    chown -R node:node "${DEPLOYMENT_FOLDER}" && cd "${DEPLOYMENT_FOLDER}" && su node -c "npm install" && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

VOLUME ["${DEPLOYMENT_FOLDER}"]

EXPOSE 80 443

WORKDIR ${DEPLOYMENT_FOLDER}/ 

CMD [ "node", "index.js" ]    
