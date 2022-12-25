#include <stdio.h>
#include <stdlib.h>
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

int check_num()
{
	int num;
	while (scanf_s("%d", &num) != 1 || num < 1 || getchar() != '\n')
	{
		printf("Try again\n");
		rewind(stdin);
	}
	return num;
}

int* memory(int n)
{
	int* mas;
	mas = (int**)calloc(n, sizeof(int*));
	return mas;
}

void input(int** mas, int n)
{
	int choice_of_input;
	int m;
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
			*(mas + i) = (int*)calloc(1, sizeof(int));
			printf("input amount of numbers in %d row  ", i + 1);
			while (scanf_s("%d", &m) != 1 || m < 0 || getchar() != '\n')
			{
				printf("Try again\n");
				rewind(stdin);
			}
			for (int j = 0; j < m - 1; j++)
			{
				*(mas + i) = (int*)realloc(*(mas + i), (j + 1) * sizeof(int));
				*(*(mas + i) + j) = rand() % 100;
			}
			*(*(mas + i) + m - 1) = 0;
		}
	}
	if (choice_of_input == 1)
	{
		for (int i = 0; i < n; i++)
		{
			*(mas + i) = (int*)calloc(1, sizeof(int));
			for (int j = 0;; j++)
			{
				*(mas + i) = (int*)realloc(*(mas + i), (j + 1) * sizeof(int));
				printf("input %d %d element (0 to finish row)", i + 1, j + 1);
				while (scanf_s("%d", *(mas + i) + j) != 1 || *(*(mas + i) + j) < 0 || getchar() != '\n')
				{
					printf("Try again\n");
					rewind(stdin);
				}
				if (*(*(mas + i) + j) == 0)
					break;
			}
		}
	}
}

void conversion(int** mas, int n, int num)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; *(*(mas + i) + j) != 0; j++)
		{
			if (num <= *(*(mas + i) + j))
			{
				move(*(mas + i), j);
				*(mas + i) = (int*)realloc(*(mas + i), (last(*(mas + i)) + 1) * sizeof(int));
				j--;
			}
		}
	}
}

int last(int* mas)
{
	for (int i = 0;; i++)
		if (*(mas + i) == 0)
			return i;
}

void move(int* mas, int j)
{
	for (int i = j; *(mas + i) != 0; i++)
	{
		*(mas + i) = *(mas + i + 1);
	}
}

void show(int** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;; j++)
		{
			printf("%3d ", *(*(mas + i) + j));
			if (*(*(mas + i) + j) == 0)
				break;
		}
		printf("\n");
	}
	printf("\n");
}

void clean(int** mas, int n)
{
	for (int i = 0; i < n; i++)
		free(*(mas + i));
	free(mas);
}
