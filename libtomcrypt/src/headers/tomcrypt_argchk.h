/* Defines the LTC_ARGCHK macro used within the library */
/* ARGTYPE is defined in mycrypt_cfg.h */
#if ARGTYPE == 0

#include <signal.h>

/* portability macros for compiler-specific code attributes */
#ifdef __GNUC__
#define ATTRIB_NORETURN __attribute__((noreturn))
#else
#define ATTRIB_NORETURN
#endif


/* this is the default LibTomCrypt macro  */
void crypt_argchk(char *v, char *s, int d) ATTRIB_NORETURN;
#define LTC_ARGCHK(x) if (!(x)) { crypt_argchk(#x, __FILE__, __LINE__); }
#define LTC_ARGCHKVD(x) LTC_ARGCHK(x)

#elif ARGTYPE == 1

/* fatal type of error */
#define LTC_ARGCHK(x) assert((x))
#define LTC_ARGCHKVD(x) LTC_ARGCHK(x)

#elif ARGTYPE == 2

#define LTC_ARGCHK(x) if (!(x)) { fprintf(stderr, "\nwarning: ARGCHK failed at %s:%d\n", __FILE__, __LINE__); }
#define LTC_ARGCHKVD(x) LTC_ARGCHK(x)

#elif ARGTYPE == 3

#define LTC_ARGCHK(x) 
#define LTC_ARGCHKVD(x) LTC_ARGCHK(x)

#elif ARGTYPE == 4

#define LTC_ARGCHK(x)   if (!(x)) return CRYPT_INVALID_ARG;
#define LTC_ARGCHKVD(x) if (!(x)) return;

#endif


/* $Source$ */
/* $Revision$ */
/* $Date$ */
