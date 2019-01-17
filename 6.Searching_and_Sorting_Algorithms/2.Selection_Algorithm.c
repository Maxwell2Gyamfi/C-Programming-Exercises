#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

void get_array_elements(int **n, int *size);
int get_biggest(int *n, int size, int *index);
void swap_elements(int**n, int size, int index);
void selection(int*n, int size);
void print_sorted_elements(int*n, int size);

int main()
{
	int *n;
	int size = 0;

	get_array_elements(&n,&size);
	selection(n, size);
	print_sorted_elements(n, size);

	free(n);
	getch();
	return 0;
}
void get_array_elements(int **n,int *size)
{
	int i = 0;
	int nsize = 0;
	printf("Enter how many elements the array will contain: ");
	scanf("%d", &nsize);

	*n = (int*)calloc(n, sizeof(int));
	if (*n == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	printf("Enter %d elements into array: ",nsize);
	for (i = 0; i < nsize;i++)
	{
		scanf("%d", &((*n)[i]));
	}
	*size = nsize;
}
int get_biggest(int *n,int size,int *index)
{
	int i = 0;
	int bigger = -100;

	for (i = 0; i < size; i++)
	{
		if (n[i] > bigger)
		{
			bigger = n[i];
			*index = i;
		}
	}
	return bigger;
}
void swap_elements(int**n, int size,int index)
{

	int temp = 0;

	temp = (*n)[size-1];
	(*n)[size - 1] = (*n)[index];
	(*n)[index] = temp;

}
void selection(int*n, int size)
{
	int i = 0;
	int bigger = 0;
	int index = 0;

	do
	{
		bigger = get_biggest(n, size,&index);
		swap_elements(&n, size, index);

		size--;

	} while (n[0] != bigger);

}
void print_sorted_elements(int*n, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d ", n[i]);
	}

}