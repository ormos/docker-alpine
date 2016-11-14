ENV_FILE ?= Makefile_env.inc

ifneq ("$(wildcard $(ENV_FILE))","")
include $(ENV_FILE)
endif


.PHONY: build push commit clean

default: build

build:
	./build-image

push:
	./build-image push

commit:
	./build-image commit

clean:
	./build-image cleanup
