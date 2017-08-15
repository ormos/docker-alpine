# configuration parameters
S3_ACCESS_KEY:=elvido
S3_SECRET_KEY:=123456789
S3_REGION:=eu
S3_STORAGE:=/var/storage

HOST_NAME:=$(shell hostname -f)
HOST_PORT:=9000
HOST_IP:=$(shell ip route get 8.8.8.8 | head -1 | cut -d' ' -f8)

ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

DATA_FOLDER:=$(ROOT_DIR)/data

SHELL:=/bin/sh

# docker options
#PORTS = -p $(HOST_PORT):8089

VOLUMES = \
  -v $(DATA_FOLDER):$(S3_STORAGE)

ENV = \
  -e HOST_NAME="$(HOST_NAME)" \
  -e MINIO_ACCESS_KEY="$(S3_ACCESS_KEY)" \
  -e MINIO_SECRET_KEY="$(S3_SECRET_KEY)" \
  -e MINIO_REGION="$(S3_REGION)"

