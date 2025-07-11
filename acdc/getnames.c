/* getnames.c (acdc) - copyleft @ M.L.Arnautov 1990-1999.
 *
 * 24 Jul 99   MLA           Fixed complier warnings.
 * 16 Mar 91   MLA           Suppress used count for . prefix.
 * 30 Dec 90   MLA           Use voc_buf for intermediate vocab storage.
 * 15 Sep 90   MLA           Initial coding.
 *
 */

#include "acdc.h"
#include "const.h"
#include "line.h"
#include "symbol.h"
#include "major.h"
#include "text.h"

#ifdef __STDC__
struct node *getnames (int major_type, struct node *gp)
#else
struct node *getnames (major_type, gp)
int major_type;
struct node *gp;
#endif
{
   int index;
   int prefix;
   int current_type;
   int refno;
   int used;
   long last_addr;
   struct node *np;
   extern void storword ();

   if (*tp [1] == '=')
      (void) gripe (tp [1], "No preceding word to equate to!");
   index = 0;
   current_type = major_type;
   np = gp;

   if (np == NULL)
      refno = type_counts [major_type]++;
   else
   {
      index = 1;
      refno = np -> refno;
      last_addr = np -> body.vocab.word_addr;
   }

   while (tp [++index] != NULL)
   {
      prefix = *tp [index];
      if ((used = (prefix == '.')))
         tp [index]++;
      if (prefix == '+' ||prefix == '-' || prefix == '=' || prefix == '!')
         tp [index]++;
      else
         prefix = (major_type == PLACE) ? '-' : '+';

      if (index == 1)
      {
         np = addsymb (SYMBOL, tp [index], current_type, refno);
         if (used)
            np -> used_count = 1;
         if (prefix != '-')
            np -> body.text.name_addr = next_vocaddr;
         else
            return (np);
      }

      if (prefix == '!') tp [index]--;
      current_type = SYNONYM;

      if (prefix == '=')
         (void) storword (tp [index], major_type, refno, last_addr);
      else
      {
         last_addr = next_vocaddr;
         (void) storword (tp [index], major_type, refno, next_vocaddr);
      }
   }

   return (np);
}
