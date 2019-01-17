#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remove_duplicates(int *size, int arr[]);
int get_numbers(int *size, int **arr);
void sort(int size, int *arr);
void print(int *arr, int size);

int main()
{
	int *arr = 0;
	int size = 0;

	get_numbers(&size, &arr);
	remove_duplicates(&size, arr);
	printf("\n\n");

	printf("The array after removing duplicates: ");
	print(arr, size);
	printf("\nAfter removing duplicates the array size is %d", size);
	getch();
	return 0;
}
int get_numbers(int *size,int **arr)
{
	size_t i;
	srand(time(NULL));
	printf("Input array size: ");
	scanf("%d", size);

	*arr = (int*)malloc(*size* sizeof(int));
	if (*arr == NULL)
	{
		perror("Error: ");
		exit(0);
	}
	for (i = 0; i < *size; i++)
	{
		(*arr)[i] = rand() % 6;
	}
}
void sort(int size, int *arr)
{
	int i = 0;int temp = 0;int j = 0;

	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (temp < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
void print(int *arr,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
void remove_duplicates(int *size, int arr[])
{
	int v = 0;int i = 0;int x = 0;int j = 0;
	int u = 0;int size2 = *size;int temp = 0;
	int *m = &arr[0];

	sort(size2, arr);
	print(arr, size2);

	for (i = 0; i < size2; i++)
	{
		x = arr[i];

		for (j = i+1; j <size2; j++)
		{
			while (x == arr[j])
			{
				u = 0;
				v = i;
				while (u < size2)
				{
					temp = m[v];
					m[v] = m[v + 1];
					m[v + 1] = temp;
					v++;u++;
				}
				size2 = size2 - 1;
			}
			if (x < arr[j]) break;
		}
	}
	*size = size2;
}
