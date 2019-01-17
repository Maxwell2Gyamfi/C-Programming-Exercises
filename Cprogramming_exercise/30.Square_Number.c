#pragma warning (disable :4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int getvalid_integer(int minimum, int maximum);
int hasdotnumber(char * number);
char hasalpha(char *number);
char has_special_character(char * number);
int iseven(int number[]);

void print_square_malloc(int * numbers, int range);
void print_square_even_numbers(int *numbers, int range);
//int *geteven_numbers(int *numbers, int range);
int *getnumbers(int *size);
int* getnumbersmalloc(int *range_size);

int main()
{
	int i = 0;
	int *numbers = 0;
	int range = 0;

	numbers = getnumbersmalloc(&range);
	print_square_malloc(numbers,range);
	//int numbers2 = getnumbers(&range);
	//print_square_even_numbers(numbers2, range);

	free(numbers);
	getch();
	return 0;
}

int *getnumbers(int *size)
{
	int i = 0;
	static int numbers[100];
	int range = 0;
	printf("Enter the range: ");
	scanf("%d", &range);

	for (i = 0; i < range; i++)
	{
		if (i% 2 == 0)
		{
			numbers[i] = i;
		}
	}
	*size = range;
	return numbers;
}
int* getnumbersmalloc(int *range_size)
{
	int size = 0;
	int i = 1;

	printf("Enter the range: ");
	scanf("%d", &size);

	int *numbers = (int*)malloc(size * sizeof(int));

	for (i = 1; i < size; i++)
	{
		numbers[i] = i;
	}

	*range_size= size;
	return numbers;

}
void print_square_malloc(int * numbers, int range)
{
	int i = 0;

	for (i = 1; i < range; i++)
	{
		if (iseven(&numbers[i]))
		{
			printf("%d*%d=%d\n",numbers[i],numbers[i],numbers[i]*numbers[i]);
		}
	}
}
int iseven(int number[])
{
	int i = 0;
	for (i = 0; i < 1; i++)
	{
		if (number[i] % 2 == 0)
		{
			return 1;
		}
	}
	return 0;
}
void print_square_even_numbers(int *numbers, int range)
{
	int i = 0;
	for (i = 0; i < range; i++)
	{
		if (numbers[i] == 0) {}
		else
		{
			printf("\n%d^%d=%d", numbers[i], numbers[i], numbers[i] * numbers[i]);
		}
	}
}
int getvalid_integer(int minimum, int maximum)
{
	int success = 0;
	static char numbers[3];
	int number = 0;
	do
	{
		scanf("%s", numbers);
		if (hasdotnumber(numbers))
		{
			printf("Floats not allowed, try again\n");
		}
		else if (hasalpha(numbers))
		{
			printf("Alphabets not allowed, try again\n");
		}
		else if (has_special_character(numbers))
		{
			printf("Speical characters not allowed\n");
		}
		else
		{
			number = atoi(numbers);
			if ((number < minimum) || number > maximum)
			{
				printf("Number out of range\n");
			}
			else
			{
				success = 1;
				return number;
			}
			success = 0;
		}


	} while (success == 0);
}
int hasdotnumber(char * number)
{

	int i = 0;
	int j = 0;
	int size = 0;
	size = strlen(number);

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (number[j] == '.')
			{
				return 1;
			}

		}
	}
	return 0;
}
char hasalpha(char *number)
{

	int i = 0;
	int j = 0;
	int size = 0;
	size = strlen(number);

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (isalpha(number[j]))
			{
				return 1;
			}
		}
	}
	return 0;
}
char has_special_character(char * number)
{
	int i = 0;
	int j = 0;
	int size = 0;
	size = strlen(number);

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (isalpha(number[j]) || isdigit(number[j]) || number[j] == '-')
			{
			}
			else
			{
				return 1;
			}
		}
	}
	return 0;
}