FROM elvido/alpine-nginx-lua

MAINTAINER elvido <ralf.hofmann@elvido.net>

RUN GEOIP_COUNTRY_DATA_URL="http://geolite.maxmind.com/download/geoip/database/GeoLiteCountry/GeoIP.dat.gz" && \
    GEOIP_CITY_DATA_URL="http://geolite.maxmind.com/download/geoip/database/GeoLiteCity.dat.gz" && \
    \
    apk upgrade --update && \
    apk --no-cache add --virtual=.build-dependencies curl libarchive-tools && \
    \
    echo "Downloading and installing GeoIP databases" >&2 && \
    mkdir -p "/etc/nginx/geoip" && \
    curl -kSL "${GEOIP_COUNTRY_DATA_URL}" | gunzip >|"/etc/nginx/geoip/GeoIP-Country.dat" && \
    curl -kSL "${GEOIP_CITY_DATA_URL}"    | gunzip >|"/etc/nginx/geoip/GeoIP-City.dat" && \
    \
    apk del .build-dependencies && \
    rm -rf /tmp/* /var/cache/apk/*

    VOLUME ["/etc/nginx/geoip"]

    CMD ["nginx", "-g", "daemon off;"]
