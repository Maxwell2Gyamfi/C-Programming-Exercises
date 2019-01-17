#pragma warning (disable:4996)
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int *sum_all_odd(int odd, int *numbers);
int *getnumbers(int *sizes);
int *sort_odd_numbers(int size, int *numbers);
int getvalid_integer(int minimum, int maximum);
int hasdotnumber(char * number);
char hasalpha(char *number);
char has_special_character(char * number);
int isodd(int *number);

int main()
{

	int *get_numbers = 0;
	int *get_odd_numbers = 0;
	int size = 0;
	int odds_size = 0;
	int sum = 0;


	get_numbers = getnumbers(&size);
	get_odd_numbers = sort_odd_numbers(size, get_numbers);
	sum = sum_all_odd(odds_size, get_odd_numbers);

	printf("%d", sum);
	free(get_numbers);
	getch();
	return 0;
}
int *getnumbers(int *sizes)
{
	int i = 0;
	int size = 15;
	int size2 = 5;
	int *all_numbers = 0;
	*sizes = size2;

	all_numbers = (int*)malloc(size * sizeof(int));

	if (size == NULL)
	{
		printf("Error allocating");
		exit(0);
	}

	printf("Enter five numbers: ");
	for (i = 0; i < 5; i++)
	{
		*(all_numbers+i) = getvalid_integer(0, 1000);

	}
	return all_numbers;

}
int *sort_odd_numbers(int size, int * numbers)
{
	int i = 0;
	int odds = 0;
	static int oddnumbers[6];

	for (i = 0; i < size; i++)
	{
		if (isodd(&numbers[i]))
		{
			*(oddnumbers + i) = *(numbers + i);
			odds++;
		}
	}
	return oddnumbers;
}
int isodd(int *number)
{
	int i = 0;
	for (i = 0; i < 1; i++)
	{
		if (number[i] % 2 == 0)
		{
			return 0;
		}
		return 1;
	}
	
}
int *sum_all_odd(int odd, int *numbers)
{

	int i = 0;
	int sum = 0;

	for (i = 0; i <5; i++)
	{
		sum += *(numbers + i);
	}
	return sum;
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