/* acdc.h (acdc) - copyleft @ M.L.Arnautov 1990-2001.
 */

#ifdef __STDC__
extern int getline (int key);
extern void gripe (char *error_token, char *error_message);
extern int gettext (int description, int *max_states, int fragment);
extern void storchar (int ch);
extern void doswitch (char *text_ptr, int *max_states);
#ifdef EOF
   extern FILE *openout(char *name, char *mode);
   extern void openfrst (char *file_spec);
#endif /* EOF */
#else  /* ! __STDC__ */
extern int getline ();
extern void gripe ();
extern int gettext ();
extern void storchar ();
extern void doswitch ();
#ifdef EOF
   extern FILE *openout ();
   extern void openfrst ();
#endif /* EOF */
#endif /* ! __STDC__ */
