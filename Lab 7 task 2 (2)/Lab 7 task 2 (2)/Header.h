char* input_line();
void output_line(char* s);
int code_of_1st_letter(char* s);
int size_of_1st_word(char* s);
int ind_in_S0(char* s);
int number_of_symbols_in_line(char* s);
int number_of_words_in_line(char* s, int n);

char**  remade_s(char* s, int number_of_symbols, int number_of_words);
int  check_same(char** S_new, char* S0, int number_of_words, int code, int length);
char** remade_S_(char** S_new, int flag, int number_of_words, int number_of_symbols);
int count_symbols_again(int flag, int number_of_words);