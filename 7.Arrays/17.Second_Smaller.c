#pragma warning (disable:4996)

#include <stdio.h>

void insertion_sort(int *numbers, int size);
int get_numbers(int *numbers);
void print_elements(int *numbers, int size);

int main()
{
	int size = 0;
	int numbers[20];
	size = get_numbers(numbers);
	insertion_sort(numbers, size);
	print_elements(numbers, size);

	getch();
	return 0;
}
int get_numbers(int *numbers)
{
	int i = 0;
	int size = 0;
	printf("Input the size of array : ");
	scanf("%d", &size);

	printf("Input 5 elements in the array (value must be <9999) : ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		printf("element - %d : ", i + 1);
		scanf("%d", &numbers[i]);
	}

	return size;
}
void insertion_sort(int *numbers, int size)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *s = &numbers[0];

	for (i = 1; i < size; i++)
	{
		j = i - 1;
		temp = s[i];

		while (j >= 0 && temp < s[j])
		{
			s[j + 1] = s[j];
			j--;
		}
		s[j + 1] = temp;
	}
}
void print_elements(int *numbers, int size)
{
	int k = 0;
	int i = 0;
	int second_smaller = 0;
	int smaller = numbers[0];

	while (numbers[k] == smaller)
	{
		k++;
		if (numbers[k] != smaller)
		{
			if (k >= size)
			{
				printf("The Second smallest element in the array is : %d", smaller);
			}
			else
			{
				second_smaller = numbers[k];
				printf("The Second smallest element in the array is : %d", second_smaller);
			}

		}
		
	}
}
