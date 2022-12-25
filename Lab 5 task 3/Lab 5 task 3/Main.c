#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void main()
{
	int** mas;
	int n, num;
	printf("Input number of rows  ");
	n = check_n();
	printf("Input custom number  ");
	num = check_num();
	mas = memory(n);
	input(mas, n);
	show(mas, n);
	conversion(mas, n, num);
	show(mas, n);
	clean(mas, n);
}