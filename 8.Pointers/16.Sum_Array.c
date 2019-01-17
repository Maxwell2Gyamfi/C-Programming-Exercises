#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int get_numberof_elements(int *size);
void get_elements(int **k, int size);
void get_sum(int *k, int size);
int main()
{
	int size = 0;
	int *k = 0;
	k = get_numberof_elements(&size);
	get_elements(&k, size);
	get_sum(k, size);


	getch();
	return 0;
}
int get_numberof_elements(int *size)
{
	int *k = 0;

	printf("Input the number of elements to store in the array (max 10) : ");
	scanf("%d", &(*size));

	k = (int*)malloc(*size * sizeof(int));
	if (k == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	return k;
}
void get_elements(int **k, int size)
{
	int i = 0;

	printf("\nInput %d elements in the array : ",size);
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("element - %d : ", i+1);
		scanf("%d", &((*k)[i]));
	}
}
void get_sum(int *k, int size)
{
	int sum = 0;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		sum += *(k);
		k++;
	}
	printf("The sum of array is : %d", sum);
}