#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

int merge_sort(int start, int end, int *numbers);
void get_numbers(int **numbers, int size);
int get_array_size();
int get_second_biggest(int *numbers, int size);
void merge_array(int start, int end, int middle, int *numbers);
int get_second_biggest(int *numbers, int size);

int main()
{
	int secondbiggest = 0;

	int size = get_array_size();
	int *numbers = (int*)calloc(size, sizeof(int));

	get_numbers(&numbers, size);
	merge_sort(0, size - 1, numbers);
	secondbiggest = get_second_biggest(numbers,size);

	printf("The Second largest element in the array is : %d", secondbiggest);

	//getch();
	return 0;
}
int get_array_size()
{
	int size = 0;
	printf("Input the size of the array: ");
	scanf("%d", &size);

	return size;
}
void get_numbers(int **numbers, int size)
{
	int i = 0;

	printf("Input %d elements in the array : ", size);
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("element - %d : ",i+1);
		scanf("%d", &((*numbers)[i]));
	}
}
int merge_sort(int start, int end, int *numbers)
{

	int middle = 0;

	if (start < end)
	{
		middle = (start + end) / 2;
		merge_sort(start, middle, numbers);
		merge_sort(middle+1, end, numbers);
		merge_array(start, end, middle, numbers);
	}
}
void merge_array(int start, int end, int middle, int *numbers)
{

	int temp[10];
	int i = start;
	int j = middle + 1;
	int k = 0;
	int *s;

	while (i <= middle && j <= end)
	{
		if (numbers[i] < numbers[j])
		{
			temp[k++] = numbers[i++];
		}
		else
		{
			temp[k++] = numbers[j++];
		}
	}
	if (i >= middle)
	{
		while (j <= end)
		{
			temp[k++] = numbers[j++];
	    }
	}
	if (j >= end)
	{
		while (i <= middle)
		{
			temp[k++] = numbers[i++];
		}
	}

	s = &numbers[0];
	for (i = start, k = 0; k <=end; i++, k++)
	{
		s[i] = temp[k];
	}
}
int get_second_biggest(int *numbers,int size)
{
	int i = 0;
	int flag = 0;
	int secondbiggest = 0;
	int duplicate = size - 1;
	int biggest = numbers[size-1];

	
		while (numbers[duplicate] == biggest)
		{
			duplicate--;

			if (numbers[duplicate] != biggest)
			{
				if (duplicate == -1)
				{
					return biggest;
				}
				else
				{
					secondbiggest = numbers[duplicate];
					return secondbiggest;
				}
			}	
		}
}
