FROM elvido/alpine

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"
LABEL "net.elvido.alpine-java-oracle"="3.6"

# java home home environment
ENV JAVA_HOME=/usr/lib/jvm/default-jvm

RUN JAVA_VERSION_MAJOR=9 && \
    JAVA_VERSION_MINOR=181 && \
    JAVA_VERSION_BUILD=ea && \
    JAVA_PACKAGE_FOLDER=090f390dda5b47b9b721c7dfaa008135 && \
    JAVA_PACKAGE=jdk && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet --virtual=.build-dependencies curl libarchive-tools && \
    \
    JAVA_DIR=$(dirname "${JAVA_HOME}") && \
    mkdir -p "${JAVA_DIR}" && \
    JAVA_PACKAGE_FILENAME="${JAVA_PACKAGE}-${JAVA_VERSION_MAJOR}-${JAVA_VERSION_BUILD}+${JAVA_VERSION_MINOR}_linux-x64-musl_bin.tar.gz" && \
    echo "Downloading Java package archive: $JAVA_PACKAGE_FILENAME" >&2 && \
    echo "Downloading: http://download.java.net/java/jdk${JAVA_VERSION_MAJOR}-alpine/archive/${JAVA_VERSION_MINOR}/binaries/${JAVA_PACKAGE_FILENAME}" >&2 && \
    curl -jkSL -# -H "Cookie: oraclelicense=a" \
      http://download.java.net/java/jdk${JAVA_VERSION_MAJOR}-alpine/archive/${JAVA_VERSION_MINOR}/binaries/${JAVA_PACKAGE_FILENAME} | \
      bsdtar -xf- -C "${JAVA_DIR}"  && \
    ln -s "${JAVA_DIR}/jdk-${JAVA_VERSION_MAJOR}" "${JAVA_HOME}" && \
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
