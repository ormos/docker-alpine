# configuration parameters
S3_ACCESS_KEY:=ormos
S3_SECRET_KEY:=123456789
S3_REGION:=eu
S3_STORAGE:=/var/storage
DEF_ARGS:=server $(S3_STORAGE)

HOST_SYS:= $(shell uname -s)
ifeq ($(HOST_SYS),Linux)
  HOST_IP:=$(shell ip route get 8.8.8.8 | head -1 | cut -d' ' -f7)
endif
ifeq ($(HOST_SYS),Darwin)
  HOST_IP:=$(shell ipconfig getifaddr `route get 8.8.8.8 | awk '{ if ($$1 ~/interface:/) { print $$2} }'`)
endif
HOST_NAME:=$(shell hostname -f)
HOST_PORT:=9000

ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

DATA_FOLDER:=$(ROOT_DIR)/data

# docker options
#PORTS = -p $(HOST_PORT):8089

VOLUMES = \
  -v $(DATA_FOLDER):$(S3_STORAGE)

ENV = \
  -e HOST_NAME="$(HOST_NAME)" \
  -e MINIO_ACCESS_KEY="$(S3_ACCESS_KEY)" \
  -e MINIO_SECRET_KEY="$(S3_SECRET_KEY)" \
  -e MINIO_REGION="$(S3_REGION)"

ifneq (,$(filter run start,$(firstword $(MAKECMDGOALS))))
  RUN_ARGS:=$(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@true)
endif
ifeq (,$(RUN_ARGS))
  RUN_ARGS:=$(DEF_ARGS)
endif
