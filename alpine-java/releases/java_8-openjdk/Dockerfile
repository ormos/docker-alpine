FROM elvido/alpine

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"
LABEL "net.elvido.alpine-java-openjdk"="3.6"

# java home home environment
ENV JAVA_HOME=/usr/lib/jvm/default-jvm

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates openjdk8 && \
    \
    # remove stuff we do not need
    rm -rf ${JAVA_HOME}/jre/bin/jjs \
        ${JAVA_HOME}/jre/bin/keytool \
        ${JAVA_HOME}/jre/bin/orbd \
        ${JAVA_HOME}/jre/bin/pack200 \
        ${JAVA_HOME}/jre/bin/policytool \
        ${JAVA_HOME}/jre/bin/rmid \
        ${JAVA_HOME}/jre/bin/rmiregistry \
        ${JAVA_HOME}/jre/bin/servertool \
        ${JAVA_HOME}/jre/bin/tnameserv \
        ${JAVA_HOME}/jre/bin/unpack200 && \
    \
    echo "Cleaning up..." >&2 && \
    rm -rf /tmp/* /var/cache/apk/*
