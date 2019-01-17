#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char hasalpha(char *number);
int hasdotnumber(char * number);
int getvalid_integer(int minimum, int maximum);
struct numbers bigger(int first, int second);
char has_special_character(char * number);
struct numbers multiplied(int number1, int number2);
struct numbers enter_numbers();

struct numbers
{
	int bigger;
	int smaller;
	int firstnumber;
	int secondnumber;

};

int main()
{
	struct numbers  p;
	
	enter_numbers();

	getch();
	return 0;
}
struct numbers enter_numbers()	
{
	struct numbers p;

	printf("Enter first number: ");
	p.firstnumber= getvalid_integer(1, 1000);
	printf("Enter second number: ");
	p.secondnumber = getvalid_integer(1, 1000);
	multiplied(p.firstnumber, p.secondnumber);

}
struct numbers multiplied(int number1, int number2)
{
	struct numbers p;
	p = bigger(number1, number2);
	if ((p.bigger%p.smaller) == 0)
	{
		printf("Multiplied\n");
	}
	else
	{
		printf("\nNot Multiplied!\n");
	}

}
struct numbers bigger(int first, int second)
{
	struct numbers u;

	if (first > second)
	{
		u.bigger = first;
		u.smaller = second;
	}
	else
	{
		u.smaller = first;
		u.bigger = second;
	}
	return u;
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
		for (j=0; j < size;j++)
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
		for (j = 0; j < size;j++)
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
			if (isalpha(number[j]) || isdigit(number[j]))
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

