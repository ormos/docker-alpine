FROM elvido/alpine

MAINTAINER elvido <ralf.hofmann@elvido.net>

# Install GNU libc (aka glibc) and set C.UTF-8 locale as default.

ENV LANG=C.UTF-8

RUN ALPINE_GLIBC_BASE_URL="https://github.com/sgerrand/alpine-pkg-glibc/releases/download" && \
    ALPINE_GLIBC_PACKAGE_VERSION="2.23-r3" && \
    ALPINE_GLIBC_BASE_PACKAGE_FILENAME="glibc-$ALPINE_GLIBC_PACKAGE_VERSION.apk" && \
    ALPINE_GLIBC_BIN_PACKAGE_FILENAME="glibc-bin-$ALPINE_GLIBC_PACKAGE_VERSION.apk" && \
    ALPINE_GLIBC_I18N_PACKAGE_FILENAME="glibc-i18n-$ALPINE_GLIBC_PACKAGE_VERSION.apk" && \
    ALPINE_GLIBC_PACKAGE_KEY="sgerrand.rsa.pub" && \
    apk upgrade --update && \
    apk add --no-cache ca-certificates && \
    apk add --no-cache --virtual=.build-dependencies curl && \
    echo "Downloading GLIBC package key: $ALPINE_GLIBC_PACKAGE_KEY" >&2 && \
    curl -jkSL -o "/etc/apk/keys/$ALPINE_GLIBC_PACKAGE_KEY" \
        "$ALPINE_GLIBC_BASE_URL/$ALPINE_GLIBC_PACKAGE_VERSION/$ALPINE_GLIBC_PACKAGE_KEY" && \
    echo "Downloading GLIBC base package: $ALPINE_GLIBC_BASE_PACKAGE_FILENAME" >&2 && \
    curl -jkSL -o "$ALPINE_GLIBC_BASE_PACKAGE_FILENAME" \
        "$ALPINE_GLIBC_BASE_URL/$ALPINE_GLIBC_PACKAGE_VERSION/$ALPINE_GLIBC_BASE_PACKAGE_FILENAME" && \
    echo "Downloading GLIBC bin package: $ALPINE_GLIBC_BIN_PACKAGE_FILENAME" >&2 && \
    curl -jkSL -o "$ALPINE_GLIBC_BIN_PACKAGE_FILENAME" \
        "$ALPINE_GLIBC_BASE_URL/$ALPINE_GLIBC_PACKAGE_VERSION/$ALPINE_GLIBC_BIN_PACKAGE_FILENAME" && \
    echo "Downloading GLIBC i18n package: $ALPINE_GLIBC_I18N_PACKAGE_FILENAME" >&2 && \
    curl -jkSL -o "$ALPINE_GLIBC_I18N_PACKAGE_FILENAME" \
        "$ALPINE_GLIBC_BASE_URL/$ALPINE_GLIBC_PACKAGE_VERSION/$ALPINE_GLIBC_I18N_PACKAGE_FILENAME" && \
    apk add --no-cache \
        "$ALPINE_GLIBC_BASE_PACKAGE_FILENAME" \
        "$ALPINE_GLIBC_BIN_PACKAGE_FILENAME" \
        "$ALPINE_GLIBC_I18N_PACKAGE_FILENAME" && \
    \
    /usr/glibc-compat/bin/localedef --force --inputfile POSIX --charmap UTF-8 C.UTF-8 || true && \
    echo "export LANG=$LANG" > /etc/profile.d/locale.sh && \
    \
    apk del glibc-i18n && \
    rm \
        "$ALPINE_GLIBC_BASE_PACKAGE_FILENAME" \
        "$ALPINE_GLIBC_BIN_PACKAGE_FILENAME" \
        "$ALPINE_GLIBC_I18N_PACKAGE_FILENAME" \
        "/etc/apk/keys/$ALPINE_GLIBC_PACKAGE_KEY" && \
    \
    apk del .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*
