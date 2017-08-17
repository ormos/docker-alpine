# configuration parameters
DEF_ARGS:=go

ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

DATA_FOLDER:=$(ROOT_DIR)/data

# docker options
#PORTS = -p $(HOST_PORT):8089

#VOLUMES = \
#  -v $(DATA_FOLDER):$(S3_STORAGE)

#ENV = \

ifneq (,$(filter run start,$(firstword $(MAKECMDGOALS))))
  RUN_ARGS:=$(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@true)
endif
ifeq (,$(RUN_ARGS))
  RUN_ARGS:=$(DEF_ARGS)
endif
