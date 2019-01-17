#pragma warning(disable:4996)

#include <stdio.h>

int get_numbers(int *numbers);
int divide_arrays(int *numbers, int start, int end);
void merge_elements(int *numbers, int start, int end, int middle);
void print(int *numbers, int size);

int main()
{
	int numbers[30];
	
	get_numbers(numbers);

	getch();
	return 0;
}
int get_numbers(int *numbers)
{
	int n = 0;
	int i = 0;
	int start = 0;

	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &n);

	printf("Input %d elements in the array : ", n);
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("element - %d : ", i + 1);
		scanf("%d", &numbers[i]);
	}
	
	divide_arrays(numbers, start, n-1);
	print(numbers, n);
}
int divide_arrays(int *numbers,int start,int end)
{
	int middle1 = 0;

	if(start < end)
	{
		middle1 = (start + end) / 2;

		divide_arrays(numbers, start, middle1);
		divide_arrays(numbers, middle1+1, end);
		merge_elements(numbers, start, end, middle1);
	}
}
void merge_elements(int *numbers,int start,int end,int middle)
{

	int i = start;
	int j = middle + 1;
	int temp = 0;
	int k = 0;
	int temparray[20];

	while (i <= middle && j <= end)
	{
		if (numbers[i] < numbers[j])
		{
			temparray[k++] = numbers[i++];
		}
		else
		{
			temparray[k++] = numbers[j++];
		}
	}
	while (i <=middle)
	{
		temparray[k++] = numbers[i++];
	}
	while (j <=end)
	{
		temparray[k++] = numbers[j++];
	}

	for (i = start, k = 0; i <=end; i++, k++)
	{
		numbers[i] = temparray[k];
	}
}
void print(int *numbers, int size)
{
	int i = 0;

	printf("\n");
	printf("Elements of array in sorted ascending order: ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}

}