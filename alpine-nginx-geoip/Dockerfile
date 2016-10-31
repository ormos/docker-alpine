FROM elvido/alpine-nginx-lua

MAINTAINER elvido <ralf.hofmann@elvido.net>

RUN GEOIP_COUNTRY_DATA_URL="http://geolite.maxmind.com/download/geoip/database/GeoLiteCountry/GeoIP.dat.gz" && \
    GEOIP_CITY_DATA_URL="http://geolite.maxmind.com/download/geoip/database/GeoLiteCity.dat.gz" && \
    \
    apk --no-cache upgrade --update && \
    apk --no-cache add --quiet --virtual=.build-dependencies curl libarchive-tools && \
    \
    echo "Downloading and installing GeoIP databases..." >&2 && \
    mkdir -p "/etc/nginx/geoip" && \
    curl -kSL "${GEOIP_COUNTRY_DATA_URL}" | gunzip >|"/etc/nginx/geoip/GeoIP-Country.dat" && \
    curl -kSL "${GEOIP_CITY_DATA_URL}"    | gunzip >|"/etc/nginx/geoip/GeoIP-City.dat" && \
    \
    echo "Deploying optional LUA packages..." >&2 && \
    luarocks-deploy add "lua-iconv" && \
    \
    echo "Cleaning up..." >&2 && \
    apk del --quiet --purge .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

VOLUME ["/etc/nginx/geoip"]

CMD ["nginx", "-g", "daemon off;"]
