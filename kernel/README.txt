                           The A-code kernel
                           =================

The A-code kernel consists of the two source files advkern.c and
advkern.h, which need to be compiled together with the C sources
generated from A-code by the acdc translator. 

Please note that this version of the A-code kernel is provided
specifically for the purpose of building executables from publicly
available source-code, and hence lacks all database decryption code.

On Unix/Linux, the resulting game executable can take a number of
command line arguments:

 -w                inverts the default wrap/justify setting of the game.
                   In wrap mode, text is simply broken into lines
                   according to the screen width (see the -s keyword).
                   With justification turned on, each line is right-
                   justified. All of this pre-suppose a fixed font
                   being in use. For variable font devices, which tend
                   to do their own wrapping, the default screen width
                   should be set to zero, meaning "infinite", and the
                   margin should be specified as zero too. This keyword
                   is suppressed if the GLK symbol is defined

 -b                inverts the default setting for blank lines around
                   the '?' prompt line. In old-style A-code, which does 
                   not distinguish between replies to queries and general
                   commands, this only affects presence/absence of
                   a blank line after the prompt line, and never before it.

 -s <H>x<W>[-<M>]  set screen size (height in lines, width in fixed font
                   characters, and margin (in fixed font blanks).
                   The default screen dimension is 24x80 with the margin
                   being set to 1 character. The -s keyword allows a
                   different screen size (and optionally margin) to be 
                   specified. Screen width of zero means "infinite" width.
                   Note that the line length cannot be set to less than
                   16 characters and the minimal number of lines per
                   screen is 5. This keyword is suppressed if the GLK
                   symbol is defined.

 -d <dbsdir>       specify dbs directory.
                   By default, the game database is assumed to live in
                   the same directory as the executable. The -d keyword
                   allows a separate location to be specified. The
                   program will attempt to work out the separator
                   which should follow the directory name, but if in doubt
                   as to the appropriate one for the given platform,
                   the dbs name will be simply concatenated with the
                   supplied pathname -- hence if it doesn't work, try
                   adding the trailing separator to the pathname.

 [-r] <dumpfile>   restore game from dump.
                   The -r keyword is optional in that any command line
                   argument which is not a keyword and is not associated
                   with a preceding keyword, will be taken as the name
                   of the dumpfile to restore on invocation. The default
                   behaviour is to prompt the user whether a dumped game
                   is to be restored.

 -c <cominfile>    replay game from log.
                   This is a debugging tool, which allows a game to be
                   replayed from a log file (see below). If the logfile
                   contains more than one session log, only the first
                   session will be replayed. The log contains the value
                   of the random seed used in the session, thereby
                   ensuring that the game is replayed exactly, despite
                   any randomisation. [NB, this may not in fact work!]

 -l <logfile>      log the game
                   Specifies the file into which a session log is to 
                   be written. The log is human-readable, but has some
                   additional features allowing it to be used subsequently
                   for replaying the session. If the nominated logfile
                   already exists, it gets appended to.

 -h                print command line usage summary.

The  functionality of the -s and -w keywords is also provided via kernel
hooks (see procedure special() in advkern.c), so that the game may -- at
author's  discretion  --  offer  the  player  commands  for toggling the
justification switch and altering screen size and margin. 

In addition, the kernel source has some conditional compilation switches 
and its behaviour can be altered by defining the following symbols:

GLK              Causes the object files to be Glk-instrumented, ready
                 to be linked with a Glk library implementation.
                 If defined, this symbol suppresses the -j and the -s
                 text formatting command line options.

MSDOS            If defined, various MSDOS-ish restrictions apply
                 on save file name.

JUSTIFY          Specifies that right-justifying text should be the
                 game default. The default default is to wrap text.
                 The -j command line keyword can be used to override
                 either setting. This symbol is ignored if the GLK
                 symbol is defined.

COMPRESS         Specifies that the game default should be to suppress
                 blank lines around the '?' prompt lines. This is the
                 default for games written in old-style A-code. Blank
                 lines are the default in games using A-code style 10
                 or higher. Either setting can be overridden by the
                 -b command line keyword.

PAUSE            Specifies that the game should pause before exiting.
                 This is the default on MS platforms, unless the GLK
                 symbol is defined. The default presence/absence of
                 the pause can be overridden by the -p command line
                 keyword.

MEMORY, BUFFERS, LOC_STATS       
                 These symbols may be present in the source code but
                 are of no significance to this version of the kernel,
                 which can only handle plaintext databases, and reads
                 database files fully into memory.

Any other symbols used in the kernel source are there for the internal
use by the game itself (one of the automatically generated include files
being included by the kernel), or for development/debugging purposes.


                                     Mike Arnautov
                                     mla@britishlibrary.net
                                     04 Jan 2002
