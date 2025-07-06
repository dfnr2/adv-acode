/* advkern.h - copyleft @ M.L.Arnautov 1990-1994 */

#include <setjmp.h>
#ifdef __STDC__
extern void say (int key, int what, int qualifier);
extern int query (int textref);
extern int special (int key, int var);
extern int ishere (int l1, int l2);
extern int isnear (int l1, int l2);
extern void apport (int l1, int l2);
extern void set (int l1, int l2, int l3);
extern void lda (int l1, int l2);
extern void eval (int l1, int l2);
extern void deposit (int l1, int l2);
extern void locate (int l1, int l2);
extern int evar (int l1);
extern short *bitword (int a1);
extern void bitmod (char a1, int a2, int a3);
extern int bitest (int a1, int a2);
extern void outchar (int text_char);
extern char *outline (char *addr, int char_count, int break_count, int fill);
extern void finita (void);
extern int irand (int less_then);
extern int have (int l1, int l2);
extern void flush_command (void);
extern void input (int textref);
extern void default_to (int key, int place, int type);
extern void voc (int word, int what, int test, int text);
extern int anyof (int first, ...);
extern int keyword (int first, ...);
extern void move (int a1, int a2, ...);
extern void tie (int text, int holder);
extern void svar (int type, int var);
#else
extern void say ();
extern int query ();
extern int special ();
extern int ishere ();
extern int isnear ();
extern void apport ();
extern void set ();
extern void lda ();
extern void eval ();
extern void deposit ();
extern void locate ();
extern int evar ();
extern short *bitword ();
extern void bitmod ();
extern int bitest ();
extern void outchar ();
extern char *outline ();
extern void finita ();
extern int irand ();
extern int have ();
extern void flush_command ();
extern void input ();
extern void default_to ();
extern void voc ();
extern int anyof ();
extern int keyword ();
extern void move ();
extern void tie ();
extern void svar ();
#endif
extern jmp_buf loop_back;
extern int value[];
extern int location[];
extern short objbits[];
extern short placebits[];
extern short varbits[];
extern void (*procs[])();
#include "autod1.h"
#ifdef ALL
extern int value_all;
#endif
