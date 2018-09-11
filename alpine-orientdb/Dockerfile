FROM ormos/alpine-java-11

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "net.ormos.alpine-orientdb"="3.8"

ENV DEPLOYMENT_FOLDER="/var/orientdb" \
    ORIENTDB_HOME="/usr/local/orientdb" \
    ORIENTDB_PID="/var/run/orientdb.pid"

RUN ORIENTDB_VERSION="3.0.7" && \
    ORIENTDB_PACKAGE_VERSION="${ORIENTDB_VERSION}" && \
    ORIENTDB_PACKAGE_FILENAME="orientdb-community-${ORIENTDB_VERSION}.tar.gz" && \
    ORIENTDB_PACKAGE_FOLDER="orientdb" && \
    ORIENTDB_BASE_URL="http://repo1.maven.org/maven2/com/orientechnologies" && \
    ORIENTDB_PACKAGE_URL="${ORIENTDB_BASE_URL}/orientdb-community/${ORIENTDB_VERSION}/${ORIENTDB_PACKAGE_FILENAME}" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet  ca-certificates openssl zlib && \
    apk --no-cache add --quiet --virtual=.build-dependencies openssl-dev curl libarchive-tools && \
    \
    echo "Downloading and installing OrientDB package: $ORIENTDB_PACKAGE_FILENAME" >&2 && \
    mkdir -p "${ORIENTDB_HOME}" && \
    curl -jkSL -# "${ORIENTDB_PACKAGE_URL}" | bsdtar -xf- -C ${ORIENTDB_HOME} --strip-components=1 && \
    \
    mkdir -p "${DEPLOYMENT_FOLDER}" && \
    mv "${ORIENTDB_HOME}/config" "${DEPLOYMENT_FOLDER}" && \
    ln -s "${DEPLOYMENT_FOLDER}/config" "${ORIENTDB_HOME}" && \
    ( [ -d "${ORIENTDB_HOME}/databases" ] && mv "${ORIENTDB_HOME}/databases" "${DEPLOYMENT_FOLDER}" ) && \
    ( [ -d "${DEPLOYMENT_FOLDER}/databases" ] || mkdir -p "${DEPLOYMENT_FOLDER}/databases" ) && \
    ln -s "${DEPLOYMENT_FOLDER}/databases" "${ORIENTDB_HOME}" && \
    ( [ -d "${ORIENTDB_HOME}/log" ] && mv "${ORIENTDB_HOME}/log" "${DEPLOYMENT_FOLDER}" ) && \
    ( [ -d "${DEPLOYMENT_FOLDER}/log" ] || mkdir -p "${DEPLOYMENT_FOLDER}/log" ) && \
    ln -s "${DEPLOYMENT_FOLDER}"/log "${ORIENTDB_HOME}" && \
    rm -rf "${ORIENTDB_HOME}/benchmarks" && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/* && \
    \
    rm -rf "${DEPLOYMENT_FOLDER}"/databases/*

ENV PATH "${ORIENTDB_HOME}/bin:$PATH"

VOLUME ["${DEPLOYMENT_FOLDER}"]

EXPOSE 2424 2480

WORKDIR "${DEPLOYMENT_FOLDER}/"

CMD ["server.sh"]
