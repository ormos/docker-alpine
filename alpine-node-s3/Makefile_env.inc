# configuration parameters

S3_ACCESS_KEY:=elvido
S3_SECRET_KEY:=123456789

HOST_NAME:=$(shell hostname -f)
HOST_IP:=$(shell ip route get 8.8.8.8 | head -1 | cut -d' ' -f8)
HOST_PORT:=8090

ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

DATA_FOLDER:=$(ROOT_DIR)/data

# docker options
PORTS = -p $(HOST_PORT):8000

VOLUMES = \
  -v $(DATA_FOLDER)/buckets:/usr/src/app/localData \
  -v $(DATA_FOLDER)/meta:/usr/src/app/localMetadata

ENV = \
  -e HOST_NAME="$(HOST_NAME)" \
  -e ACCESS_KEY="$(S3_ACCESS_KEY)" \
  -e SECRET_KEY="$(S3_SECRET_KEY)"

