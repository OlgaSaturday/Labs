#include<stdio.h>
#include <stdlib.h>
#include "Header.h"
void move(int* mas, int* n, int i)
{
	for (; i < *n; i++)
	{
		mas[i] = mas[i + 1];
	}
	(*n)--;
}
int composite_number(int mas)
{
	for (int j = 2; j * j <= mas; j++)
	{
		if (mas % j == 0)
			return 1;
	}
	return 0;
}
void show(int* mas, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", *(mas + i));
	printf("\n");
}
int check_size()
{
	int n;
	while (scanf_s("%d", &n) != 1 || n < 1 || getchar() != '\n')
	{
		printf("Try again\n");
		rewind(stdin);
	}
	return n;
}
void input(int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Input %d number ", i + 1);
		while (scanf_s("%d", &mas[i]) != 1 || mas[i] < 1 || getchar() != '\n')
		{
			printf("Try again\n");
			rewind(stdin);
		}
	}
}
void check_of_elements(int* mas, int n)
{
	int flag = 0;
	for (int i = n - 1; i >= 0; i--)
		if (composite_number(mas[i]))
		{
			flag = 1;
			move(mas, &n, i);
			mas = (int*)realloc(mas, n * sizeof(int));
		}
	if (flag == 0)
	{
		printf("unpossible to remade\n");
	}
	else
	{
		show(mas, n);
	}
}

int* memory(int n)
{
	int* mas;
	mas = (int*)malloc(n * sizeof(int));
	return mas;
}
