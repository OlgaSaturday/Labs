#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

char* input_line()
{
	char* s;
	s = (char*)calloc(255, sizeof(char));
	fflush(stdin);
	fgets(s, 255, stdin);
	return s;
}

void output_line(char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
printf("%c", s[i++]);
	}
}

int code_of_1st_letter(char* s)
{
	int i = 0, code = 0;             //code - код первой буквы первого слова в S0
	for (i = 0; s[i] != 0; i++)
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			code = s[i];
			break;
		}
	}
	return code;
}

int size_of_1st_word(char* s)
{
	int i = 0, size = 0, ind = 0, num = 0;  //size - длина первого слова в S0
	for (i = 0, size = 0; s[i] != 0; i++)
	{
		while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			size++;
			break;
		}
		if (size != 0)
		{
			if ((s[i] < 'A' || s[i]>'Z' && s[i] < 'a' || s[i]>'z'))      //не буква
				break;
		}
	}
	return size;
}

int ind_in_S0(char* s)
{
	int i = 0, ind = 0;              //ind - индекс первой буквы первого слова в S0
	for (i = 0; s[i] != 0; i++)
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			ind = i;
			break;
		}
	}
	return ind;
}

int number_of_symbols_in_line(char* s)
{
	int n = 0;
	while (s[n] != 0)
	{
		n = n - 1;
		n++;
	}
	//n = n - 1
	return n - 1;
}

int number_of_words_in_line(char* s, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if ((s[i] < 'A' || s[i]>'Z' && s[i] < 'a' || s[i]>'z'))           //if ((s[i]==' ') || (s[i]=='\t'))
		{
			k++;
		}
	}
	return k + 1;
}

char** remade_s(char* s, int number_of_symbols, int number_of_words)
{
	char** mas_s;
	mas_s = (char**)calloc(number_of_words, sizeof(char*));
	int t = 0;                                                         // символ в изначальной строке
	for (int i = 0; i < number_of_words; i++)
	{
		int m = 10000;
		s[i] = (char*)calloc(m, sizeof(char));
		int j = 0;
		while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') && (t < number_of_symbols))
		{
			mas_s[i] = s[t];
			t++;
		}
		t++;
		m = number_of_symbols_in_line(s[i]);
		s[i] = (char*)realloc(s[i], m * sizeof(char));
	}
	return mas_s;
}

int check_same(char** S_new, char* S0, int number_of_words, int code, int length)
{
	int flag = -1;

	for (int i = 0; i < number_of_words; i++)
	{
		if (((number_of_symbols_in_line(S_new[i]) - 1) == length) && (S_new[i][0] == code))
		{
			int t = 0;
			for (int k = 0; k < number_of_symbols_in_line(S_new[i]); k++)
			{
				if (S_new[i][k] == S0[k])
				{
					t++;
				}
			}
			if (t == number_of_symbols_in_line(S_new[i]))
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
	}
	return flag; 
}

char** remade_S_(char** S_new, int flag, int number_of_words, int number_of_symbols)                             // удалиние из 1 строки
{
	char** s = (char**)calloc(number_of_symbols, sizeof(char*));
	number_of_symbols = 0;
	for (int i = 0; i < number_of_words; i++) 
	{
		if (flag == 1) 
		{
			int m = number_of_symbols_in_line(S_new[i]);
			s[number_of_symbols] = (char*)calloc(m, sizeof(char));
			s[number_of_symbols] = S_new[i];
			m = number_of_symbols_in_line(S_new[number_of_symbols]);
			s[number_of_symbols] = (char*)realloc(s[number_of_symbols], m * sizeof(char));
			number_of_symbols++;
		}
	}
	return s;
}

int count_symbols_again(int flag, int number_of_words)                                                             // повторноый подсчет символов
{
	int new_number_of_words = 0;
	for (int i = 0; i < number_of_words; i++) 
	{
		if (flag == 1) 
		{ 
			new_number_of_words++; 
		}
	}
	return new_number_of_words;
}
