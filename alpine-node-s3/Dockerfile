FROM elvido/alpine-node

MAINTAINER elvido <ralf.hofmann@elvido.net>

LABEL "net.elvido.alpine-node-s3"="3.5"

# installation folder
ENV  NODE_S3_FOLDER=/usr/src/app

COPY S3 /usr/src/app

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet --virtual=.build-dependencies binutils-gold curl g++ gcc libgcc linux-headers make python git libarchive-tools && \
    \
    echo "Deplyoing node S3 service" >&2 && \
    cd "${NODE_S3_FOLDER}" ; npm install --production && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf ~/.node-gyp /tmp/* /var/cache/apk/*

VOLUME ["${NODE_S3_FOLDER}/localData", "${NODE_S3_FOLDER}/localMetadata"]

EXPOSE 8000

WORKDIR ${NODE_S3_FOLDER}/

ENTRYPOINT ["./docker-entrypoint.sh"]

CMD [ "npm", "start" ]

