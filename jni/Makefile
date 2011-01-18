CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld

DEF=-DFLVSTREAMER_VERSION=\"v2.1c1\"
OPT=-O2
CFLAGS=-Wall $(XCFLAGS) $(INC) $(DEF) $(OPT)
LDFLAGS=-Wall $(XLDFLAGS)
LIBS=
THREADLIB=-lpthread
SLIBS=$(THREADLIB) $(LIBS)

EXT=

all:
	@echo 'use "make posix" for a native Linux/Unix build, or'
	@echo '    "make mingw" for a MinGW32 build'
	@echo 'use commandline overrides if you want anything else'

progs:	flvstreamer streams rtmpsrv rtmpsuck

posix linux unix osx:
	@$(MAKE) $(MAKEFLAGS) progs

mingw:
	@$(MAKE) CROSS_COMPILE=mingw32- LIBS="$(LIBS) -lws2_32 -lwinmm -lgdi32" THREADLIB= EXT=.exe $(MAKEFLAGS) progs

cygwin:
	@$(MAKE) XCFLAGS=-static XLDFLAGS="-static-libgcc -static" EXT=.exe $(MAKEFLAGS) progs

cross:
	@$(MAKE) CROSS_COMPILE=armv7a-angstrom-linux-gnueabi- INC=-I/OE/tmp/staging/armv7a-angstrom-linux-gnueabi/usr/include $(MAKEFLAGS) progs

clean:
	rm -f *.o flvstreamer$(EXT) streams$(EXT) rtmpsrv$(EXT) rtmpsuck$(EXT)

flvstreamer: log.o rtmp.o amf.o flvstreamer.o parseurl.o
	$(CC) $(LDFLAGS) $^ -o $@$(EXT) $(LIBS)

rtmpsrv: log.o rtmp.o amf.o rtmpsrv.o thread.o
	$(CC) $(LDFLAGS) $^ -o $@$(EXT) $(SLIBS)

rtmpsuck: log.o rtmp.o amf.o rtmpsuck.o thread.o
	$(CC) $(LDFLAGS) $^ -o $@$(EXT) $(SLIBS)

streams: log.o rtmp.o amf.o streams.o parseurl.o thread.o
	$(CC) $(LDFLAGS) $^ -o $@$(EXT) $(SLIBS)

log.o: log.c log.h Makefile
parseurl.o: parseurl.c parseurl.h log.h Makefile
streams.o: streams.c rtmp.h log.h Makefile
rtmp.o: rtmp.c rtmp.h log.h amf.h Makefile
amf.o: amf.c amf.h bytes.h log.h Makefile
flvstreamer.o: flvstreamer.c rtmp.h log.h amf.h Makefile
rtmpsrv.o: rtmpsrv.c rtmp.h log.h amf.h Makefile
thread.o: thread.c thread.h
