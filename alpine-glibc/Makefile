ENV_FILE ?= Makefile_env.inc

ifneq ("$(wildcard $(ENV_FILE))","")
include $(ENV_FILE)
endif

NS = elvido
VERSION ?= 3.5
TAGS ?= latest

REPO = alpine-glibc
NAME = alpine-glibc
INSTANCE = default

GLIBC_VERSION ?= 2.25
GLIBC_PREFIX  ?= /usr/glibc-compat
GLIBC_ARCH	  ?= x86_64
GLIBC_RELEASE ?= glibc-releases/alpine-glibc-$(GLIBC_VERSION)-$(GLIBC_ARCH).tgz
GLIBC_BUILDER = $(NS)/glibc-builder

.PHONY: build push shell run start stop rm release tag $(TAGS) build-glibc

default: build

build:
	docker build -t $(NS)/$(REPO):$(VERSION) .

push:
	docker push $(NS)/$(REPO):$(VERSION)

shell:
	docker run --rm --name $(NAME)-$(INSTANCE) -i -t $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION) /bin/sh

run:
	docker run --rm --name $(NAME)-$(INSTANCE) $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION)

start:
	docker run -d --name $(NAME)-$(INSTANCE) $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION)

stop:
	docker stop $(NAME)-$(INSTANCE)

rm:
	docker rm $(NAME)-$(INSTANCE)

release: build
	@make --no-print-directory tag -e VERSION="$(VERSION)" -e TAGS="$(TAGS)"
	@make --no-print-directory push -e VERSION="$(VERSION)"

tag: $(TAGS)

$(TAGS):
	docker tag $(NS)/$(REPO):$(VERSION) $(NS)/$(REPO):$@

build-glibc:
	docker build -t $(GLIBC_BUILDER) builder
	docker run --rm $(GLIBC_BUILDER) -S -r $(GLIBC_VERSION) -a $(GLIBC_ARCH) -p $(GLIBC_PREFIX) \
        > $(GLIBC_RELEASE)
	docker rmi $(GLIBC_BUILDER)
