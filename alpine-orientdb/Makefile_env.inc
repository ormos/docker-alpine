# configuration parameters
DB_ROOT_PWD:=0rient
HOST_PORT:=80
HOST_IP:=$(shell ip route get 8.8.8.8 | head -1 | cut -d' ' -f8)

ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

# docker options
#PORTS = -p $(HOST_PORT):2480

VOLUMES = \
  -v $(ROOT_DIR)/data:/var/orientdb \

ENV = \
  -e ORIENTDB_ROOT_PASSWORD="$(DB_ROOT_PWD)"