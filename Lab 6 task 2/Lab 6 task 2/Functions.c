#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"
int check_int()
{
	int a;
	while (scanf_s("%d", &a) != 1 || a < 1 || getchar() != '\n')
	{
		printf("Try again\n");
		rewind(stdin);
	}
	return a;
}
//int check_k()
//{
//	int k;
//	while (scanf_s("%d", &k) != 1 || k < 1 || k > n || getchar() != '\n')
//	{
//		printf("Try gagin\n");
//		rewind(stdin);
//	}
//	return k;
//}
int** memory(int n, int m)
{
	int** matr;
	matr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		*(matr + i) = (int*)calloc(m, sizeof(int));
	return matr;
}
void input(int** matr, int n, int m)
{
	int choice_of_input;
	printf("Choose 0 for random input and 1 for keyboard input  ");
	while (scanf_s("%d", &choice_of_input) != 1 || (choice_of_input != 0 && choice_of_input != 1) || getchar() != '\n')
	{
		printf("try again\n");
		rewind(stdin);
	}
	switch (choice_of_input)
	{
	case 0: random_input(matr, n, m);
		break;
	case 1: keyboard_input(matr, n, m);
		break;
	}
}
void random_input(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(matr + i) + j) = rand() % 21-10;
		}
	}
}
void keyboard_input(int** matr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("input %d %d element ", i + 1, j + 1);
			while (scanf_s("%d", *(matr + i) + j) != 1 || getchar() != '\n')
			{
				printf("Try again\n");
				rewind(stdin);
			}
		}
	}
}
void show(int** matr, int n, int m)
{

	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d\t", *(*(matr + i) + j));
		printf("\n");
	}
}
void sort(int** matr, int n, int m, int k)
{
	int max, temp;
	for (int i = k - 1; i < n-k; i += k)
	{
		max = i;
		for (int j = i + k; j < n; j += k)
		{
			if(sum (matr[j], m) > sum (matr[max], m))
				max = j;
		}
		for (int a = 0; a < m; a++)
		{
			temp = matr[i][a];
			matr[i][a] = matr[max][a];
			matr[max][a] = temp;
		}
	}
}
int sum(int* matr, int m)
{
	int sum = 0;
	for (int j = 0; j < m; j++)
	{
		if (matr[j] > 0)
			sum += matr[j];
	}
	return sum;
}
void clean(int** matr, int n)
{
		for (int i = 0; i < n; i++)
			free(*(matr + i));
		free(matr);
}
