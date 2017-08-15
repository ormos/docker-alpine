ENV_FILE ?= Makefile_env.inc

ifneq ("$(wildcard $(ENV_FILE))","")
include $(ENV_FILE)
endif

NS = elvido
VERSION ?= 3.6
TAGS ?= latest

REPO = alpine-java
NAME = alpine-java
INSTANCE = default

XSHELL ?= /bin/sh

.PHONY: build push shell run start stop rm release

default: build

build:
	./build-images build

push:
	./build-images push

shell:
	docker run --rm --name $(NAME)-$(INSTANCE) -i -t $(PORTS) $(VOLUMES) $(ENV) --entrypoint=$(XSHELL) $(NS)/$(REPO):$(VERSION)

run:
	docker run --rm --name $(NAME)-$(INSTANCE) $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION) $(RUN_ARGS)

start:
	docker run -d --rm --name $(NAME)-$(INSTANCE) $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION)

stop:
	docker stop $(NAME)-$(INSTANCE)

rm:
	docker rm $(NAME)-$(INSTANCE)

release: build push
