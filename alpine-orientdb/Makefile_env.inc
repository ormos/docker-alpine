# configuration parameters
DB_ROOT_PWD:=0rient

HOST_SYS:= $(shell uname -s)
ifeq ($(HOST_SYS),Linux)
  HOST_IP:=$(shell ip route get 8.8.8.8 | head -1 | cut -d' ' -f7)
endif
ifeq ($(HOST_SYS),Darwin)
  HOST_IP:=$(shell ipconfig getifaddr `route get 8.8.8.8 | awk '{ if ($$1 ~/interface:/) { print $$2} }'`)
endif
HOST_NAME:=$(shell hostname -f)
HOST_PORT:=80

ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

# docker options
#PORTS = -p $(HOST_PORT):2480

#VOLUMES = \
#  -v $(ROOT_DIR)/data:/var/orientdb \

ENV = \
  -e ORIENTDB_ROOT_PASSWORD="$(DB_ROOT_PWD)"

ifneq (,$(filter run start,$(firstword $(MAKECMDGOALS))))
  RUN_ARGS:=$(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@true)
endif
ifeq (,$(RUN_ARGS))
  RUN_ARGS:=$(DEF_ARGS)
endif
