#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_numbers(int *numbers, int *size);
void sort_array(int *numbers[], int size);
void insert_value(int *numbers, int *size);
void sort_new_value_insertion(int **numbers, int size);
void print_numbers(int *numbers, int size);


int main()
{
	int temp[20];
	int *numbers = (int*)calloc(20,sizeof(int));
	
	int size = 0;

	get_numbers(numbers, &size);
	sort_array(&numbers, size);
	memcpy(temp, numbers, sizeof(numbers)*size);
	insert_value(numbers, &size);
	sort_new_value_insertion(&numbers, size);

	printf("\n");
	printf("The exist array list is : ");
	print_numbers(temp, size-1);
	
	printf("After Insert the list is : ");
	print_numbers(numbers, size);

	getch();
	return 0;
}
int get_numbers(int *numbers, int *size)
{
	int n = 0;
	int i = 0;

	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &n);

	printf("Input %d elements in the array : ", n);
	printf("\n");

	for (i = 0; i <n; i++)
	{
		printf("element - %d : ", i);
		scanf("%d", &numbers[i]);
	}
	*size = n;

}
void sort_array(int *numbers[], int size)
{
	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (((*numbers)[i]) >((*numbers)[j]))
			{
				temp = (*numbers)[i];
				(*numbers)[i] = (*numbers)[j];
				(*numbers)[j] = temp;
			}
		}
	}
}
void insert_value(int *numbers, int *size)
{
	printf("Input the value to be inserted : ");
	scanf("%d", &numbers[*size]);

	*size = *size + 1;
}
void sort_new_value_insertion(int **numbers, int size)
{
	int j = 0;
	int i = 0;
	int temp = 0;

	for (i = 1; i < size; i++)
	{
		temp = (*numbers)[i];
		j = i - 1;

		while (temp < ((*numbers)[j]) && j >= 0)
		{
			(*numbers)[j + 1] = (*numbers)[j];
			j--;
		}
		(*numbers)[j + 1] = temp;
	}	
}
void print_numbers(int *numbers, int size)
{
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");
}