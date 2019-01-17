#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *get_array_number(int *size);
void bubble_sort_array(int *numbers, int size);
void print_new_values(int *numbers, int size);

int main()
{
	int *numbers;
	int size = 0;

	numbers = get_array_number(&size);
	bubble_sort_array(numbers,size);
	print_new_values(numbers,size);

	free(numbers);
	getch();
	return 0;
}
int *get_array_number(int *size)
{
	int i = 0;
	int *numbers;
	int array_numbers = 0;

	printf("Input number of elements to be stored in array: ");
	scanf("%d", &array_numbers);

	*size = array_numbers;

	numbers = (int*)malloc(array_numbers * sizeof(int));

	if (numbers == NULL)
	{
		printf("Error");
		exit(1);
	}

	printf("Input 5 elements in the array\n");
	for (i = 0; i < array_numbers; i++)
	{
		printf("Element - %d : ",i);
		scanf("%d", &(*(numbers + i)));
	}
	return numbers;

}
void bubble_sort_array(int *numbers, int size)
{

	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0; i < size-1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (*(numbers + i) > (*(numbers + j)))
			{
				temp = *(numbers + i);
				*(numbers + i) = *(numbers + j);
				*(numbers + j) = temp;
			}
		}
	}
}
void print_new_values(int *numbers,int size)
{
	int i = 0;
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("%d\n", numbers[i]);
	}
}