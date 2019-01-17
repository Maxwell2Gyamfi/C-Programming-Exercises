#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

int *getnumbers(int *size);
int *get_remainder_numbers(int size, int *numbers);
void print_remainder_numbers(int *numbers, int size);
int main()
{
	int lenght = 0;
	int lenght2 = 0;

	int *numbers = getnumbers(&lenght);
	int *remainder_numbers = get_remainder_numbers(lenght, numbers);
	print_remainder_numbers(remainder_numbers, lenght);
	free(numbers);
	getch();
	return 0;
}
int *getnumbers(int *size)
{
	int lenght = 500;
	int i = 0;
	*size = lenght;


	int *numbers = (int*)malloc(lenght * sizeof(int));

	for (i = 0; i < lenght; i++)
	{
		numbers[i] = i;
	}
	return numbers;

}
int *get_remainder_numbers(int size, int *numbers)
{
	int i = 0;
	static int numbers_again[200];
	int remainder = 0;
	int specified_number = 0;

	printf("Enter the number: ");
	scanf("%d", &specified_number);

	for (i = 0; i < size; i++)
	{
		if (numbers[i] % specified_number == 3)
		{
			numbers_again[i] = numbers[i];
		}
		else
		{
			numbers_again[i] = 0;
		}
	}
	return numbers_again;
}
void print_remainder_numbers(int *numbers, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (numbers[i] == 0)
		{
		}
		else
		{
			printf("%d\n", numbers[i]);
		}
	}
}