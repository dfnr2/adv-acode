This A-code bundle contains A-code sources of adv550 and adv660, plus
the tools for creating playable games out of these sources. The bundle
is supplied as a single directory ACODE, which contains:

README.txt    this file
adv550        directory containing A-code source of Dave Platt's adv550;
              (NB this is the original DP source, with text switches and
              pre-formatted texts, omitted in other ditributions).
adv660        directory containing the A-code source of my superset of
              Luckett's and Pike's adv440 and Dave Platt's adv550 
acdc          directory containing the source of the acdc translator for
              converting A-code source into a database file and ANSI C code
kernel        directory containing A-code kernel, which needs to be compiled
              and linked with the C code create by acdc, into an executable
              game.

To build the acdc translator, cd to the acdc directory, and compile and
link all C sources found therein, to create the acdc executable.

To derive a playable game from an A-code source, run the acdc
translator, giving it as its command line argument the (path)name of the
main file of the A-code source (by convention, this file has the name
of the game, suffixed with .acd -- e.g. adv550.acd). This will create
several C source files, all prefixed with 'auto', and one database file
suffixed with .dat. (By default all these files will be created in the 
same directory as the A-code source.)

Copy the kernel source files (advkern.c and advkern.h) to the same
directory as the files created by the translator, and compile and link
the lot into an executable. You now have a playeable game.

If you have an implementation of the Glk library, you can create a Glk
version of the game by supplying -DGLK on the compilation command line
and linking in the Glk library. Glk startup function is included in the
kernel for Unix/Linux and Windows. On other platforms, you will need to
supply your own. 


                                        Mike Arnautov
                                        mla@britishlibrary.net
                                        04 Jan 2002
