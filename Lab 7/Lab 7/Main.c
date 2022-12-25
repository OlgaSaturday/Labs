#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main ()
{
	void (* task) (void);
	int num;
	printf("Choose num (1 or 2) ");
	num = check_num();
	printf("\n");

	switch (num)
	{
	case 1: task = main1;
		task();
		break;
	case 2: task = main2;
		task();
		break;
	}
	getchar();
}