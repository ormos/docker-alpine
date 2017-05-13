FROM elvido/alpine

MAINTAINER elvido <ralf.hofmann@elvido.net>

LABEL "net.elvido.alpine-nginx-lua"="3.5"

ENV DEPLOYMENT_FOLDER="/var/nginx" \
    LUA_VERSION="5.1" \
    LUA_JIT="2.1" \
    LUA_INC="/usr/include/luajit-2.1" \
    LUA_LIB="/usr/lib/lua"

RUN NGINX_VERSION="1.12.0" && \
    NGINX_PACKAGE_VERSION="${NGINX_VERSION}" && \
    NGINX_PACKAGE_FILENAME="nginx-${NGINX_PACKAGE_VERSION}.tar.gz" && \
    NGINX_PACKAGE_FOLDER="nginx-${NGINX_PACKAGE_VERSION}" && \
    NGINX_BASE_URL="http://nginx.org/download" && \
    NGINX_PACKAGE_URL="${NGINX_BASE_URL}/${NGINX_PACKAGE_FILENAME}" && \
    NGINX_DEVKIT_MODULE="ngx_devel_kit" && \
    NGINX_DEVKIT_MODULE_VERSION="0.3.0" && \
    NGINX_DEVKIT_MODULE_FOLDER="${NGINX_DEVKIT_MODULE}-${NGINX_DEVKIT_MODULE_VERSION}" && \
    NGINX_DEVKIT_BASE_URL="https://github.com/simpl/ngx_devel_kit" && \
    NGINX_DEVKIT_MODULE_URL="${NGINX_DEVKIT_BASE_URL}/archive/v${NGINX_DEVKIT_MODULE_VERSION}.zip" && \
    NGINX_GEOIP_MODULE="ngx_http_geoip2_module" && \
    NGINX_GEOIP_MODULE_VERSION="master" && \
    NGINX_GEOIP_MODULE_FOLDER="${NGINX_GEOIP_MODULE}-${NGINX_GEOIP_MODULE_VERSION}" && \
    NGINX_GEOIP_BASE_URL="https://github.com/leev" && \
    NGINX_GEOIP_MODULE_URL="${NGINX_GEOIP_BASE_URL}/${NGINX_GEOIP_MODULE}/archive/${NGINX_GEOIP_MODULE_VERSION}.zip" && \
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
    OPENRESTY_MISC_MODULE="set-misc-nginx-module" && \
    OPENRESTY_MISC_MODULE_VERSION="master" && \
    OPENRESTY_MISC_MODULE_FOLDER="${OPENRESTY_MISC_MODULE}-${OPENRESTY_MISC_MODULE_VERSION}" && \
    OPENRESTY_MISC_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_MISC_MODULE}/archive/${OPENRESTY_MISC_MODULE_VERSION}.zip" && \
    OPENRESTY_HEADER_MODULE="headers-more-nginx-module" && \
    OPENRESTY_HEADER_MODULE_VERSION="master" && \
    OPENRESTY_HEADER_MODULE_FOLDER="${OPENRESTY_HEADER_MODULE}-${OPENRESTY_HEADER_MODULE_VERSION}" && \
    OPENRESTY_HEADER_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_HEADER_MODULE}/archive/${OPENRESTY_HEADER_MODULE_VERSION}.zip" && \
    OPENRESTY_CORE_MODULE="lua-resty-core" && \
    OPENRESTY_CORE_MODULE_VERSION="master" && \
    OPENRESTY_CORE_MODULE_FOLDER="${OPENRESTY_CORE_MODULE}-${OPENRESTY_CORE_MODULE_VERSION}" && \
    OPENRESTY_CORE_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_CORE_MODULE}/archive/${OPENRESTY_CORE_MODULE_VERSION}.zip" && \
    OPENRESTY_STRING_MODULE="lua-resty-string" && \
    OPENRESTY_STRING_MODULE_VERSION="master" && \
    OPENRESTY_STRING_MODULE_FOLDER="${OPENRESTY_STRING_MODULE}-${OPENRESTY_STRING_MODULE_VERSION}" && \
    OPENRESTY_STRING_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_STRING_MODULE}/archive/${OPENRESTY_STRING_MODULE_VERSION}.zip" && \
    OPENRESTY_LOCK_MODULE="lua-resty-lock" && \
    OPENRESTY_LOCK_MODULE_VERSION="master" && \
    OPENRESTY_LOCK_MODULE_FOLDER="${OPENRESTY_LOCK_MODULE}-${OPENRESTY_LOCK_MODULE_VERSION}" && \
    OPENRESTY_LOCK_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_LOCK_MODULE}/archive/${OPENRESTY_LOCK_MODULE_VERSION}.zip" && \
    OPENRESTY_LRU_MODULE="lua-resty-lrucache" && \
    OPENRESTY_LRU_MODULE_VERSION="master" && \
    OPENRESTY_LRU_MODULE_FOLDER="${OPENRESTY_LRU_MODULE}-${OPENRESTY_LRU_MODULE_VERSION}" && \
    OPENRESTY_LRU_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_LRU_MODULE}/archive/${OPENRESTY_LRU_MODULE_VERSION}.zip" && \
    OPENRESTY_DNS_MODULE="lua-resty-dns" && \
    OPENRESTY_DNS_MODULE_VERSION="master" && \
    OPENRESTY_DNS_MODULE_FOLDER="${OPENRESTY_DNS_MODULE}-${OPENRESTY_DNS_MODULE_VERSION}" && \
    OPENRESTY_DNS_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_DNS_MODULE}/archive/${OPENRESTY_DNS_MODULE_VERSION}.zip" && \
    OPENRESTY_TRAFFIC_MODULE="lua-resty-limit-traffic" && \
    OPENRESTY_TRAFFIC_MODULE_VERSION="master" && \
    OPENRESTY_TRAFFIC_MODULE_FOLDER="${OPENRESTY_TRAFFIC_MODULE}-${OPENRESTY_TRAFFIC_MODULE_VERSION}" && \
    OPENRESTY_TRAFFIC_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_TRAFFIC_MODULE}/archive/${OPENRESTY_TRAFFIC_MODULE_VERSION}.zip" && \
    OPENRESTY_JSON_MODULE="lua-cjson" && \
    OPENRESTY_JSON_MODULE_VERSION="master" && \
    OPENRESTY_JSON_MODULE_FOLDER="${OPENRESTY_JSON_MODULE}-${OPENRESTY_JSON_MODULE_VERSION}" && \
    OPENRESTY_JSON_MODULE_URL="${OPENRESTY_BASE_URL}/${OPENRESTY_JSON_MODULE}/archive/${OPENRESTY_JSON_MODULE_VERSION}.zip" && \
    LUAJIT_VERSION="2.1" && \
    LUAJIT_PACKAGE_VERSION="${LUAJIT_VERSION}.0-beta2" && \
    LUAJIT_PACKAGE_FILENAME="v${LUAJIT_VERSION}.zip" && \
    LUAJIT_PACKAGE_FOLDER="LuaJIT-${LUAJIT_VERSION}" && \
    LUAJIT_BASE_URL="https://github.com/LuaJIT/LuaJIT" && \
    LUAJIT_PACKAGE_URL="${LUAJIT_BASE_URL}/archive/${LUAJIT_PACKAGE_FILENAME}" && \
    LIBCIDR_VERSION="1.2.3" && \
    LIBCIDR_PACKAGE_FILENAME="libcidr-${LIBCIDR_VERSION}.tar.xz" && \
    LIBCIDR_PACKAGE_FOLDER="libcidr-${LIBCIDR_VERSION}" && \
    LIBCIDR_BASE_URL="http://www.over-yonder.net/%7Efullermd/projects/libcidr/" && \
    LIBCIDR_PACKAGE_URL="${LIBCIDR_BASE_URL}/${LIBCIDR_PACKAGE_FILENAME}" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates libstdc++ openssl pcre zlib libmaxminddb && \
    apk --no-cache add --quiet --virtual=.build-dependencies build-base coreutils patch linux-headers openssl-dev pcre-dev curl tar libarchive-tools xz zlib-dev libmaxminddb-dev && \
    \
    echo "Downloading and building LuaJIT package: $LUAJIT_PACKAGE_FILENAME" >&2 && \
    curl -kSL -# "${LUAJIT_PACKAGE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${LUAJIT_PACKAGE_FOLDER}" && \
      make PREFIX=/usr && \
      make install PREFIX=/usr && \
      ln -sf /usr/bin/luajit-${LUAJIT_PACKAGE_VERSION} /usr/bin/luajit || : && \
      export LUAJIT_LIB="${LUA_LIB}" && \
      export LUAJIT_INC="${LUA_INC}" && \
    cd /tmp && rm -rf "/tmp/${LUAJIT_PACKAGE_FOLDER}" && \
    \
    echo "Apply temporary patch for LuaJIT (${LUAJIT_PACKAGE_VERSION}) upstream" >&2 && \    
    sed -ie 's/#define LUA_VERSION_NUM	501/#define LUA_VERSION_NUM	502/g' "${LUA_INC}/lua.h" && \
    \
    echo "Downloading and building libCIDR package: $LIBCIDR_PACKAGE_FILENAME" >&2 && \
    curl -kSL -# "${LIBCIDR_PACKAGE_URL}" | tar -xJf- -C "/tmp" && \
    cd "/tmp/${LIBCIDR_PACKAGE_FOLDER}" && \
      make PREFIX=/usr && \
      make PREFIX=/usr install && \
    ln -sf /usr/bin/luajit-2.1.0-beta3 /usr/bin/luajit && \
    cd /tmp && rm -rf "/tmp/${LIBCIDR_PACKAGE_FOLDER}" && \
    \
    echo "Downloading and building nginx package: $NGINX_PACKAGE_FILENAME" >&2 && \
    curl -kSL -# "${NGINX_PACKAGE_URL}" | bsdtar -xf- -C "/tmp" && \
    echo "Downloading and building nginx devkit package: $NGINX_DEVKIT_MODULE_FOLDER" >&2 && \
    curl -kSL -# "${NGINX_DEVKIT_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    echo "Downloading and building nginx geoip package: $NGINX_GEOIP_MODULE_FOLDER" >&2 && \
    curl -kSL -# "${NGINX_GEOIP_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    echo "Downloading and building openresty lua package: $OPENRESTY_LUA_MODULE_FOLDER" >&2 && \
    curl -kSL -# "${OPENRESTY_LUA_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    echo "Downloading and building openresty upstream package: $OPENRESTY_UPSTREAM_MODULE_FOLDER" >&2 && \
    curl -kSL -# "${OPENRESTY_UPSTREAM_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    echo "Downloading and building openresty echo package: $OPENRESTY_ECHO_MODULE_FOLDER" >&2 && \
    curl -kSL -# "${OPENRESTY_ECHO_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    echo "Downloading and building openresty set-misc package: $OPENRESTY_MISC_MODULE_FOLDER" >&2 && \
    curl -kSL -# "${OPENRESTY_MISC_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    echo "Downloading and building openresty header package: $OPENRESTY_HEADER_MODULE_FOLDER" >&2 && \
    curl -kSL -# "${OPENRESTY_HEADER_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    \
    echo "Apply temporary patches for using LuaJIT upstream with nginx 1.11.13" >&2 && \    
    sed -ie 's/#if LUA_VERSION_NUM != 501/#if LUA_VERSION_NUM < 501/g' "/tmp/${OPENRESTY_LUA_MODULE_FOLDER}/config" && \
    sed -ie 's/#if LUA_VERSION_NUM != 501/#if LUA_VERSION_NUM < 501/g' "/tmp/${OPENRESTY_LUA_MODULE_FOLDER}/src/ngx_http_lua_common.h" && \
    \
    cd "/tmp/${NGINX_PACKAGE_FOLDER}" && \
      ./configure \
        --prefix=/etc/nginx \
        --sbin-path=/usr/sbin/nginx \
        --modules-path=/usr/lib/nginx/modules \
        --conf-path="${DEPLOYMENT_FOLDER}/config/nginx.conf" \
        --error-log-path="${DEPLOYMENT_FOLDER}/log/error.log" \
        --http-log-path="${DEPLOYMENT_FOLDER}/log/access.log" \
        --pid-path="${DEPLOYMENT_FOLDER}/run/nginx.pid" \
        --lock-path="${DEPLOYMENT_FOLDER}/run/nginx.lock" \
        --http-client-body-temp-path="${DEPLOYMENT_FOLDER}/cache/client_temp" \
        --http-proxy-temp-path="${DEPLOYMENT_FOLDER}/cache/proxy_temp" \
        --user=nginx \
        --group=nginx \
        --without-http_userid_module \
        --without-http_ssi_module \
        --without-http_fastcgi_module \
        --without-http_uwsgi_module \
        --without-http_scgi_module \
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
        --add-dynamic-module="../${NGINX_DEVKIT_MODULE_FOLDER}" \
        --add-dynamic-module="../${NGINX_GEOIP_MODULE_FOLDER}" \
        --add-dynamic-module="../${OPENRESTY_LUA_MODULE_FOLDER}" \
        --add-dynamic-module="../${OPENRESTY_UPSTREAM_MODULE_FOLDER}" \
        --add-dynamic-module="../${OPENRESTY_ECHO_MODULE_FOLDER}" \
        --add-dynamic-module="../${OPENRESTY_MISC_MODULE_FOLDER}" \
        --add-dynamic-module="../${OPENRESTY_HEADER_MODULE_FOLDER}" \
      && \
      mkdir -p "${DEPLOYMENT_FOLDER}/run/"    && \
      mkdir -p "${DEPLOYMENT_FOLDER}/log/"    && \
      mkdir -p "${DEPLOYMENT_FOLDER}/cache/"  && \
      mkdir -p "${DEPLOYMENT_FOLDER}/config/" && \
      make install && \
    cd /tmp && rm -rf \
      "/tmp/${NGINX_PACKAGE_FOLDER}" \
      "/tmp/${NGINX_DEVKIT_MODULE_FOLDER}" \
      "/tmp/${NGINX_GEOIP_MODULE_FOLDER}" \
      "/tmp/${OPENRESTY_LUA_MODULE_FOLDER}" \
      "/tmp/${OPENRESTY_UPSTREAM_MODULE_FOLDER}" \
      "/tmp/${OPENRESTY_ECHO_MODULE_FOLDER}" \
      "/tmp/${OPENRESTY_MISC_MODULE_FOLDER}" \
      "/tmp/${OPENRESTY_HEADER_MODULE_FOLDER}" \
    && \
    rm -f "${DEPLOYMENT_FOLDER}/config/"fastcgi* \
          "${DEPLOYMENT_FOLDER}/config/"scgi* \
          "${DEPLOYMENT_FOLDER}/config/"uwsgi* \
          "${DEPLOYMENT_FOLDER}/config/"*.default \
    && \
    mv /etc/nginx/html "${DEPLOYMENT_FOLDER}" && \
    rmdir /etc/nginx 2>/dev/null || : && \
    sed -i -e "s#root[[:blank:]]\+html;#root ${DEPLOYMENT_FOLDER}/html;#g" "${DEPLOYMENT_FOLDER}/config/nginx.conf" && \
    sed -i -e 's/#access_log[[:blank:]]\+logs\/access.log[[:blank:]]\+main;/access_log \/dev\/stdout;/' -e 's/#error_log[[:blank:]]\+logs\/error.log[[:blank:]]\+notice;/error_log \/dev\/stderr notice;/' "${DEPLOYMENT_FOLDER}/config/nginx.conf" && \
    adduser -D nginx && \
    chown -R nginx:nginx ${DEPLOYMENT_FOLDER} && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_CORE_MODULE" >&2 && \
    curl -kSL -# "${OPENRESTY_CORE_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_CORE_MODULE_FOLDER}" && \
      make install PREFIX=/usr && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_CORE_MODULE_FOLDER}" && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_STRING_MODULE" >&2 && \
    curl -kSL -# "${OPENRESTY_STRING_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_STRING_MODULE_FOLDER}" && \
      make install PREFIX=/usr && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_STRING_MODULE_FOLDER}" && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_LOCK_MODULE" >&2 && \
    curl -kSL -# "${OPENRESTY_LOCK_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_LOCK_MODULE_FOLDER}" && \
      make install PREFIX=/usr && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_STRING_MODULE_FOLDER}" && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_LRU_MODULE" >&2 && \
    curl -kSL -# "${OPENRESTY_LRU_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_LRU_MODULE_FOLDER}" && \
      make install PREFIX=/usr && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_LRU_MODULE_FOLDER}" && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_DNS_MODULE" >&2 && \
    curl -kSL -# "${OPENRESTY_DNS_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_DNS_MODULE_FOLDER}" && \
      make install PREFIX=/usr && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_DNS_MODULE_FOLDER}" && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_TRAFFIC_MODULE" >&2 && \
    curl -kSL -# "${OPENRESTY_TRAFFIC_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_TRAFFIC_MODULE_FOLDER}" && \
      make install PREFIX=/usr && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_TRAFFIC_MODULE_FOLDER}" && \
    \
    echo "Downloading and installing nginx LUA package: $OPENRESTY_JSON_MODULE" >&2 && \
    curl -kSL -# "${OPENRESTY_JSON_MODULE_URL}" | bsdtar -xf- -C "/tmp" && \
    cd "/tmp/${OPENRESTY_JSON_MODULE_FOLDER}" && \
      make install PREFIX=/usr LUA_INCLUDE_DIR="${LUAJIT_INC}" && \
    cd /tmp && rm -rf "/tmp/${OPENRESTY_JSON_MODULE_FOLDER}" && \
    \
    rm -rf ${DEPLOYMENT_FOLDER}/run/*    \
           ${DEPLOYMENT_FOLDER}/log/*    \
           ${DEPLOYMENT_FOLDER}/cache/*  \
           ${DEPLOYMENT_FOLDER}/config/*.conf \
           ${DEPLOYMENT_FOLDER}/html \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

COPY rootfs /

EXPOSE 80 443

WORKDIR ${DEPLOYMENT_FOLDER}/

CMD ["nginx", \
     "-p", "/usr/lib/nginx", \
     "-c", "/var/nginx/config/nginx.conf", \
     "-g", "daemon off; error_log /dev/stderr info;"]
