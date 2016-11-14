ENV_FILE ?= Makefile_env.inc

ifneq ("$(wildcard $(ENV_FILE))","")
include $(ENV_FILE)
endif

NS = elvido
VERSION ?= 3.4
TAGS ?= latest

REPO = alpine-abuild
NAME = alpine-abuild
INSTANCE = default


.PHONY: secret-save secret-remove build push shell run start stop rm release tag $(TAGS) 

default: build

build:
	docker build -t $(NS)/$(REPO):$(VERSION) .
 
push:
	docker push $(NS)/$(REPO):$(VERSION)

shell:
	docker run --rm --name $(NAME)-$(INSTANCE) --entrypoint /bin/sh -i -t $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION) 

run: $(PACKAGER_KEY)
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

ifdef SECRET_SET
secret-save:
	$(SECRET_SET)
endif

ifdef SECRET_DEL
secret-remove:
	$(SECRET_DEL)
endif

ifdef PACKAGER_KEY
$(PACKAGER_KEY): $(PACKAGER_CRT)
ifdef SECRET_GET
	$(SECRET_GET) | openssl rsa -in $< -passin stdin -pubout -outform PEM -out $@
else
	openssl rsa -in $< -pubout -outform PEM -out $@
endif
endif
