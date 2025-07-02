CC = /opt/local/bin/gcc
ifdef DEBUG
   CFLAGS = -g -DDEBUG
else
   CFLAGS =
endif

ACDCOBJ = acdc.o \
	  addsymb.o \
	  chrtobin.o \
	  clsfile.o \
	  dominor.o \
	  domajor.o \
	  doswitch.o \
	  finalise.o \
	  fndsymb.o \
	  getconst.o \
	  getdesc.o \
	  getline.o \
	  getnames.o \
	  gettext.o \
	  gettoken.o \
	  gripe.o \
	  initial.o \
	  openfrst.o \
	  openout.o \
	  organise.o \
	  opnsrc.o \
	  parse.o \
	  recase.o \
	  storchar.o \
	  storword.o \
	  tsearch.o

acdc:       $(ACDCOBJ)
	    $(CC) $^ -o acdc

clean:      
	    rm -f *.o

acdc.o:     acdc.c acdc.h const.h line.h source.h major.h symbol.h \
	    text.h output.h
addsymb.o:  addsymb.c acdc.h symbol.h
chrtobin.o: chrtobin.c acdc.h
clsfile.o:  clsfile.c acdc.h
domajor.o:  domajor.c acdc.h const.h line.h symbol.h major.h source.h \
	    text.h output.h
dominor.o:  dominor.c acdc.h line.h const.h symbol.h minor.h major.h \
            text.h output.h
doswitch.o: doswitch.c acdc.h text.h
finalise.o: finalise.c acdc.h text.h search.h symbol.h output.h major.h const.h
fndsymb.o:  fndsymb.c acdc.h symbol.h const.h
getconst.o: getconst.c acdc.h symbol.h const.h major.h
getdesc.o:  getdesc.c acdc.h const.h line.h symbol.h text.h
getline.o:  getline.c const.h line.h source.h output.h
getnames.o: getnames.c acdc.h const.h line.h symbol.h major.h text.h
gettext.o:  gettext.c acdc.h const.h line.h symbol.h major.h text.h
gettoken.o: gettoken.c 
gripe.o:    gripe.c const.h line.h source.h
initial.o:  initial.c acdc.h const.h minor.h major.h line.h source.h \
	    symbol.h text.h output.h 
openfrst.o: openfrst.c source.h 
openout.o:  openout.c acdc.h source.h 
opnsrc.o:   opnsrc.c acdc.h const.h line.h source.h
organise.o: organise.c acdc.h search.h const.h symbol.h major.h text.h \
	    output.h source.h 
parse.o:    parse.c acdc.h const.h line.h symbol.h major.h 
recase.o:   recase.c const.h 
storchar.o: storchar.c text.h
storword.o: storword.c acdc.h symbol.h text.h const.h 
tsearch.o:  tsearch.c


