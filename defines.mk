ROOT:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
PLATFORM:=$(shell $(ROOT)/systype.sh)
include $(ROOT)/defines.$(PLATFORM).mk
