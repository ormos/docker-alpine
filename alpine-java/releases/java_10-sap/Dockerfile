FROM ormos/alpine-glibc

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "ormos.alpine-java-sap"="3.8"
LABEL "ormos.alpine-java-10-sap"="3.8"

# java home home environment
ENV JAVA_HOME=/usr/lib/jvm/default-jvm

RUN JAVA_VERSION_MAJOR=10 && \
    JAVA_VERSION_MINOR=0.2 && \
    JAVA_VERSION_RELEASE=13 && \
    JAVA_PACKAGE_FOLDER=sapmachine-${JAVA_VERSION_MAJOR}.${JAVA_VERSION_MINOR}%2B${JAVA_VERSION_RELEASE}-1 && \
    JAVA_PACKAGE=sapmachine-jdk && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet --virtual=.build-dependencies curl libarchive-tools && \
    \
    JAVA_DIR=$(dirname "${JAVA_HOME}") && \
    mkdir -p "${JAVA_DIR}" && \
    JAVA_PACKAGE_FILENAME="${JAVA_PACKAGE}-${JAVA_VERSION_MAJOR}.${JAVA_VERSION_MINOR}.${JAVA_VERSION_RELEASE}_linux-x64_bin.tar.gz" && \
    echo "Downloading Java package archive: $JAVA_PACKAGE_FILENAME" >&2 && \
    echo "Downloading: https://github.com/SAP/SapMachine/releases/download/${JAVA_PACKAGE_FOLDER}/${JAVA_PACKAGE_FILENAME}" >&2 && \
    curl -jkSL -# \
      https://github.com/SAP/SapMachine/releases/download/${JAVA_PACKAGE_FOLDER}/${JAVA_PACKAGE_FILENAME} | \
      bsdtar -xf- -C "${JAVA_DIR}"  && \
    ln -s "${JAVA_DIR}/${JAVA_PACKAGE}-${JAVA_VERSION_MAJOR}.${JAVA_VERSION_MINOR}" "${JAVA_HOME}" && \
    \
    # remove stuff we do not need
    rm -rf ${JAVA_HOME}/lib/*src.zip \
           ${JAVA_HOME}/lib/missioncontrol \
           ${JAVA_HOME}/lib/*javafx* \
    \
    # adjust some settings
    echo 'hosts: files mdns4_minimal [NOTFOUND=return] dns mdns4' >> /etc/nsswitch.conf && \
    sed -i s/#networkaddress.cache.ttl=-1/networkaddress.cache.ttl=30/ "${JAVA_HOME}/conf/security/java.security" && \
    ln -s "${JAVA_HOME}/bin/"* "/usr/bin/" || : && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*
