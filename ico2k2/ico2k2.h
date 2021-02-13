#pragma once

#ifdef ICO2K2_EXPORTS
#define ICO2K2_API __declspec(dllexport)
#else
#define ICO2K2_API __declspec(dllimport)
#endif

#ifndef _ICO2K2__H_
#define _ICO2K2__H_

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

typedef struct
{
	void* arr;
	size_t size,length;
}arr;

typedef unsigned char char_type;
typedef arr* arrp;

ICO2K2_API arrp				arr_enew(void* a, size_t size_element, size_t length, arrp* dest);
ICO2K2_API arrp				arr_tnew(void* a, size_t size_total, size_t length, arrp* dest);
ICO2K2_API arrp				arr_snew(void* a, size_t size_total, size_t size_element, arrp* dest);
ICO2K2_API size_t			arr_length(arrp a);
ICO2K2_API size_t			arr_esize(arrp a);
ICO2K2_API size_t			arr_size(arrp a);
ICO2K2_API void*			arr_arr(arrp a);
ICO2K2_API void				arr_del(arrp a);
ICO2K2_API char_type		chrtyp(char c);
ICO2K2_API char				chrupc(char c);
ICO2K2_API char				chrdwc(char c);
ICO2K2_API char*			strupc(char* string);
ICO2K2_API char*			strdwc(char* string);
ICO2K2_API size_t			strget(char* buffer, int max);
ICO2K2_API size_t			strget(char* buffer, int max,FILE* f);
ICO2K2_API char*			chrdes(char_type c);
ICO2K2_API void				arr_print(char* a,size_t size);
ICO2K2_API void				arr_print(arrp a);
ICO2K2_API long				ffind(FILE * f, char* find, size_t length);
ICO2K2_API unsigned char	digtoi(char digit);
ICO2K2_API char				itodig(unsigned char i);
ICO2K2_API char				fisc_check(char* code,size_t length);
ICO2K2_API unsigned char	fisc_even(char c);
ICO2K2_API unsigned char	fisc_uneven(char c);
ICO2K2_API long				flen(FILE* f);

#endif