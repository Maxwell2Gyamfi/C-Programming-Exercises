#pragma warning(disable:4996)


#include<stdio.h>


void print_numbers(int *n, int size);
void get_numbers(int *numbers1, int *size);
void insertion_algorithm(int *n, int size);

int main()
{
	int numbers[100];
	int size = 0;

	get_numbers(numbers, &size);
	insertion_algorithm(numbers, size);
	print_numbers(numbers, size);

	getch();
	return 0;
}
void get_numbers(int *numbers1, int *size)
{
	int i = 0;
	int n = 0;

	printf("Enter the amount of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &numbers1[i]);
	}

	*size = n;
}
void insertion_algorithm(int *n, int size)
{
	int i = 0;
	int temp = 0;
	int j = 0;

	for (i = 1; i < size; i++)
	{
		temp = n[i];
		j = i - 1;

		while (temp < n[j] && j >= 0)
		{
			n[j+1] = n[j];
			j--;
		}
		n[j+1] = temp;

	}
}
void print_numbers(int *n, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d ", n[i]);
	}
}


