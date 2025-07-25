/* openfrst.c (acdc) - copyleft @ M.L.Arnautov 1999.
 *
 * 17 Nov 01   MLA           Bug: Fixed pathname code.
 * 06 Nov 01   MLA           bug: Display correctly what file not found.
 * 30 Sep 00   MLA           Removed searching for adv_src.
 * 07 Aug 99   MLA           Initial coding.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef __50SERIES
#include <errno.h>
#endif

#include "source.h"
char source_stem [MAXLINE + 1];
char source_file [32];

#ifdef __STDC__
void openfrst (char *file_spec)
#else
void openfrst (file_spec)
   char *file_spec;
#endif
{
   char *nameptr = file_spec;
   char *sfxptr = NULL;
   char fullname [128];
   
   if (nameptr = strrchr (file_spec, SEP))
   {
      int len;
      *nameptr++ = '\0';
      len = strlen (file_spec);
      strncpy (source_stem, file_spec, sizeof (source_stem));
      *(source_stem + len++) = SEP;
      *(source_stem + len) = '\0';
   }
   else
   {
      nameptr = file_spec;
      *source_stem = '\0';
   }      
   strncpy (source_file, nameptr,  sizeof (source_file) - 5);  
      
   sfxptr = strrchr (source_file, '.');
   if (sfxptr == NULL || strcmp (sfxptr + 1, "acd") != 0)
      strcat (source_file, ".acd");
   
   sprintf (fullname, "%s%s", source_stem, source_file);
   if ((*infile = fopen (fullname, "r")) != NULL)
   {
      strcpy (pathname [0], fullname);
      level = 0;
      return;
   }

   fprintf (stderr, "Sorry, cannot find source file %s.\n", fullname);
   exit (1);
}
