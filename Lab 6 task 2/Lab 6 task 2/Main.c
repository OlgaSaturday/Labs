#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
int main()
{
	int n, m, k;
	int** matr;
	printf("Input number of rows  ");
	n = check_int();
	printf("Input number of columns  ");
	m = check_int();
	matr = memory(n, m);
	input(matr, n, m);
	show(matr, n, m);
	//printf("Input k ");
	do
	{
		printf("Input k (proviso: 0 < k < number of rows) ");
		k = check_int();
	} 
	while (k > n);
	sort(matr, n, m, k);
	show(matr, n, m);
	getchar();
	return 0;
}