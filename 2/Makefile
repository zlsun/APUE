include ../defines.mk

PROGS = conf options

all: $(PROGS)

conf: conf.o
conf.o: conf.c conf.h print.h

conf.h: make.py sysconf.sym pathconf.sym
	$(PYTHON) $^ > $@

sysconf.sym: sysconf-lim.sym
	grep -v "^#" $< > $@

pathconf.sym: pathconf-lim.sym
	grep -v "^#" $< > $@

options: options.o
options.o: options.c options.h print.h

options.h: make.py sysopt.sym pathopt.sym
	$(PYTHON) $^ > $@

sysopt.sym: sysconf-opt.sym
	grep -v "^#" $< > $@

pathopt.sym: pathconf-opt.sym
	grep -v "^#" $< > $@

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o conf.h options.h \
		pathconf.sym pathopt.sym sysconf.sym sysopt.sym

