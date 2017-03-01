FROM elvido/alpine-glibc

MAINTAINER elvido <ralf.hofmann@elvido.net>

LABEL "net.elvido.alpine-java-sap"="3.5"

# Java home
ENV JAVA_HOME=/usr/lib/jvm/default-jvm

RUN JAVA_VERSION_MAJOR=8 && \
    JAVA_VERSION_MINOR=1 && \
    JAVA_VERSION_BUILD=021 && \
    JAVA_PACKAGE=sapjvm && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet --virtual=.build-dependencies curl libarchive-tools && \
    \
    JAVA_DIR=$(dirname "${JAVA_HOME}") && \
    mkdir -p "${JAVA_DIR}" && \
    JAVA_PACKAGE_FILENAME="${JAVA_PACKAGE}-${JAVA_VERSION_MAJOR}.${JAVA_VERSION_MINOR}.${JAVA_VERSION_BUILD}-linux-x64.zip" && \
    echo "Downloading Java package archive: $JAVA_PACKAGE_FILENAME" >&2 && \
    curl -jkSL -# -H "Cookie: eula_3_1_agreed=tools.hana.ondemand.com/developer-license-3_1.txt" \
      https://tools.hana.ondemand.com/additional/${JAVA_PACKAGE_FILENAME} | \
      bsdtar -xf- -C "${JAVA_DIR}"  && \
    ln -s "${JAVA_DIR}/${JAVA_PACKAGE}_${JAVA_VERSION_MAJOR}" "${JAVA_HOME}" && \
    \
    # remove stuff we do not need
    rm -rf ${JAVA_HOME}/*src.zip \
           ${JAVA_HOME}/lib/missioncontrol \
           ${JAVA_HOME}/lib/visualvm \
           ${JAVA_HOME}/lib/*javafx* \
           ${JAVA_HOME}/jre/plugin \
           ${JAVA_HOME}/jre/bin/javaws \
           ${JAVA_HOME}/jre/bin/jjs \
           ${JAVA_HOME}/jre/bin/keytool \
           ${JAVA_HOME}/jre/bin/orbd \
           ${JAVA_HOME}/jre/bin/pack200 \
           ${JAVA_HOME}/jre/bin/policytool \
           ${JAVA_HOME}/jre/bin/rmid \
           ${JAVA_HOME}/jre/bin/rmiregistry \
           ${JAVA_HOME}/jre/bin/servertool \
           ${JAVA_HOME}/jre/bin/tnameserv \
           ${JAVA_HOME}/jre/bin/unpack200 \
           ${JAVA_HOME}/jre/lib/javaws.jar \
           ${JAVA_HOME}/jre/lib/deploy* \
           ${JAVA_HOME}/jre/lib/desktop \
           ${JAVA_HOME}/jre/lib/*javafx* \
           ${JAVA_HOME}/jre/lib/*jfx* \
           ${JAVA_HOME}/jre/lib/amd64/libdecora_sse.so \
           ${JAVA_HOME}/jre/lib/amd64/libprism_*.so \
           ${JAVA_HOME}/jre/lib/amd64/libfxplugins.so \
           ${JAVA_HOME}/jre/lib/amd64/libglass.so \
           ${JAVA_HOME}/jre/lib/amd64/libgstreamer-lite.so \
           ${JAVA_HOME}/jre/lib/amd64/libjavafx*.so \
           ${JAVA_HOME}/jre/lib/amd64/libjfx*.so \
           ${JAVA_HOME}/jre/lib/ext/jfxrt.jar \
           ${JAVA_HOME}/jre/lib/oblique-fonts \
           ${JAVA_HOME}/jre/lib/plugin.jar && \
    \
    # adjust some settings
    chmod +x "${JAVA_HOME}/bin/"* && \
    chmod +x "${JAVA_HOME}/jre/bin/"* && \
    ln -s "${JAVA_HOME}/bin/"* "/usr/bin/" || : && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

    # for now a dirty hack - need fix
    COPY libstdc++.so.6 libgcc_s.so.1 /usr/glibc-compat/lib/ 
