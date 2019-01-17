#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

void print_numbers(int *numbers, int size);
int *get_array_size(int *size);
int get_numbers(int *numbers, int size);
int main()
{
	int size = 0;
	int*arraysize = get_array_size(&size);
	get_numbers(arraysize,size);
	print_numbers(arraysize, size);
	free(arraysize);
	getch();
	return 0;
}
int *get_array_size(int *size2)
{
	int *numbers;
	int size = 7;
	*size2 = size;
	numbers = (int*)malloc(size * sizeof(int));

	if (numbers == 0)
	{
		printf("Error");
		exit(1);
	}
	return numbers;
}
int get_numbers(int *numbers, int size)
{
	int i = 0;

	printf("Enter 5 numbers: ");
	for (i = 0; i < 5; i++)
	{
		scanf("%d",&(*(numbers+i)));
	}
}
void print_numbers(int *numbers, int size)
{
	int i = 0;
	int *p  =(int*)malloc(6 * sizeof(int));

	p= &numbers[0];

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		if (numbers[i] <= 0)
		{
			p[i] = 100;
		}
		printf("n[%d]= %d\n", i, *(numbers+i));
	}
}