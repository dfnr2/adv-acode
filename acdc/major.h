/* major.h (acdc) - copyleft @ M.L.Arnautov 1990-2001.
 *
 * 14 Mar 01   MLA           Added STYLE directive.
 * 31 Dec 98   MLA           Added ARRAY type. 
 * 15 Sep 90   MLA           Initial coding.
 *
 */

#define OBJECT 0
#define PLACE 1
#define VERB 2
#define VARIABLE 3
#define TEXT 4
#define PROCEDURE 5
#define CONSTANT 6
#define FLAGS 7
#define STATE 8
#define FRAGMENT 9
#define ARRAY 10
#define MAXTYPES CONSTANT   /* The rest are compilation directives */
#define ACTION 21
#define AT 22
#define INIT 23
#define REPEAT 24
#define NOISE 25
#define LIST 26
#define NOLIST 27
#define INCLUDE 28
#define SYNONYM 29
#define DBNAME 30
#define DEFINE 31
#define STYLE 32
