FROM elvido/alpine-node

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"
LABEL "net.elvido.alpine-node-s3"="3.7"

# installation folder
ENV  NODE_S3_FOLDER=/usr/src/app

RUN NODE_S3_REPO="https://github.com/scality/S3.git" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet --virtual=.build-dependencies binutils-gold curl g++ gcc libgcc linux-headers make python git libarchive-tools && \
    \
    echo "Cloning S3 app repo" >&2 && \
    git clone "${NODE_S3_REPO}" "${NODE_S3_FOLDER}" && \
    \
    echo "Deplyoing node S3 service" >&2 && \
    cd "${NODE_S3_FOLDER}" ; npm install --production && \
    \
    echo "Modify startup scripts..." && \
    mv "${NODE_S3_FOLDER}/docker-entrypoint.sh" "${NODE_S3_FOLDER}/docker-entrypoint.bash" && \
    echo -e '#!/bin/sh\n# set -e stops the execution of a script if a command or pipeline has an error\nset -e\n' >>"${NODE_S3_FOLDER}/docker-entrypoint.sh" && \
    echo -e 'if [[ "$ACCESS_KEY" && "$SECRET_KEY" ]]; then\n  sed -i "s/accessKeyDocker/$ACCESS_KEY/" ./conf/authdata.json\n  sed -i "s/verySecretKeyDocker/$SECRET_KEY/" ./conf/authdata.json\n  echo "Access key and secret key have been modified successfully"\nfi\n' >>"${NODE_S3_FOLDER}/docker-entrypoint.sh" && \
    echo -e 'exec "$@"\n' >>"${NODE_S3_FOLDER}/docker-entrypoint.sh" && \
    chmod +x "${NODE_S3_FOLDER}/docker-entrypoint.sh" && \
    \    
    echo "Cleaning up..." >&2 && \
    rm -rf "${NODE_S3_FOLDER}/tests" && \
    rm -rf "${NODE_S3_FOLDER}/docs" && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf ~/.node-gyp /tmp/* /var/cache/apk/*

VOLUME ["${NODE_S3_FOLDER}/localData", "${NODE_S3_FOLDER}/localMetadata"]

EXPOSE 8000

WORKDIR ${NODE_S3_FOLDER}/

ENTRYPOINT ["./docker-entrypoint.sh"]

CMD [ "npm", "start" ]

