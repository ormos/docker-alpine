FROM ormos/alpine-glibc

LABEL maintainer="ormos <r.hofmann@sap.com>"
LABEL "ormos.alpine-java-openjdk"="3.9"
LABEL "ormos.alpine-java-11-openjdk"="3.9"

# java home home environment
ENV JAVA_HOME=/usr/lib/jvm/default-jvm

RUN JAVA_VERSION_MAJOR=11 && \
    JAVA_VERSION_MINOR=0.2 && \
    JAVA_VERSION_RELEASE=. && \
    JAVA_PACKAGE=openjdk && \
    JAVA_PACKAGE_FOLDER=java/GA/jdk11/9/GPL && \
    JAVA_PACKAGE_URL=https://download.java.net && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet --virtual=.build-dependencies curl libarchive-tools && \
    \
    JAVA_DIR=$(dirname "${JAVA_HOME}") && \
    mkdir -p "${JAVA_DIR}" && \
    JAVA_PACKAGE_FILENAME="${JAVA_PACKAGE}-${JAVA_VERSION_MAJOR}${JAVA_VERSION_RELEASE}${JAVA_VERSION_MINOR}_linux-x64_bin.tar.gz" && \
    echo "Downloading Java package archive: $JAVA_PACKAGE_FILENAME" >&2 && \
    echo "Downloading: ${JAVA_PACKAGE_URL}/${JAVA_PACKAGE_FOLDER}/${JAVA_PACKAGE_FILENAME}" >&2 && \
    curl -jkSL -# -H "Cookie: oraclelicense=a" \
      ${JAVA_PACKAGE_URL}/${JAVA_PACKAGE_FOLDER}/${JAVA_PACKAGE_FILENAME} | \
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
