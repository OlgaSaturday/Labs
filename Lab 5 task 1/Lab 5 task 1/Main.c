#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
int main()
{
	int  n, flag = 0;
	int* mas;
	printf("Input amount of numbers\n");
	n = check_size();
	mas = memory(n);
	//mas = (int*)malloc(n * sizeof(int));
	input(mas, n);
	show(mas, n);
	check_of_elements(mas, n);
	free(mas);
	getchar();
	return 0;
}