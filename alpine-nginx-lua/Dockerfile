FROM elvido/alpine-glibc

MAINTAINER elvido <ralf.hofmann@elvido.net>

ENV DEPLOYMENT_FOLDER="/var/nginx"
ENV LUA_VERSION="5.1"

RUN NGINX_VERSION="1.11.3" && \
    NGINX_PACKAGE_VERSION="${NGINX_VERSION}" && \
    NGINX_PACKAGE_FILENAME="nginx-${NGINX_PACKAGE_VERSION}.tar.gz" && \
    NGINX_PACKAGE_FOLDER="nginx-${NGINX_PACKAGE_VERSION}" && \
    NGINX_BASE_URL="http://nginx.org/download" && \
    NGINX_PACKAGE_URL="${NGINX_BASE_URL}/${NGINX_PACKAGE_FILENAME}" && \
    LUAJIT_VERSION="2.1" && \
    LUAJIT_PACKAGE_VERSION="${LUAJIT_VERSION}.0-beta2" && \
    LUAJIT_PACKAGE_FILENAME="LuaJIT-${LUAJIT_PACKAGE_VERSION}.tar.gz" && \
    LUAJIT_PACKAGE_FOLDER="LuaJIT-${LUAJIT_PACKAGE_VERSION}" && \
    LUAJIT_BASE_URL="http://luajit.org/download" && \
    LUAJIT_PACKAGE_URL="${LUAJIT_BASE_URL}/${LUAJIT_PACKAGE_FILENAME}" && \
    GEOIP_VERSION="1.6.9" && \
    GEOIP_PACKAGE_VERSION="${GEOIP_VERSION}" && \
    GEOIP_PACKAGE_FILENAME="GeoIP-${GEOIP_PACKAGE_VERSION}.tar.gz" && \
    GEOIP_PACKAGE_FOLDER="GeoIP-${GEOIP_PACKAGE_VERSION}" && \
    GEOIP_BASE_URL="https://github.com/maxmind/geoip-api-c/releases/download" && \
    GEOIP_PACKAGE_URL="${GEOIP_BASE_URL}/v${GEOIP_VERSION}/${GEOIP_PACKAGE_FILENAME}" && \
    OPENRESTY_BASE_URL="https://github.com/openresty" && \
    OPENRESTY_LUA_MODULE="lua-nginx-module" && \
    OPENRESTY_LUA_MODULE_VERSION="master" && \
    OPENRESTY_LUA_MODULE_FOLDER="${OPENRESTY_LUA_MODULE}-${OPENRESTY_LUA_MODULE_VERSION}" && \
    OPENRESTY_LUA_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_LUA_MODULE}/archive/${OPENRESTY_LUA_MODULE_VERSION}.zip" && \
    OPENRESTY_UPSTREAM_MODULE="lua-upstream-nginx-module" && \
    OPENRESTY_UPSTREAM_MODULE_VERSION="master" && \
    OPENRESTY_UPSTREAM_MODULE_FOLDER="${OPENRESTY_UPSTREAM_MODULE}-${OPENRESTY_UPSTREAM_MODULE_VERSION}" && \
    OPENRESTY_UPSTREAM_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_UPSTREAM_MODULE}/archive/${OPENRESTY_UPSTREAM_MODULE_VERSION}.zip" && \
    OPENRESTY_ECHO_MODULE="echo-nginx-module" && \
    OPENRESTY_ECHO_MODULE_VERSION="master" && \
    OPENRESTY_ECHO_MODULE_FOLDER="${OPENRESTY_ECHO_MODULE}-${OPENRESTY_ECHO_MODULE_VERSION}" && \
    OPENRESTY_ECHO_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_ECHO_MODULE}/archive/${OPENRESTY_ECHO_MODULE_VERSION}.zip" && \
    OPENRESTY_CORE_MODULE="lua-resty-core" && \
    OPENRESTY_CORE_MODULE_VERSION="master" && \
    OPENRESTY_CORE_MODULE_FOLDER="${OPENRESTY_CORE_MODULE}-${OPENRESTY_CORE_MODULE_VERSION}" && \
    OPENRESTY_CORE_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_CORE_MODULE}/archive/${OPENRESTY_CORE_MODULE_VERSION}.zip" && \
    OPENRESTY_LRU_MODULE="lua-resty-lrucache" && \
    OPENRESTY_LRU_MODULE_VERSION="master" && \
    OPENRESTY_LRU_MODULE_FOLDER="${OPENRESTY_LRU_MODULE}-${OPENRESTY_LRU_MODULE_VERSION}" && \
    OPENRESTY_LRU_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_LRU_MODULE}/archive/${OPENRESTY_LRU_MODULE_VERSION}.zip" && \
    OPENRESTY_DNS_MODULE="lua-resty-dns" && \
    OPENRESTY_DNS_MODULE_VERSION="master" && \
    OPENRESTY_DNS_MODULE_FOLDER="${OPENRESTY_DNS_MODULE}-${OPENRESTY_DNS_MODULE_VERSION}" && \
    OPENRESTY_DNS_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_DNS_MODULE}/archive/${OPENRESTY_DNS_MODULE_VERSION}.zip" && \
    OPENRESTY_JSON_MODULE="lua-cjson" && \
    OPENRESTY_JSON_MODULE_VERSION="master" && \
    OPENRESTY_JSON_MODULE_FOLDER="${OPENRESTY_JSON_MODULE}-${OPENRESTY_JSON_MODULE_VERSION}" && \
    OPENRESTY_JSON_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_JSON_MODULE}/archive/${OPENRESTY_JSON_MODULE_VERSION}.zip" && \
    \
    apk upgrade --update && \
    apk --no-cache add ca-certificates openssl pcre zlib && \
    apk --no-cache add --virtual=.build-dependencies build-base linux-headers openssl-dev pcre-dev curl libarchive-tools zlib-dev && \
    \
    echo "Downloading and building LuaJIT package: $LUAJIT_PACKAGE_FILENAME" >&2 && \
    curl -kSL "${LUAJIT_PACKAGE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${LUAJIT_PACKAGE_FOLDER}" && \
      make PREFIX=/usr && \
      make install PREFIX=/usr && \
      ln -sf /usr/bin/luajit-${LUAJIT_PACKAGE_VERSION} /usr/bin/luajit || true && \
      export LUAJIT_LIB="/usr/lib" && \
      export LUAJIT_INC="/usr/include/luajit-${LUAJIT_VERSION}" && \
    cd /tmp && rm -rf "/tmp/${LUAJIT_PACKAGE_FOLDER}" && \
    \
    echo "Downloading and building GeoIP package: $GEOIP_PACKAGE_FILENAME" >&2 && \
    echo "${GEOIP_PACKAGE_URL}" >&2 && \
    curl -kSL "${GEOIP_PACKAGE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${GEOIP_PACKAGE_FOLDER}" && \
      ./configure \
        --prefix=/usr \
        --sysconfdir=/etc/geoip \
        --mandir=/usr/share/man \
        --infodir=/usr/share/info \
      && \
      make install && \
    cd /tmp && rm -rf "/tmp/${GEOIP_PACKAGE_FOLDER}" && \
    \
    echo "Downloading and building nginx package: $NGINX_PACKAGE_FILENAME" >&2 && \
    curl -kSL "${NGINX_PACKAGE_URL}" | bsdtar -xf- -C "/tmp" && \
    curl -kSL "${OPENRESTY_LUA_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    curl -kSL "${OPENRESTY_UPSTREAM_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    curl -kSL "${OPENRESTY_ECHO_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${NGINX_PACKAGE_FOLDER}" && \
      ./configure \
        --prefix=/etc/nginx \
        --sbin-path=/usr/sbin/nginx \
        --conf-path="${DEPLOYMENT_FOLDER}/config/nginx.conf" \
        --error-log-path="${DEPLOYMENT_FOLDER}/log/error.log" \
        --http-log-path="${DEPLOYMENT_FOLDER}/log/access.log" \
        --pid-path="${DEPLOYMENT_FOLDER}/run/nginx.pid" \
        --lock-path="${DEPLOYMENT_FOLDER}/run/nginx.lock" \
        --http-client-body-temp-path="${DEPLOYMENT_FOLDER}/cache/client_temp" \
        --http-proxy-temp-path="${DEPLOYMENT_FOLDER}/cache/proxy_temp" \
        --user=nginx \
        --group=nginx \
        --without-http_fastcgi_module\
        --without-http_uwsgi_module\
        --without-http_scgi_module\
  	    --with-http_ssl_module \
  	    --with-http_realip_module \
  	    --with-http_addition_module \
  	    --with-http_sub_module \
  	    --with-http_dav_module \
  	    --with-http_flv_module \
  	    --with-http_mp4_module \
  	    --with-http_gunzip_module \
  	    --with-http_gzip_static_module \
  	    --with-http_random_index_module \
  	    --with-http_secure_link_module \
  	    --with-http_stub_status_module \
  	    --with-http_auth_request_module \
  	    --with-threads \
  	    --with-stream \
  	    --with-stream_ssl_module \
  	    --with-http_slice_module \
  	    --with-file-aio \
  	    --with-http_v2_module \
  	    --with-ipv6 \
  	    --with-pcre-jit \
        --with-mail=dynamic \
        --with-mail_ssl_module \
        --with-http_geoip_module=dynamic \
        --add-dynamic-module="../${OPENRESTY_LUA_MODULE_FOLDER}" \
        --add-dynamic-module="../${OPENRESTY_UPSTREAM_MODULE_FOLDER}" \
        --add-dynamic-module="../${OPENRESTY_ECHO_MODULE_FOLDER}" \
      && \
      mkdir -p "${DEPLOYMENT_FOLDER}/run/"    && \
      mkdir -p "${DEPLOYMENT_FOLDER}/log/"    && \
      mkdir -p "${DEPLOYMENT_FOLDER}/cache/"  && \
      mkdir -p "${DEPLOYMENT_FOLDER}/config/" && \
      make install && \
    cd /tmp && rm -rf \
      "/tmp/${NGINX_PACKAGE_FOLDER}" \
      "/tmp/${OPENRESTY_LUA_MODULE_FOLDER}" \
      "/tmp/${OPENRESTY_UPSTREAM_MODULE_FOLDER}" \
      "/tmp/${OPENRESTY_ECHO_MODULE_FOLDER}" \
    && \
    mv /etc/nginx/html "${DEPLOYMENT_FOLDER}" && \
    sed -i -e "s#root[[:blank:]]\+html;#root ${DEPLOYMENT_FOLDER}/html;#g" "${DEPLOYMENT_FOLDER}/config/nginx.conf" && \
    sed -i -e 's/#access_log[[:blank:]]\+logs\/access.log[[:blank:]]\+main;/access_log \/dev\/stdout;/' -e 's/#error_log[[:blank:]]\+logs\/error.log[[:blank:]]\+notice;/error_log \/dev\/stderr notice;/' "${DEPLOYMENT_FOLDER}/config/nginx.conf" && \
    adduser -D nginx && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_CORE_MODULE" >&2 && \
    curl -kSL "${OPENRESTY_CORE_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_CORE_MODULE_FOLDER}" && \
      make install PREFIX=/usr && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_CORE_MODULE_FOLDER}" && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_LRU_MODULE" >&2 && \
    curl -kSL "${OPENRESTY_LRU_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_LRU_MODULE_FOLDER}" && \
      make install PREFIX=/usr && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_LRU_MODULE_FOLDER}" && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_DNS_MODULE" >&2 && \
    curl -kSL "${OPENRESTY_DNS_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_DNS_MODULE_FOLDER}" && \
      make install PREFIX=/usr && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_DNS_MODULE_FOLDER}" && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_JSON_MODULE" >&2 && \
    curl -kSL "${OPENRESTY_JSON_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_JSON_MODULE_FOLDER}" && \
      make install PREFIX=/usr LUA_INCLUDE_DIR="${LUAJIT_INC}" && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_JSON_MODULE_FOLDER}" && \
    \
    apk del .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

    WORKDIR ${DEPLOYMENT_FOLDER}/

    ONBUILD RUN rm -rf ${DEPLOYMENT_FOLDER}/run/*    \
                       ${DEPLOYMENT_FOLDER}/log/*    \
                       ${DEPLOYMENT_FOLDER}/cache/*  \
                       ${DEPLOYMENT_FOLDER}/config/* \
                       ${DEPLOYMENT_FOLDER}/html/*
    ONBUILD COPY files/nginx ${DEPLOYMENT_FOLDER}/

    VOLUME ["/var/nginx"]

    EXPOSE 80 443
    CMD ["nginx", "-g", "daemon off;"]
