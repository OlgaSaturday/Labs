#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"
int check_n()
{
	int n;
	while (scanf_s("%d", &n) != 1 || n < 1 || getchar() != '\n')
	{
		printf("Try again\n");
		rewind(stdin);
	}
	return n;
}
int check_m()
{
	int m;
	while (scanf_s("%d", &m) != 1 || m < 1 || getchar() != '\n')
	{
		printf("Try gagin\n");
		rewind(stdin);
	}
	return m;
}
int check_in()
{
	int in;
	while (scanf_s("%d", &in) != 1 || (in != 1 && in != 0) || getchar() != '\n')
	{
		printf("Try again\n");
		rewind(stdin);
	}
	return in;
}
int **memory(int n, int m)
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
	if (choice_of_input == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				*(*(matr + i) + j) = rand() % 11;
			}
		}
	}

	else
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

int remade(int** matr, int *n, int m)
{
	int* min;
	int flag = -1;
	min = (int*)calloc(m, sizeof(int));
	for (int i = 0; i < m; i++)
		*(min + i) = minimal(matr, i,(* n));                                                              //Сохранение минимумов в столбцах начальной матрицы

	for (int i = 0; i < (*n); i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((*(*(matr + i) + j) == maximal(*(matr + i), m)) && (*(*(matr + i) + j) == *(min + j)))
			{
				flag = 1;
				move(matr, &n, i);
				matr = (int**)realloc(matr, (* n) * sizeof(int*));
				i--;
				break;
			}
		}
	}
	free(min);
	return flag;
}



int minimal(int** matr, int j, int n)
{
	int mn = *(*matr + j);
	for (int i = 0; i < n; i++)
		if (*(*(matr + i) + j) < mn)
			mn = *(*(matr + i) + j);
	return mn;
}

int maximal(int* matr, int m)
{
	int mx = *matr;
	for (int i = 0; i < m; i++)
	{
		if (*(matr + i) > mx)
			mx = *(matr + i);

	}
	return mx;
}

void move(int** matr, int* n, int i)
{
	for (int j = i; j < (*n) - 1; j++)
		*(matr + j) = *(matr + j + 1);
	(* n)--;
}

void result(int** matr, int n, int m)
{
	if (remade(matr, n, m))
	{
		printf("\nunpossible to remade\n");
	}
	else
	{
		printf("\nfinal matrix:\n");
		show(matr, n, m);
	}
}

void clean(int** matr, int n)
{
	for (int i = 0; i < n; i++)
		free(*(matr + i));
	free(matr);
}
