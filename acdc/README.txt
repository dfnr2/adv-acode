                   acdc  -  an A-code to C translator
                   ==================================

The acdc utility is used to translate A-code source of an adventure into
a compilable C source (.acd -> .c == acdc  :-).  The translated code
(the autop<n>.c and autod<n>.h files, where <n> is a number from 0 upwards)
needs to be compiled and linked with the supplied adventure kernel
sources (advkern.c and advkern.h) into an executable game. 

The translated code is created in the same directory in which the A-code
source is specified, except that if that directory contains a
subdirectory called C, the translated C code is placed there.

A makefile is provided for use on Unix, but you can simply compile and
link all .c modules in this directory.

The acdc command line takes a number of optional arguments:

(path)name     This is the name (or pathname) of the principal A-code
               source file. All includes specified by this file are
               taken to be relative to its location. If not supplied,
               the (path)name is prompted for. The ".acd" suffix may
               be omitted.

-headers       Adds to the generated C source comment lines at the
               beginning of each procedure, identifying it by its
               A-code identity,

-source        Adds to the generated C source comment lines showing
               the A-code source being processed.

-trace         Causes "headers" identification to be displayed at
               runtime.

-debug         Equivalent to "-headers -source -trace"

Alternatively, if the environmental variable DEBUG is set, "-headers
-source -trace" is assumed. 

(Note that this version of acdc lacks the ability to encrypt the
game database it creates -- it is intended solely for processing
publicly available A-code sources.)

The resulting C sources are written into the sub-directory C of the
A-code source directory, if such sub-directory exists, or in its
absence, into the source directory itself. 

The acdc translator was developed in order to port Adventure4+ (a.k.a. 
Adv660) to DOS, when the "munger" approach taken over from Adv550,
started to creak even on large (at the time!) multi-user machines. My
solution was to drop the idea of creating a psudo-binary which then got
interpreted by an "executive", and to go the whole hog instead:
translate A-code into compilable C.

In developing acdc, I took the opportunity to extend further the A-code
functionality. Some new directives, like IFINRANGE and IFIS, were added
to the A-code munger/executive in merging Adventure 550 with Adventure
II. Further additions (e.g. the TIE directive, nested texts and
implicit text qualifiers) appeared as the result of later work on
adv770. 


                                           Mike Arnautov
                                           mla@britishlibrary.net
                                           04 Jan 2002
