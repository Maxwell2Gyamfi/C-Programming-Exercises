#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

int get_array_size();
int allocate_memory(int size);
void get_elements(int **numbers, int size);
void print_elements(int *numbers, int size);

int main()
{
	int *array = 0;
	int size = 0;

	size = get_array_size();
	array = allocate_memory(size);
	get_elements(&array, size);
	print_elements(array, size);

	getch();
	return 0;
}
int get_array_size()
{
	int size = 0;
	printf("Input the number of elements to store in the array :");
	scanf("%d", &size);
	return size;
}
int allocate_memory(int size)
{
	int *array = (int*)calloc(size, sizeof(int));
	if (array == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	return array;
}
void get_elements(int **numbers, int size)
{
	int i, j = 0;

	printf("\n\nInput %d number of elements in the array : ", size);
	printf("\n");

	for (i = 0; i < size; i++)
	{
		printf("element - %d : ", i+1);
		scanf("%d", &((*numbers)[i]));
	}
}
void print_elements(int *numbers, int size)
{
	printf("\n\nThe elements you entered are :    ");
	printf("\n");
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("element - %d : %d ", i + 1,*(numbers+i));
		printf("\n");
	}

}