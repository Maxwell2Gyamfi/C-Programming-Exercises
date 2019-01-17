#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int array_elements();
void get_elements(int **n, int amount);
int print_elements(int *n, int amount, int counter);

int main()
{
	int amount = 0;
	int *arr = NULL;

	amount = array_elements();
	get_elements(&arr, amount);
	print_elements(arr, amount, 0);

	getch();
	return 0;
}
int array_elements()
{
	int amount = 0;
	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &amount);
	return amount;
}
void get_elements(int **n, int amount)
{
	int i = 0;
	*n = (int*)calloc(amount, sizeof(int));
	if (*n == NULL)
	{
		printf("Error allocaating");
		exit(0);
	}

	printf("Input %d elements in the array : ", amount);
	printf("\n");
	for (i = 0; i < amount; i++)
	{
		printf("Element - %d: ",i);
		scanf("%d", &((*n)[i]));
	}
}
int print_elements(int *n, int amount,int counter)
{
	if (counter == amount)
	{
		return 1;
	}
	else
	{
		if (counter == 0)
		{
			printf("The elements in the array are : ");
		}
		printf("%d ", n[counter]);
		print_elements(n, amount, counter + 1);
	}
}