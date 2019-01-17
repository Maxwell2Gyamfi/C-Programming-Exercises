#pragma warning(disable:4996)
#include <stdio.h>
#define VALUE 6
void get_numbers(int numbers[], int size);
void swap(int *first, int *second);
void swap_numbers(int start, int end, int *numbers);
void print_numbers(int *numbers, int size, int sit);

int main()
{
	int numbers[10];

	get_numbers(numbers, VALUE);
	print_numbers(numbers, VALUE, 1);
	swap_numbers(0, VALUE-1, numbers);
	print_numbers(numbers, VALUE, 0);
	getch();
	return 0;
}
void get_numbers(int numbers[], int size)
{
	int *s = &numbers[0];
	int i = 0;

	
	for (i = 0; i < size; i++)
	{
		printf("Input the value of element %d : ", i + 1);
		scanf("%d", &s[i]);
	}
}
void swap(int *first, int *second)
{
	int temp = 0;
	temp = *first;
	*first = *second;
	*second = temp;
}
void swap_numbers(int start, int end, int *numbers)
{

	if (start < end)
	{
		swap(&numbers[start], &numbers[end]);
		swap_numbers(start + 1, end, numbers);
	}
	//return 0;
}
void print_numbers(int *numbers, int size,int sit)
{
	int i = 0;
	switch (sit)
	{
	case 1:
		printf("\nThe value before swapping are : ");
		break;
	default:
		printf("\nThe value after swapping are : ");
		break;
	}

	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
}
