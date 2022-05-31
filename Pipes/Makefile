CFLAGS=-g
CC=gcc
LDLIBS=-lncurses -lpthread

SUBDIRS= ipc
SUBCLEAN=$(addsuffix .clean,$(SUBDIRS))
PROGS=
ALL=$(SUBDIRS) $(PROGS)

ALL:$(ALL)

$(SUBDIRS):
	$(MAKE) -C $@ -f Makefile

.PHONY: clean $(SUBCLEAN) $(SUBDIRS)
clean: $(SUBCLEAN)
	\rm -rf $(PROGS) *.o

$(SUBCLEAN): %.clean:
	$(MAKE) -C $* -f Makefile clean

