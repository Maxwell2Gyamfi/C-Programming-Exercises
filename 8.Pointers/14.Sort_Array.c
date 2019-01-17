#pragma warning(disable:4996)
void get_numbers(int *numbers, int *size);
void merge_sort(int start, int end, int *numbers);
void merge(int start, int end, int middle, int *numbers);
void print(int numbers[], int size);

#include <stdio.h>
int main()
{
	int size = 0;
	int numbers[20];
	get_numbers(numbers, &size);
	merge_sort(0, size - 1, numbers);
	print(numbers, size);

	getch();
	return 0;
}
void get_numbers(int *numbers, int *size)
{
	int i = 0;
	printf("Input the number of elements to store in the array :");
	scanf("%d", &(*size));

	for (i = 0; i < *size; i++)
	{
		printf("element - %d : ", i);
		scanf("%d", &(*numbers));
		numbers++;
	}
}
void merge_sort(int start, int end, int *numbers)
{
	int middle = 0;
	if (start < end)
	{
		middle = (start + end) / 2;
		merge_sort(start, middle, numbers);
		merge_sort(middle + 1, end, numbers);
		merge(start, end, middle, numbers);
	}
}
void merge(int start, int end, int middle, int *numbers)
{
	int *s = &numbers[0];
	int k = 0;
	int temp[20];
	int i = start;
	int j = middle+1;

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

	for (i = start,k=0; i <= end; i++,k++)
	{
		s[i] = temp[k];
	}
}
void print(int numbers[], int size)
{
	int i = 0;
	printf("\nThe elements in the array after sorting : ");
	printf("\n");

	for (i = 0; i<size; i++)
	{
		printf("\nelement - %d : ", i + 1);
		printf("%d ", numbers[i]);
	}
}