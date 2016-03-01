
include utils.mk

MAKE = make --no-print-directory

DIRS = lib 1 2 3 4

all clean:
	@for i in $(DIRS); do         \
		$(call title,Making,$$i); \
		$(MAKE) -C $$i $@;        \
	done

