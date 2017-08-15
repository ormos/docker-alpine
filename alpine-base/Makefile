ENV_FILE ?= Makefile_env.inc

ifneq ("$(wildcard $(ENV_FILE))","")
include $(ENV_FILE)
endif

.PHONY: build push commit clean

default: build

build:
	./build-images build

push:
	./build-images push

commit:
	./build-images commit

clean:
	./build-images cleanup
