
include utils.mk

MAKE = make --no-print-directory

DIRS = lib $(wildcard ?) $(wildcard 1?)

all clean:
	@for i in $(DIRS); do         \
		$(call title,Making,$$i); \
		$(MAKE) -C $$i $@;        \
	done

