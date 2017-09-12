#ifndef _CONFIG_H_
#define _CONFIG_H_

/* UTF8 BF~=PNOB */
#define UTF8_INPUT_ENABLE
#define UTF8_OUTPUT_ENABLE

/* Shift_JIS BHO0O30$NJ8;z$r!"BCP932 B$GF1CM$JJ8;z$KFI$_49$($kB */
#define SHIFTJIS_CP932

/* B%*%W%7%g%s$GF~NO$r;XDj$7$?;~$K!"J8;z%3!<%I$r8GDj$9$kB */
#define INPUT_CODE_FIX

/* --overwrite B%*%W%7%g%sB */
/* by Satoru Takabayashi <ccsatoru@vega.aichi-u.ac.jp> */
#define OVERWRITE

/* --cap-input, --url-input B%*%W%7%g%sB */
#define INPUT_OPTION

/* --numchar-input B%*%W%7%g%sB */
#define NUMCHAR_OPTION

/* --debug, --no-output B%*%W%7%g%sB */
#define CHECK_OPTION

/* JIS X0212 */
#define X0212_ENABLE

/* --exec-in, --exec-out B%*%W%7%g%sB
 * pipe, fork, execvp B$"$?$j$,L5$$$HF0$-$^$;$s!#B
 * MS-DOS, MinGW B$J$I$G$OB undef B$K$7$F$/$@$5$$B
 * child process B=*N;;~$N=hM}$,$$$$$+$2$s$J$N$G!"B
 * B%G%U%)%k%H$GL58z$K$7$F$$$^$9!#B
 */
/* #define EXEC_IO */

/* SunOS B$NB cc B$r;H$&$H$-$OB undef B$K$7$F$/$@$5$$B */
#define ANSI_C_PROTOTYPE

/* int B$,B 32bit BL$K~$N4D6-$GB NUMCHAR_OPTION B$r;H$&$K$O!"B
 * B%3%a%s%H$r30$7$F$/$@$5$$!#B
 */
/* #define INT_IS_SHORT */


#if defined(INT_IS_SHORT)
typedef long nkf_char;
typedef unsigned char nkf_nfchar;
#else
typedef int nkf_char;
typedef int nkf_nfchar;
#endif

/* Unicode Normalization */
#define UNICODE_NORMALIZATION

#ifndef WIN32DLL
/******************************/
/* B%G%U%)%k%H$N=PNO%3!<%IA*BrB */
/* Select DEFAULT_CODE */
#define DEFAULT_CODE_JIS
/* #define DEFAULT_CODE_SJIS */
/* #define DEFAULT_CODE_EUC */
/* #define DEFAULT_CODE_UTF8 */
/******************************/
#else
#define DEFAULT_CODE_SJIS
#endif

#if defined(NUMCHAR_OPTION) && !defined(UTF8_INPUT_ENABLE)
#define UTF8_INPUT_ENABLE
#endif

#ifdef UNICODE_NORMALIZATION
#ifndef UTF8_INPUT_ENABLE
#define UTF8_INPUT_ENABLE
#endif
#define NORMALIZATION_TABLE_LENGTH 942
#define NORMALIZATION_TABLE_NFC_LENGTH 3
#define NORMALIZATION_TABLE_NFD_LENGTH 9
struct normalization_pair{
    const nkf_nfchar nfc[NORMALIZATION_TABLE_NFC_LENGTH];
    const nkf_nfchar nfd[NORMALIZATION_TABLE_NFD_LENGTH];
};
#endif

#endif /* _CONFIG_H_ */