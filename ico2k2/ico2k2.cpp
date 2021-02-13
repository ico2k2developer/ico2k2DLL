#include "pch.h" 
#include "ico2k2.h"

arrp arr_new(void* a, size_t size,size_t length,arrp dest)
{
	if (!dest)
		dest = (arrp)malloc(sizeof(arr));
	if (dest)
	{
		if (!a)
			a = malloc(size * length);
		dest->a = a;
		dest->l = length == size ? 0 : 1;
		dest->sizes = (size_t*)malloc(sizeof(size_t) * ((size_t)dest->l + 1));
	}
	return dest;
}

size_t arr_size(arrp a)
{
	size_t result = NULL;
	if (a)
		result = a->sizes[ARRAYP_SZ];
	return result;
}

size_t arr_length(arrp a)
{
	size_t result = NULL;
	if (a)
		result = a->sizes[a->l];
	return result;
}

size_t arr_esize(arrp a)
{
	return arr_size(a) / arr_length(a);
}

void* arr_arr(arrp a)
{
	return a ? a->a : NULL;
}

char_type chrtyp(char c)
{
	char_type result = OTHER;
	switch (c)
	{
	case -127:
	case -126:
	case -125:
	case -124:
	case -123:
	case -122:
	case -120:
	case -119:
	case -118:
	case -117:
	case -116:
	case -115:
	case -111:
	case -109:
	case -108:
	case -107:
	case -106:
	case -105:
	case -101:
	case -96:
	case -95:
	case -94:
	case -93:
	case -58:
	case -43:
	case -28:
	{
		result = VOWEL | ACCENTED | DOWNCASE;
		break;
	}
	case -121:
	case -104:
	case -92:
	case -26:
	case -20:
	{
		result = CONSONANT | ACCENTED | DOWNCASE;
		break;
	}
	case -114:
	case -113:
	case -112:
	case -110:
	case -103:
	case -102:
	case -99:
	case -75:
	case -74:
	case -73:
	case -57:
	case -46:
	case -45:
	case -44:
	case -42:
	case -41:
	case -40:
	case -34:
	case -32:
	case -30:
	case -29:
	case -27:
	case -23:
	case -22:
	case -21:
	{
		result = VOWEL | ACCENTED | UPCASE;
		break;
	}
	case -128:
	case -91:
	case -47:
	case -19:
	{
		result = CONSONANT | ACCENTED | UPCASE;
		break;
	}
	case -86:
	case -80:
	case -79:
	case -78:
	case -77:
	case -76:
	case -2:
	{
		result = GRAPHIC;
		break;
	}
	case -85:
	case -84:
	case -13:
	{
		result = DIGIT | FACT;
		break;
	}
	case 97:
	case 101:
	case 105:
	case 111:
	case 117:
	{
		result = VOWEL | DOWNCASE;
		break;
	}
	case 65:
	case 69:
	case 73:
	case 79:
	case 85:
	{
		result = VOWEL | UPCASE;
		break;
	}
	case -100:
	case -67:
	case -66:
	case 36:
	{
		result = MONEY;
		break;
	}
	case -98:
	case -97:
	case -16:
	case -15:
	case -10:
	case 37:
	case 43:
	case 60:
	case 61:
	case 62:
	case 126:
	{
		result = MATH;
		break;
	}
	case -90:
	case -89:
	case -88:
	case -87:
	case -83:
	case -82:
	case -81:
	case -72:
	case -17:
	case -9:
	case -6:
	case 19:
	case 32:
	case 33:
	case 34:
	case 39:
	case 42:
	case 44:
	case 45:
	case 46:
	case 58:
	case 59:
	case 63:
	case 94:
	case 96:
	{
		result = PUNTACTION;
		break;
	}
	case -1:
	case 0:
	case 9:
	case 10:
	{
		result = CONTROL;
		break;
	}
	case 11:
	case 12:
	{
		result = SEX;
		break;
	}
	case 14:
	case 15:
	{
		result = EMOJI;
		break;
	}
	case 16:
	case 17:
	{
		result = ARROW;
		break;
	}
	case 40:
	case 41:
	case 91:
	case 93:
	case 123:
	case 125:
	{
		result = PARENTHESIS;
		break;
	}
	case 47:
	case 92:
	{
		result = SLASH;
		break;
	}
	default:
	{
		if (c >= 'A' && c <= 'Z')
			result = CONSONANT | UPCASE;
		else if (c >= 'a' && c <= 'z')
			result = CONSONANT | DOWNCASE;
		else if (c >= '0' && c <= '9')
			result = DIGIT;
		else if ((c >= -71 && c <= -50) || (c >= -39 && c <= -33))
			result = GRAPHIC;
		else if (c >= 1 && c <= 6)
			result = EMOJI;
		else if (c >= 23 && c <= 31)
			result = EMOJI;
		else if (c >= -5 && c <= -3)
			result = DIGIT | POW;
	}
	}
	return result;
}

size_t strget(char* buffer, int max,FILE* stream)
{
	fgets(buffer, max, stream);
	size_t length = strlen(buffer);
	if (buffer[length - 1] == '\n')
		buffer[length - 1] = '\0';
	return length;
}

size_t strget(char* buffer, int max)
{
	return strget(buffer, max, stdin);
}

char* strupc(char* string)
{
	int i;
	for (i = 0; string[i] != '\0'; i++)
		string[i] = chrupc(string[i]);
	return string;
}

char* strdwc(char* string)
{
	int i;
	for (i = 0; string[i] != '\0'; i++)
		string[i] = chrdwc(string[i]);
	return string;
}

char chrdwc(char c)
{
	char_type t = chrtyp(c);
	if (t & UPCASE)
	{
		if (t & ACCENTED)
		{
			switch (c)
			{
				case -102:
				{
					c = -127;
					break;
				}
				case -112:
				{
					c = -126;
					break;
				}
				case -74:
				{
					c = -125;
					break;
				}
				case -114:
				{
					c = -124;
					break;
				}
				case -73:
				{
					c = -123;
					break;
				}
				case -113:
				{
					c = -122;
					break;
				}
				case -128:
				{
					c = -121;
					break;
				}
				case -46:
				{
					c = -120;
					break;
				}
				case -45:
				{
					c = -119;
					break;
				}
				case -44:
				{
					c = -118;
					break;
				}
				case -40:
				{
					c = -117;
					break;
				}
				case -41:
				{
					c = -116;
					break;
				}
				case -34:
				{
					c = -115;
					break;
				}
				case -110:
				{
					c = -111;
					break;
				}
				case -30:
				{
					c = -109;
					break;
				}
				case -103:
				{
					c = -108;
					break;
				}
				case -29:
				{
					c = -107;
					break;
				}
				case -22:
				{
					c = -106;
					break;
				}
				case -21:
				{
					c = -105;
					break;
				}
				case -99:
				{
					c = -101;
					break;
				}
				case -75:
				{
					c = -96;
					break;
				}
				case -42:
				{
					c = -95;
					break;
				}
				case -32:
				{
					c = -94;
					break;
				}
				case -23:
				{
					c = -93;
					break;
				}
				case -91:
				{
					c = -92;
					break;
				}
				case -57:
				{
					c = -58;
					break;
				}
				case 105:
				{
					c = -43;
					break;
				}
				case -27:
				{
					c = -28;
					break;
				}
				case 77:
				{
					c = -26;
					break;
				}
				case -19:
				{
					c = -20;
					break;
				}
			}
		}
		else
		{
			c += UPC_DWC_OFF;
		}
	}
	return c;
}

char chrupc(char c)
{
	char_type t = chrtyp(c);
	if (t & DOWNCASE)
	{
		if (t & ACCENTED)
		{
			switch (c)
			{
				case -127:
				{
					c = -102;
					break;
				}
				case -126:
				{
					c = -112;
					break;
				}
				case -125:
				{
					c = -74;
					break;
				}
				case -124:
				{
					c = -114;
					break;
				}
				case -123:
				{
					c = -73;
					break;
				}
				case -122:
				{
					c = -113;
					break;
				}
				case -121:
				{
					c = -128;
					break;
				}
				case -120:
				{
					c = -46;
					break;
				}
				case -119:
				{
					c = -45;
					break;
				}
				case -118:
				{
					c = -44;
					break;
				}
				case -117:
				{
					c = -40;
					break;
				}
				case -116:
				{
					c = -41;
					break;
				}
				case -115:
				{
					c = -34;
					break;
				}
				case -111:
				{
					c = -110;
					break;
				}
				case -109:
				{
					c = -30;
					break;
				}
				case -108:
				{
					c = -103;
					break;
				}
				case -107:
				{
					c = -29;
					break;
				}
				case -106:
				{
					c = -22;
					break;
				}
				case -105:
				{
					c = -21;
					break;
				}
				case -101:
				{
					c = -99;
					break;
				}
				case -96:
				{
					c = -75;
					break;
				}
				case -95:
				{
					c = -42;
					break;
				}
				case -94:
				{
					c = -32;
					break;
				}
				case -93:
				{
					c = -23;
					break;
				}
				case -92:
				{
					c = -91;
					break;
				}
				case -58:
				{
					c = -57;
					break;
				}
				case -43:
				{
					c = 105;
					break;
				}
				case -28:
				{
					c = -27;
					break;
				}
				case -26:
				{
					c = 77;
					break;
				}
				case -20:
				{
					c = -19;
					break;
				}
			}
		}
		else
		{
			c -= UPC_DWC_OFF;
		}
	}
	return c;
}

char* chrdes(char_type c)
{
	char* result = (char*)malloc(sizeof(char) * SIZE_DESC);
	if (!result)
		return NULL;
	switch (c & TYPES_ALL)
	{
	case VOWEL:
	{
		strcpy_s(result, SIZE_DESC, "vocale");
		break;
	}
	case CONSONANT:
	{
		strcpy_s(result, SIZE_DESC, "consonante");
		break;
	}
	case DIGIT:
	{
		strcpy_s(result, SIZE_DESC, "cifra");
		break;
	}
	case MONEY:
	{
		strcpy_s(result, SIZE_DESC, "valuta");
		break;
	}
	case PARENTHESIS:
	{
		strcpy_s(result, SIZE_DESC, "parentesi");
		break;
	}
	case PUNTACTION:
	{
		strcpy_s(result, SIZE_DESC, "punteggiatura");
		break;
	}
	case SEX:
	{
		strcpy_s(result, SIZE_DESC, "sesso");
		break;
	}
	case SLASH:
	{
		strcpy_s(result, SIZE_DESC, "barra");
		break;
	}
	case MATH:
	{
		strcpy_s(result, SIZE_DESC, "simbolo matemetico");
		break;
	}
	case GRAPHIC:
	{
		strcpy_s(result, SIZE_DESC, "carattere grafico");
		break;
	}
	case EMOJI:
	{
		strcpy_s(result, SIZE_DESC, "emoji");
		break;
	}
	case ARROW:
	{
		strcpy_s(result, SIZE_DESC, "indicatore");
		break;
	}
	case CONTROL:
	{
		strcpy_s(result, SIZE_DESC, "carattere di controllo");
		break;
	}
	default:
	{
		strcpy_s(result, SIZE_DESC, "carattere non classificato");
	}
	}
	switch (c & CASE_ALL)
	{
	case DOWNCASE:
	{
		strcat_s(result, SIZE_DESC, " minuscola");
		break;
	}
	case UPCASE:
	{
		strcat_s(result, SIZE_DESC, " maiuscola");
		break;
	}
	case FACT:
	{
		strcat_s(result, SIZE_DESC, ": frazione");
		break;
	}
	case POW:
	{
		strcat_s(result, SIZE_DESC, ": potenza");
		break;
	}
	}
	if (c & ACCENTED)
		strcat_s(result, SIZE_DESC, " accentata o speciale");
	return result;
}

void arr_print(char* a, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
		printf("[%d]\t", a[i]);
	printf("\n");
}

void arr_print(arrp a)
{
	arr_print((char*)a->a, arr_length(a));
}

long ffind(FILE* f, char* find, size_t length)
{
	long result = EOF;
	size_t i;
	int c;
	if (f && find)
	{
		fseek(f, 0, SEEK_SET);
		while (result == EOF)
		{
			do
			{
				c = fgetc(f);
			}
			while (c != find[0] && c != EOF);
			if (c == EOF)
				break;
			else
			{
				for (i = 1; i < length; i++)
				{
					c = fgetc(f);
					if (find[i] != c)
						break;
				}
				if (i == length)
					result = (long int)(ftell(f) - i);
			}
		}
	}
	return result;
}

unsigned char digtoi(char digit)
{
	return digit >= '0' && digit <= '9' ? digit - 48 : 0;
}

char itodig(unsigned char i)
{
	return i >= 0 && i <= 9 ? i + 48 : -1;
}

char fisc_check(char* code,size_t length)
{
	size_t i;
	unsigned short tmp = 0;
	unsigned char result = NULL;
	if (!code)
		return result;
	for (i = 0; i * 2 < length && (result = code[i * 2]) != NULL; i++)
	{
		tmp += fisc_uneven(result);
	}
	for (i = 0; (i * 2 + 1) < length && (result = code[i * 2 + 1]) != NULL; i++)
	{
		tmp += fisc_even(result);
	}
	return ((char)(tmp % 26)) + 'A';
}

unsigned char fisc_even(char c)
{
	char result = NULL;
	switch (chrtyp(c) & TYPES_ALL)
	{
		case DIGIT:
		{
			result = digtoi(c);
			break;
		}
		case VOWEL:
		case CONSONANT:
		{
			result = chrupc(c) - 'A';
			break;
		}
	}
	return result;
}

unsigned char fisc_uneven(char c)
{
	char result = NULL;
	switch (c)
	{
		case '0':
		{
			result = 1;
			break;
		}
		case '1':
		{
			result = 0;
			break;
		}
		case '2':
		{
			result = 5;
			break;
		}
		case '3':
		{
			result = 7;
			break;
		}
		case '4':
		{
			result = 9;
			break;
		}
		case '5':
		{
			result = 13;
			break;
		}
		case '6':
		{
			result = 15;
			break;
		}
		case '7':
		{
			result = 17;
			break;
		}
		case '8':
		{
			result = 19;
			break;
		}
		case '9':
		{
			result = 21;
			break;
		}
		case 'A':
		{
			result = 1;
			break;
		}
		case 'B':
		{
			result = 0;
			break;
		}
		case 'C':
		{
			result = 5;
			break;
		}
		case 'D':
		{
			result = 5;
			break;
		}
		case 'E':
		{
			result = 7;
			break;
		}
		case 'F':
		{
			result = 13;
			break;
		}
		case 'G':
		{
			result = 15;
			break;
		}
		case 'H':
		{
			result = 17;
			break;
		}
		case 'I':
		{
			result = 19;
			break;
		}
		case 'J':
		{
			result = 21;
			break;
		}
		case 'K':
		{
			result = 2;
			break;
		}
		case 'L':
		{
			result = 4;
			break;
		}
		case 'M':
		{
			result = 18;
			break;
		}
		case 'N':
		{
			result = 20;
			break;
		}
		case 'O':
		{
			result = 11;
			break;
		}
		case 'P':
		{
			result = 3;
			break;
		}
		case 'Q':
		{
			result = 6;
			break;
		}
		case 'R':
		{
			result = 8;
			break;
		}
		case 'S':
		{
			result = 12;
			break;
		}
		case 'T':
		{
			result = 14;
			break;
		}
		case 'U':
		{
			result = 16;
			break;
		}
		case 'V':
		{
			result = 10;
			break;
		}
		case 'W':
		{
			result = 22;
			break;
		}
		case 'X':
		{
			result = 25;
			break;
		}
		case 'Y':
		{
			result = 24;
			break;
		}
		case 'Z':
		{
			result = 23;
			break;
		}
	}
	return result;
}

long flen(FILE* f)
{
	long result, l = ftell(f);
	fseek(f, 0, SEEK_END);
	result = ftell(f);
	fseek(f, l, SEEK_SET);
	return result;
}