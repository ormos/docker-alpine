ENV_FILE ?= Makefile_env.inc

ifneq ("$(wildcard $(ENV_FILE))","")
include $(ENV_FILE)
endif

NS = ormos
VERSION ?= 3.9
TAGS ?= latest

REPO = alpine-dops
NAME = alpine-dops
INSTANCE = default

XSHELL ?= /bin/zsh

.PHONY: build push shell run start stop rm release tag $(TAGS) assets

default: build

build:
	docker build -t $(NS)/$(REPO):$(VERSION) .

push:
	docker push $(NS)/$(REPO):$(VERSION)

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

release: build
	@make --no-print-directory tag -e VERSION="$(VERSION)" -e TAGS="$(TAGS)"
	@make --no-print-directory push -e VERSION="$(VERSION)"

tag: $(TAGS)

$(TAGS):
	docker tag $(NS)/$(REPO):$(VERSION) $(NS)/$(REPO):$@

assets:
	mkdir -p rootfs/root/.vim/colors
	curl -jkSL -# -o rootfs/root/.vim/colors/monokai.vim https://raw.githubusercontent.com/sickill/vim-monokai/master/colors/monokai.vim
