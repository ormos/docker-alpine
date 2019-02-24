ENV_FILE ?= Makefile_env.inc

ifneq ("$(wildcard $(ENV_FILE))","")
include $(ENV_FILE)
endif

NS = ormos
VERSION ?= 3.9
TAGS ?= latest

REPO = alpine-minio
NAME = alpine-minio
INSTANCE = default

XSHELL ?= /bin/sh

.PHONY: build push shell run start stop rm release tag $(TAGS) data-folder

default: build

build:
	docker build -t $(NS)/$(REPO):$(VERSION) .

push:
	docker push $(NS)/$(REPO):$(VERSION)

shell: data-folder
	docker run --rm --name $(NAME)-$(INSTANCE) -i -t $(PORTS) $(VOLUMES) $(ENV) --entrypoint=$(XSHELL) $(NS)/$(REPO):$(VERSION)

run: data-folder
	docker run --rm --name $(NAME)-$(INSTANCE) $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION) $(RUN_ARGS)

start: data-folder
	docker run -d --rm --name $(NAME)-$(INSTANCE) $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION) $(RUN_ARGS)

stop:
	docker stop $(NAME)-$(INSTANCE)

rm:
	docker rm -f $(NAME)-$(INSTANCE)

release: build
	@make --no-print-directory tag -e VERSION="$(VERSION)" -e TAGS="$(TAGS)"
	@make --no-print-directory push -e VERSION="$(VERSION)"

tag: $(TAGS)

$(TAGS):
	docker tag $(NS)/$(REPO):$(VERSION) $(NS)/$(REPO):$@

data-folder: $(DATA_FOLDER)

$(DATA_FOLDER):
	mkdir -p $(DATA_FOLDER)
