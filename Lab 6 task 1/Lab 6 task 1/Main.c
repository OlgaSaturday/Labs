#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"
int main()
{
	int  n;
	int* mas;
	double time1 = 0.0, time2 = 0.0;
	printf("Input amount of numbers\n");
	n = check_size();
	mas = memory(n);
	input(mas, n);
	printf("\n\nOriginal array\n");
	//show(mas, n);

	clock_t begin1 = clock();
	quick_sort(mas, 0, n - 1);
	clock_t end1 = clock();
	time1 += (double)(end1 - begin1) / CLOCKS_PER_SEC;
	printf("\n\nResult of using quick sort\n");
	//show(mas, n);
	printf("\nTime for quick sort %lf seconds\n\n", time1);

	clock_t begin2 = clock();
	selection_sort(mas, n);
	clock_t end2 = clock();
	time2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("\n\nResult of using select sort\n");
	//show(mas, n);
	printf("\nTime for select sort %lf seconds\n\n", time2);
	clean(mas);
	getchar();
	return 0;
}