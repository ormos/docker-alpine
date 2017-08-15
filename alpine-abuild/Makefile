ENV_FILE ?= Makefile_env.inc

ifneq ("$(wildcard $(ENV_FILE))","")
include $(ENV_FILE)
endif

NS = elvido
VERSION ?= 3.6
TAGS ?= latest

REPO = alpine-abuild
NAME = alpine-abuild
INSTANCE = default

XSHELL ?= /bin/shell

.PHONY: secret-save secret-remove build push shell run start stop clean release tag $(TAGS) 

default: build

build:
	docker build -t $(NS)/$(REPO):$(VERSION) .
 
push:
	docker push $(NS)/$(REPO):$(VERSION)

shell: $(PACKAGER_KEY) $(PACKAGER_RSA)
	docker run --rm --name $(NAME)-$(INSTANCE) --entrypoint /bin/sh -i -t $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION) 
	$(PACKAGER_RSA_RELEASE)

run: $(PACKAGER_KEY) $(PACKAGER_RSA)
	-docker run --rm --name $(NAME)-$(INSTANCE) $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION) build
	$(PACKAGER_RSA_RELEASE)

release: build
	@make --no-print-directory tag -e VERSION="$(VERSION)" -e TAGS="$(TAGS)"
	@make --no-print-directory push -e VERSION="$(VERSION)"

clean:
	$(PACKAGER_RSA_RELEASE)
	$(PACKAGER_KEY_RELEASE)

tag: $(TAGS)

$(TAGS):
	docker tag $(NS)/$(REPO):$(VERSION) $(NS)/$(REPO):$@

ifdef PACKAGER_RSA
$(PACKAGER_RSA): $(PACKAGER_CRT)
	$(PACKAGER_RSA_RETRIEVE) >$@
endif

ifdef PACKAGER_KEY
$(PACKAGER_KEY): $(PACKAGER_CRT)
	$(PACKAGER_KEY_RETRIEVE) >$@
endif

ifdef SECRET_SET
secret-save:
	$(SECRET_SET)
endif

ifdef SECRET_DEL
secret-remove:
	$(SECRET_DEL)
endif
