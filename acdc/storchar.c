/* storchar.c (acdc) - copyleft @ M.L.Arnautov 1990-2001.
 *
 * 17 Nov 01   MLA           Removed encryption code for public release.
 * 24 Jul 99   MLA           Fixed complier warnings.
 * 15 Sep 90   MLA           Initial coding.
 *
 */

#include "text.h"

#ifdef __STDC__
void storchar (int ch)
#else
void storchar (ch)
int ch;
#endif
{
   fputc(ch, text_file);
   next_addr++;
   return;
}
