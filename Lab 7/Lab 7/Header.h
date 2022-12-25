int check_num();
char* input_line();
void output_line(char* s);

int ind(char* s);
void output_word(char* s, int ind_max);

int code_of_1st_letter(char* s);
int size_of_1st_word(char* s);
int ind_in_S0(char* s);
int line_size(char* s);
char* remade(char* S0, int indS0, int length, int* size);
char* search(char* S, char* S0, int code, int length, int indS0);
char* delete (char* S, int start, int length);

void main1();
void main2();
