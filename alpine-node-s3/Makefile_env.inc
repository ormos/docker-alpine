# configuration parameters
S3_ACCESS_KEY:=elvido
S3_SECRET_KEY:=12456789
HOST_NAME:=$(shell hostname -f)
HOST_IP:=$(shell ip route get 8.8.8.8 | head -1 | cut -d' ' -f8)
HOST_PORT:=8090

ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

# docker options
PORTS = -p $(HOST_PORT):8000

VOLUMES = \
  -v $(ROOT_DIR)/data/buckets:/usr/src/app/localData \
  -v $(ROOT_DIR)/data/meta:/usr/src/app/localMetadata
#  -v $(ROOT_DIR)/config.json:/usr/src/app/config.json \
#  -v $(ROOT_DIR)/authdata.json:/usr/src/app/conf/authdata.json

ENV = \
  -e HOST_NAME="$(HOST_NAME)" \
  -e ACCESS_KEY="$(S3_ACCESS_KEY)" \
  -e SECRET_KEY="$(S3_SECRET_KEY)"
