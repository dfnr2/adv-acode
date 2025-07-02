/* minor.h (acdc) - copyleft @ M.L.Arnautov 1990-2001.
 *
 * 17 May 01   MLA           Added FAKECOM.
 * 16 Mar 01   MLA           Added IFANY.
 * 05 Mar 01   MLA           Added FAKEARG.
 * 28 Feb 01   MLA           Added TIE.
 * 08 Aug 00   MLA           Added OTHERWISE.
 * 15 Sep 90   MLA           Initial coding.
 *
 */

# define IFEQ 1
# define IFLT 2
# define IFGT 3
# define IFAT 4
# define IFHAVE 5
# define IFNEAR 6
# define IFHERE 7
# define IFLOC 8
# define IFIS 9
# define IFINRANGE 10
# define IFKEY 11
# define IFANY 12
# define IFFLAG 13
# define CHANCE 14
# define QUERY 15

# define NOT 20
# define AND 21
# define OR 22
# define XOR 23

# define ELSE 31
# define FIN 32
# define EOT 33
# define OTHERWISE 34

# define KEYWORD 40
# define HAVE 41
# define NEAR 42
# define HERE 43
# define ATPLACE 44
# define ANYOF 45

# define ITOBJ 51
# define ITPLACE 52
# define ITERATE 53
# define EOI 54

# define EXEC 55
# define FAKEARG 56
# define FAKECOM 57

# define CALL 61
# define PROCEED 62
# define QUIT 63
# define STOP 64

# define GOTO 71
# define MOVE 72
# define SMOVE 73

# define SAY 81
# define VALUE 82
# define QUIP 83
# define DICT 84

# define FLAG 91
# define UNFLAG 92
# define SVAR 93
# define INPUT 94
# define DEFAULT 95
# define SET 96
# define DOALL 97
# define FLUSH 98

# define ADD 101
# define SUBTRACT 102
# define MULTIPLY 103
# define DIVIDE 104
# define NEGATE 105
# define RANDOM 106
# define CHOOSE 107
# define RANDOMISE 108
# define LDA 109
# define EVAL 110
# define DEPOSIT 111
# define INTERSECT 112
# define TIE 113

# define GET 121
# define DROP 122
# define APPORT 123
# define LOCATE 124
