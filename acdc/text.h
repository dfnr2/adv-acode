/* text.h (acdc) - copyleft @ M.L.Arnautov 1990-2001.
 *
 * 25 Nov 01   MLA           Added IGNORE_EOL.
 * 06 Oct 01   MLA           Added text_count and switch_count.
 * 14 Mar 01   MLA           Moved style definition to here frmo source.h.
 * 28 Feb 01   MLA           Added in-text Dwarvish. Added text types.
 * 06 Jan 01   MLA           Added CENTER_START.
 * 11 Dec 99   MLA           Added block and tag delimiters, and hard-space.
 * 31 Dec 98   MLA           Doubled VOC_INIT_LEN.
 * 30 Dec 90   MLA           Added voc_buf necesseries.
 * 15 Sep 90   MLA           Initial coding.
 *
 */

#ifndef FILE
#include <stdio.h>
#endif

#ifdef __STDC__
extern void clsfile (FILE *outfile, char *text);
#else
extern void clsfile ();
#endif

#define TEXT_INIT_LEN  8192
#define LOGICAL_ESCAPE '\\'
#define SWITCH_START   '['
#define SWITCH_BREAK   '/'
#define SWITCH_END     ']'
#define NEST_START     '{'
#define NEST_END       '}'
#define DWARVISH_TAG   '%'
#define MAX_BREAKS     100
#define SW_START     '\377'
#define SW_BREAK     '\376'
#define HOLDER       '\375'
#define SILENCE      '\374'
#define IGNORE_EOL   '\373'
#define NEST_TEXT    '\372'
#define NEST_VAR     '\371'  
#define TAG_START    '\370'
#define TAG_END      '\367'
#define NBSP         '\366'
#define BLOCK_START  '\365'
#define BLOCK_END    '\364'
#define CENTRE_START '\363'
#define DWARVISH     '\362'

#define RANDOM_TEXT       1
#define INCREMENTAL_TEXT  2
#define CYCLIC_TEXT       3
#define ASSIGNED_TEXT     4
#define TIED_TEXT         5

extern long next_addr;
extern char *text_buf_ptr;
extern int text_buf_len;
extern FILE *text_file;
extern char dbname[];
extern char *dbname_ptr;
extern int plain_text;
extern int style;
extern int text_count;
extern int switch_count;

#define VOC_INIT_LEN 8192
extern long next_vocaddr;
extern char *voc_buf_ptr;
extern int voc_buf_len;
extern char *voc_ptr;
extern char *voc_top;
