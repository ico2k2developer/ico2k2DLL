#pragma once

#ifdef ICO2K2_EXPORTS
#define ICO2K2_API __declspec(dllexport)
#else
#define ICO2K2_API __declspec(dllimport)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	UPC_DWC_OFF		'a' - 'A'

#define	OTHER		0x0
#define	CONSONANT	0x1
#define	VOWEL		0x2
#define	DIGIT		0x3
#define	MONEY		0x4
#define	CONTROL		0x5
#define	PARENTHESIS	0x6
#define	SEX			0x7
#define	SLASH		0x8
#define	MATH		0x9
#define	GRAPHIC		0xA
#define	EMOJI		0xB
#define	ARROW		0xC
#define	PUNTACTION	0xE
#define	TYPES_ALL	0xF

#define	UPCASE		0x10
#define	DOWNCASE	0x20
#define	FACT		0x30
#define	POW			0x40
#define	CASE_ALL	0x70

#define	NORMAL		0x0
#define	ACCENTED	0x80


#define	SIZE_DESC	45

typedef unsigned char char_type;

ICO2K2_API char_type		chrtyp(char c);
ICO2K2_API char				chrupc(char c);
ICO2K2_API char				chrdwc(char c);
ICO2K2_API char*			strupc(char* string);
ICO2K2_API char*			strdwc(char* string);
ICO2K2_API size_t			strget(char* buffer, int max);
ICO2K2_API size_t			strget(char* buffer, int max,FILE* f);
ICO2K2_API char*			chrdes(char_type c);
ICO2K2_API void				arr_print(char* a,size_t size);
ICO2K2_API long int			ffind(FILE * f, char* find, size_t length);
ICO2K2_API unsigned char	digtoi(char digit);
ICO2K2_API char				itodig(unsigned char i);
ICO2K2_API char				fisc_check(char* code,size_t length);
ICO2K2_API unsigned char	fisc_even(char c);
ICO2K2_API unsigned char	fisc_uneven(char c);