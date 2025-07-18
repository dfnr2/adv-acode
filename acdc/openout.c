/* openout.c (acdc) - copyleft @ M.L.Arnautov 1999.
 *
 * 18 Nov 01   MLA           Added the copyleft code for adv660, adv770.
 * 30 Sep 00   MLA           Simplified directory serach.
 * 07 Aug 99   MLA           Initial coding.
 *
 */

#include <stdio.h>
#include <string.h>

#include "acdc.h"
#include "source.h"

#ifdef __STDC__
FILE *openout (
   char *file,
   char *mode)
#else
FILE *openout (file, mode)
   char *file;
   char *mode;
#endif
{
   char *cptr;
   char *brk;
   char path_buf [80];
   char full_name [128];
   int try = 0;
   FILE *outfile;
   
   if (*source_stem == '\0')
      sprintf (full_name, "C%c%s", SEP, file);
   else
      sprintf (full_name, "%sC%c%s", source_stem, SEP, file);

   if ((outfile = fopen (full_name, mode)) == NULL)
   {      
      if (*source_stem == '\0')
         strcpy (full_name, file);
      else
         sprintf (full_name, "%s%s", source_stem, file);

      if ((outfile = fopen (full_name, mode)) == NULL)
      {
         gripe (file, "Unable to find");
         return (NULL);
      }
   }

   if (strncmp (source_file, "adv660", 6) || strncmp (source_file, "adv770", 6))
   {
      brk = file + strlen (file) - 2;
      if (*brk == '.' && (*(brk + 1) == 'c' || *(brk + 1) == 'h'))
      {
         strcpy (full_name, source_file);
         brk = strrchr (full_name, '.');
         if (brk) *brk = '\0';
         fprintf (outfile, "/* %s: %s - copyleft %s, %s.\n */\n", file,
            full_name, "Mike Arnautov", __DATE__);
      }
   }

   return (outfile);
}
