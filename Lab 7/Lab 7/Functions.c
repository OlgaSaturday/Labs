#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int check_num()
{
	int num;
	while (scanf_s("%d", &num) != 1 || (num != 1 && num != 2) || getchar() != '\n')
	{
		printf("Try again\n");
		rewind(stdin);
	}
	return num;
}

char* input_line()                                       // строка + 4 символа
{
	char* s;
	s = (char*)calloc(1, sizeof(char));
	for (int i = 0; ; i++)
	{
		s = (char*)realloc(s, (i + 1) * sizeof(char));
		s[i] = getchar();
		if (s[i] == '\n')
		{
			s[i] = '\0';
			break;
		}
	}
	return s;
}

void output_line(char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		printf("%c", s[i++]);
	}
	printf("\n");
}

char* delete (char* S, int start, int length)
{
	for (int i = 0; S[i + length + start - 1] != '\0'; i++)
	{
		S[i + start] = S[i + length + start];
	}
	return S;
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
	int i = 0, size = 0, ind = 0, num = 0;                                        //size - длина первого слова в S0
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
	int i = 0, ind = 0;                                                       //ind - индекс первой буквы первого слова в S0
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

int line_size(char* s)
{
	int n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return n;
}

char* remade(char* S0, int indS0, int length, int* size)
{
	int i;
	for (i = 0; i < length; i++)
	{
		S0[i] = S0[i + indS0];
	}
	S0[i] = '\0';
	(*size) -= (i + 1);
	return S0;
}

char* search(char* S, char* S0, int code, int length, int indS0)
{
	int fl = 1;
	for (int i = 0; i < line_size(S); i++)
	{
		if (S[i] == S0[indS0])
		{
			fl = 1;
			int j = i;
			int k = indS0;
			while ((S[j] != ' ') && (S[j] != '\t') && (S[j] != '\0') && (S0[k] != '\0'))
			{
				if (S[j] == S0[k])
				{
					j++;
					k++;
				}
				else
				{
					fl = 0;
					break;
				}
			}
			if (fl)
			{
				S = delete(S, i, k - indS0);
				int l = line_size(S) + 1;
				S = realloc(S, l);
			}

		}
	}
	return S;
}

int ind(char* s)
{
	int temp = 0, max = 0, ind_max = 0, i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			temp++;
		}
		else
		{
			if (temp > max)
			{
				max = temp;
				ind_max = i - temp;
			}
			temp = 0;
		}
		i++;
	}
	if (temp > max)
	{
		max = temp;
		ind_max = i - temp;
		temp = 0;
	}
	return ind_max;
}

void output_word(char* s, int ind_max)
{
	int i = ind_max;
	while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
	{
		printf("%c", s[i]);
		i++;
	}
}

void main1()
{
	char* s;
	int ind_max;
	printf("Input line:  ");
	s = input_line();
	ind_max = ind(s);
	printf("\nLongest word:  ");
	output_word(s, ind_max);
	printf("\n");
	free(s);
}

void main2()
{
	char* S, * S0;
	int length = 0, code = 0, indS0 = 0, indS = 0, size_S0 = 0;
	printf("Input line S: ");
	S = input_line();
	printf("\nInput line S0: ");
	S0 = input_line();
	code = code_of_1st_letter(S0);
	length = size_of_1st_word(S0);
	indS0 = ind_in_S0(S0);
	size_S0 = line_size(S0);
	S0 = remade(S0, indS0, length, &size_S0);
	S = search(S, S0, code, length, 0);
	printf("\nFinal line: ");
	printf("%s", S);
	free(S);
	free(S0);
}