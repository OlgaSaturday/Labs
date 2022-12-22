#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

// —троки S и S0. ”далить из S первое солво из S0.

// запомнить индекс первой буквы слова (и его размер) в S0 
// идем по строке  S
// если находим первую букву слова, сравниваем посимвольно до размера прошлого слова, если след символ тоже буква, то не считаем его

void main()
{
	char* S, * S0;
	char **S_new, ** S_new_remade;
	int length = 0, code = 0, indS0 = -1, indS = -1, sizeS = 0, number_of_symbols = 0, number_of_words = 0, flag = -1, new_number_of_words = -1;
	printf("Input line S: ");
	S = input_line();
	printf("\nYour line S: ");
	output_line(S);
	printf("\nInput line S0: ");
	S0 = input_line();
	printf("\nYour line S0: ");
	output_line(S0);
	printf("\n");
	code = code_of_1st_letter(S0);
	printf("code %d\n", code);
	length = size_of_1st_word(S0);
	printf("length %d\n", length);
	indS0 = ind_in_S0(S0);
	printf("ind in S0 %d\n", indS0);
	number_of_symbols = number_of_symbols_in_line(S);
	printf("number of symbols in S %d\n", number_of_symbols);
	number_of_words = number_of_words_in_line(S, number_of_symbols);
	printf("number of words in S %d\n", number_of_words);

	S_new = remade_s(S, number_of_symbols, number_of_words);
	flag = check_same(S_new, S0, number_of_words, code, length);
	S_new_remade = remade_S_(S_new, flag, number_of_words, number_of_symbols);
	new_number_of_words = count_symbols_again(flag, number_of_words);

	printf("Final string: ");
	for (int i = 0; i < new_number_of_words; i++)
	{
		printf("%s\t", S_new_remade[i]); 
	}
	free(S);
	free(S0);
	free(S_new);
	free(S_new_remade);

}