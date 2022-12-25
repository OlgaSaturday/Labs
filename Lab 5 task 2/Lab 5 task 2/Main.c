#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int main()
{
	int** matr; //= NULL;
	int n, m, in, flag = -1;
	printf("input number of rows  ");
	n = check_n();
	printf("input number of columns  ");
	m = check_m();
	matr = memory(n, m);
	input(matr, n, m);
	show(matr, n, m);
	flag  = remade(matr, n, m);
	if (flag != 1)
	{
		printf("\nunpossible to remade\n");
	}
	else
	{
		printf("\nfinal matrix:\n");
		show(matr, n, m);
	}
	/*for (int i = 0; i < n; i++)
		free(*(matr + i));*/
	return 0;
}
