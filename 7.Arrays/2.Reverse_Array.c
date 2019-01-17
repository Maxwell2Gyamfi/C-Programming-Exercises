#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

void get_numberof_elements(int *n);
void get_array_elements(int *numbers, int size);
void print_in_reverse(int *numbers, int size);

int main()
{
	int n = 0;
	int *numbers;

	get_numberof_elements(&n);

	numbers = (int*)calloc(n,sizeof(int));
	if (numbers == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}

	get_array_elements(numbers, n);
	print_in_reverse(numbers, n);

	free(numbers);
	getch();
	return 0;
}
void get_numberof_elements(int *n)
{
	printf("Enter number of elements: ");
	scanf("%d", &(*n));
}
void get_array_elements(int *numbers, int size)
{
	int i = 0;
	printf("Input %d number of elements in array: ", size);
	puts("");
	for (i = 0; i < size; i++)
	{
		printf("Element %d : ", i + 1);
		scanf("%d", &numbers[i]);
	}
}
void print_in_reverse(int *numbers, int size)
{
	int i = 0;

	printf("\nThe values store into the array are : ");
	puts("");
	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}

	printf("\nThe values store into the array in reverse are : ");
	puts("");
	for (i = size-1; i >= 0; i--)
	{
		printf("%d ", numbers[i]);
	}
}
