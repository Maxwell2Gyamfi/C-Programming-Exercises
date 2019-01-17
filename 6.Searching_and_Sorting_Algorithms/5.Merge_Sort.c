#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int get_number_of_elements();
int get_array_elements(int n);
int merge_sort(int *n, int min, int max);
void merge(int *n, int min, int middle, int middle2, int max);
void print_elemts(int*n, int size,int *n2);



int main()
{
	int n = 0;
	int *numbers;
	int numbers2[20];

	n = get_number_of_elements();

	numbers = get_array_elements(n);

	memcpy(numbers2, numbers, n*sizeof(numbers));

	merge_sort(numbers, 0, n - 1);
	print_elemts(numbers, n,numbers2);

	getch();
	return 0;
}
int get_number_of_elements()
{
	int n = 0;
	printf("Input number of elements: ");
	scanf("%d", &n);

	return n;
}
int get_array_elements(int n)
{
	int k = 0;
	int i = 0;
	time_t t;
	k = n;

	int *numbers = (int*)calloc(n, sizeof(int));
	srand(time(0));

	if (numbers == NULL)
	{
		fputs("Error allocating memory", stderr);
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		numbers[i] = rand() % 100;
	}
	return numbers;

}
int merge_sort(int *n, int min, int max)
{

	int middle;
	
	if (min < max)
	{
		middle = (min + max) / 2;

		merge_sort(n, min, middle);
		merge_sort(n, middle + 1, max);
		merge(n, min, middle,middle+1, max);
	}
	
}
void merge(int *n, int min, int middle, int middle2, int max)
{
	int temp[20];

	int l = 0;
	int i = min;
	int j = middle2;

	while (i <= middle && j <= max)
	{
		if (n[i] < n[j])
		{
			temp[l++] = n[i++];
		}
		else
		{
			temp[l++] = n[j++];
		}
	}

	while (i <= middle)
	{
		temp[l++] = n[i++];
	}

	while (j <= max)
	{
		temp[l++] = n[j++];
	}
	
	for (l = min,j=0;l<=max; l++,j++)
	{
		n[l] = temp[j];
	}
    
}
void print_elemts(int *n, int size,int *n2)
{
	int i = 0;

	printf("Given array is ");
	printf("\n\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", n2[i]);
	}

	printf("\nSorted array is");
	printf("\n\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", n[i]);
	}
}
