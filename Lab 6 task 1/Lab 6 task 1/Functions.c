#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
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
int* memory(int n)
{
	int* mas;
	mas = (int*)malloc(n * sizeof(int));
	return mas;
}
void input(int* mas, int n)
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
	case 0: random_input(mas, n);
		break;
	case 1: keyboard_input(mas, n);
		break;
	}
}
void random_input(int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 10000;
	}
}
void keyboard_input(int* mas, int n)
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
void show(int* mas, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", *(mas + i));
	printf("\n");
}
void quick_sort(int* mas, int left, int right)
{
	int pivot;
	int l_border = left; 
	int r_border = right;
	pivot = mas[left];
	while (left < right)
	{
		while ((mas[right] >= pivot) && (left < right))
			right--;
		if (left != right) 
		{
			mas[left] = mas[right];
			left++;
		}
		while ((mas[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			mas[right] = mas[left];
			right--;
		}
	}
	mas[left] = pivot;
	pivot = left;
	left = l_border;
	right = r_border;
	if (left < pivot) 
		quick_sort(mas, left, pivot - 1);
	if (right > pivot)
		quick_sort(mas, pivot + 1, right);
}
void selection_sort(int* mas, int n)
{
	int min, temp;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++) 
		{
			if (mas[j] < mas[min])
				min = j;
		}
		temp = mas[i];
		mas[i] = mas[min];
		mas[min] = temp;
	}
}

void clean(int* mas)
{
	free(mas);
}
