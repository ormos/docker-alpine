# configuration parameters
HOST_PORT:=8089
HOST_IP:=$(shell ip route get 8.8.8.8 | head -1 | cut -d' ' -f8)

ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

# docker options
PORTS = -p $(HOST_PORT):80
  