#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int *get_numbers(int *size);
void calculations(int *numbers, int size_array);
int bubble_sort(int *numbers, int size_array);
void print_results(int add, int sub, int mul, int div);

char yes_or_no();

int main()
{
	int size = 0;
	int *numbers;
	char input;

	
	get_numbers(&size);

	getch();
	return 0;
}
int *get_numbers(int *size)
{
	int success = 0;
	int i = 0;
	char c[2];
	char input = 0;
	static int numbers[3];

	do
	{
		printf("Input any two numbers separated by comma: ");

		for (i = 0; i < 2; i++)
		{
			scanf("%d %c", &numbers[i], &c[i]);

			if ((c[i] == ',') || (c[1] == '\n')) {}

			else
			{
				printf("Incorrect sign, would you like to try again?(Y/N)?: ");
				input = yes_or_no();

			}
		}
	} while (input == 'Y');

	*size = 2;

	bubble_sort(numbers, *size);
	calculations(numbers, *size);
}
int bubble_sort(int *numbers,int size_array)
{
	int i = 0;
	int j = 0;
	int temp;

	for (i = 0; i < size_array-1; i++)
	{
		for (j = i + 1; j < size_array; j++)
		{
			if (*(numbers + i) < (*(numbers + j)))
			{
				temp = *(numbers + i);
				*(numbers + i) = *(numbers + j);
				*(numbers + j) = temp;
			}
		}
	}
}
void calculations(int *numbers, int size_array)
{
	int i = 0;
	int j = 0;
	int add, sub, mul, div = 0;
	
	for (i = 0; i < 2-1; i++)
	{
		for (j = i + 1; j < 2; j++)
		{
			add = numbers[i] + numbers[j];
			sub = numbers[i] - numbers[j];
			mul = numbers[i] * numbers[j];
			div = numbers[i] / numbers[j];
		}
	}
	print_results(add, sub, mul, div);
}
void print_results(int add, int sub, int mul, int div)
{
	printf("The sum of the given numbers : %d\n",add);
	printf("The difference of the given numbers : %d\n",sub);
	printf("The product of the given numbers : %d\n",mul);
	printf("The quotient of the given numbers : %f",(float)div);

}
char yes_or_no()
{
	int success = 0;
	char input;
	char buffer[5];

	do
	{
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%c", &input);

		input = toupper(input);

		if ((input == 'Y') || (input == 'N'))
		{
			success = 1;
			return input;
		}
		else
		{
			fputs("Incorrect input, try again: ", stderr);
		}

	} while (success == 0);

}