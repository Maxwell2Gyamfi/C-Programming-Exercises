#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

int get_array_elements(int *size);
void bubblesort(int**numbers, int size);
void print_sorted_numbers(int *numbers, int size);

int main()
{
	int size = 0;
	int *numbers = 0;

	numbers = get_array_elements(&size);
	bubblesort(&numbers, size);
	print_sorted_numbers(numbers, size);

	free(numbers);
	getch();
	return 0;
}
int get_array_elements(int *size)
{
	int n = 0;
	int i = 0;

	printf("Enter amount of elements: ");
	scanf("%d", &n);

	int *numbers = (int*)calloc(n, sizeof(int));
	if (numbers == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}

	printf("Input %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &numbers[i]);
	}
	*size = n;
    
	return numbers;
}
void bubblesort(int**numbers,int size)
{
	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < size-1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (((*numbers)[i]) > ((*numbers)[j]))
			{
				temp = (*numbers)[i];
				(*numbers)[i] = (*numbers)[j];
				(*numbers)[j] = temp;
			}
		}
	}
}
void print_sorted_numbers(int *numbers, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
}