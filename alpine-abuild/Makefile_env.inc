# configuration parameters
ROOT_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

PACKAGER := YaaS Alpine Package Publisher

PACKAGER_CRT := YaaS-Alpine_Package_Publisher.crt
PACKAGER_KEY := YaaS-Alpine_Package_Publisher.key
PACKAGER_RSA := YaaS-Alpine_Package_Publisher.rsa

# requires libsecret-tools is installed
SECRET_SET := secret-tool store --label="$(PACKAGER)" name "$(PACKAGER)" certificate "$(PACKAGER_CRT)"
SECRET_GET := secret-tool lookup name "$(PACKAGER)" certificate "$(PACKAGER_CRT)"
SECRET_DEL := secret-tool clear name "$(PACKAGER)" certificate "$(PACKAGER_CRT)"

ifdef SECRET_GET
PACKAGER_PRIVATE_KEY_DATA := $(shell $(SECRET_GET) | openssl rsa -in $(PACKAGER_CRT) -passin stdin -outform PEM) 
else
PACKAGER_PRIVATE_KEY_DATA := $(shell openssl rsa -in $(PACKAGER_CRT) -outform PEM) 
endif

VOLUMES = \
  -v $(PWD):/home/builder/package \
  -v $(PWD)/packages:/packages \
  -v $(ROOT_DIR)/$(PACKAGER_KEY):/home/builder/.abuild/$(PACKAGER_KEY)

ENV = \
  -e PACKAGER_PRIVATE_KEY_NAME="$(PACKAGER_RSA)" \
  -e PACKAGER_PRIVATE_KEY_DATA="$(PACKAGER_PRIVATE_KEY_DATA)" 
