#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

int get_natural_numbers(int **numbers);
void print_natural_numbers(int *numbers);

int main()
{
	int *numbers;

	get_natural_numbers(&numbers);
	print_natural_numbers(numbers);

	free(numbers);
	getch();
	return 0;
}
int get_natural_numbers(int **numbers)
{
	size_t i = 1;
	size_t size = 10;

	*numbers = (int*)calloc(size, sizeof(int));
	if (*numbers == NULL)
	{
		fputs("Error allocatin memory", stderr);
		exit(0);
	}

	for (i = 1; i <= size; i++)
	{
		(*numbers)[i] = i;
	}
}
void print_natural_numbers(int *numbers)
{
	int sum = 0;
	size_t i = 1;
	size_t size = 10;

	for (i = 1; i <= size; i++)
	{
		sum += numbers[i];
	}
	printf("%d", sum);
}