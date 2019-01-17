#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
int allocate_memory(int size);
void get_numbers_and_largest(int **numbers, int size);
int main()
{
	int *m = 0;
	int size = 0;
	printf("\nInput total number of elements(1 to 100): ");
	scanf("%d", &size);
	printf("\n");
	m = allocate_memory(size);
	get_numbers_and_largest(&m, size);

	getch();
	return 0;
}
int allocate_memory(int size)
{
	int *m = (int*)malloc(size * sizeof(int));
	if (m == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	return m;
}
void get_numbers_and_largest(int **numbers, int size)
{
	int temp = 0;
	int biggest = 0;
	int i = 0;


	for (i = 0; i < size; i++)
	{
		printf("Number %d : ", i + 1);
		scanf("%d", &((*numbers)[i]));
		temp = ((*numbers)[i]);
		if (temp >= biggest) biggest = temp;
	}
	printf("\nThe Largest element is :%d", biggest);
}