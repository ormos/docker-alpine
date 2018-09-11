FROM ormos/alpine-node

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "ormos.alpine-node-openui5"="3.8"

ENV  DEPLOYMENT_FOLDER="/var/webapp" \
     NODE_ENV="production"

COPY rootfs /

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet --virtual=.build-dependencies curl libarchive-tools && \
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
