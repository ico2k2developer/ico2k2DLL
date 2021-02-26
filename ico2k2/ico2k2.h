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

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define DO_EXPAND(VAL)  VAL ## 1
#define EMPTYSTR(VAL)     DO_EXPAND(VAL)


#ifdef  _MSC_VER
#define	__COMPILER__	"Visual Studio " STR(_MSC_VER) " (" STR(_MSC_FULL_VER) ")"
#elif	__GNUC__
#define	__COMPILER__	"gcc " STR(__GNUC__) "." STR(__GNUC_MINOR__)
#elif	__clang__
#define	__COMPILER__	"clang " STR(__clang_major__) "." STR(__clang_minor__) ", patch level " STR(__clang_patchlevel__)
#elif	__EMSCRIPTEN__ 
#define	__COMPILER__	"emscripten " STR(__EMSCRIPTEN__)
#elif	__MINGW32__ 
#define	__COMPILER__	"MinGW 32 bit " STR(__MINGW32_MAJOR_VERSION ) "." STR(__MINGW32_MINOR_VERSION )
#elif	__MINGW64__ 
#define	__COMPILER__	"MinGW 64 bit " STR(__MINGW64_MAJOR_VERSION ) "." STR(__MINGW64_MINOR_VERSION )
#else
#define __COMPILER__	"Unknown compiler"
#endif

#ifdef	_WIN64
#define	__OS__			"Windows 64 bit"
#elif	_WIN32
#define	__OS__			"Windows 32 bit"
#elif	__ANDROID__ 
#define	__OS__			"Android"
#elif	__linux__ 
#define	__OS__			"Linux"
#elif	__APPLE__ 
#define	__OS__			"Mac OS X or iOS"
#elif	__ros__ 
#define	__OS__			"Akaros"
#elif	__native_client__ 
#define	__OS__			"NaCL"
#elif	__asmjs__ 
#define	__OS__			"AsmJS"
#elif	__Fuchsia__ 
#define	__OS__			"Google Fuchsia"
#endif

#ifdef	__STDC__
#define	__LANGUAGE__	"C"
#elif	__cplusplus
#define	__LANGUAGE__		"C++ (" STR(__cplusplus) ")"
#endif

#ifdef	_DEBUG 
#define	__VERSION__		"Debug"
#else
#define	__VERSION__		"Release"
#endif

#ifdef	_WIN32
#define	PATH_FONTS		"%SYSTEMROOT%\\Fonts"

#endif


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