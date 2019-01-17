#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
int *get_array_number();
void print_numbers(int *numbers);
int main()
{
	int *numbers;
	numbers = get_array_number();
	print_numbers(numbers);
	getch();
	return 0;
}

int *get_array_number()
{
	int i = 0;
	int x = 0;
	static int array[5];

	printf("Enter the number: ");
	scanf("%d", &x);
	for (i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			array[i] = x;
		}
		else
		{
			array[i] = array[i-1] * 3;
		}
	}
	return array;
}
void print_numbers(int *numbers)
{
	int i = 0;
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("n[%d] = %d\n",i,numbers[i]);
	}

}