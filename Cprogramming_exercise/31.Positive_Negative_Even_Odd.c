#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getnumber();
char *get_positive_negative_even_odd(int number);
int getvalidnumber(int minimum, int maximum);
char is_special_character(char * number);
char isalphabet(char * number);
int hasdot(char *number);
int main()
{
	int number = 0;
	char *names= 0;

	number = getnumber();
	names = get_positive_negative_even_odd(number);
	printf("%s", names);
	getch();
	return 0;
}

int getnumber()
{
	int number = 0;
	printf("Enter the number: ");
	number = getvalidnumber(-200, 200);

	return number;
}
char *get_positive_negative_even_odd(int number)
{
	static char names [6][20] = { "Positive even","Negative even", "Positive odd", "Negative odd","Even" };

	if (number > 0)
	{
		if (number % 2 == 0)
		{
			return names[0];
		}
		else
		{
			return names[2];
		}
	}
	else
	{
		if (number == 0)
		{
			return names[4];
		}
		if (number% -2 == 0)
		{
			return names[1];
		}
		else
		{
			return names[3];
		}
	}

}
int getvalidnumber(int minimum, int maximum)
{
	static char numbers[10];
	int success = 0;
	int number = 0;
	do {

		scanf("%s", numbers);

		if (hasdot(numbers))
		{
			printf("Floats not allowed");
		}
		else if (is_special_character(numbers))
		{
			printf("Special characters not allowed");
		}
		else if (isalphabet(numbers))
		{
			printf("Alphabets not allowed");
		}
		else
		{
			number = atoi(numbers);
			if ((number < minimum) || number > maximum)
			{
				printf("Out of range");
			}
			else
			{
				success = 1;
				return number;
			}
		}

	} while (success == 0);

}
int hasdot(char *number)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < strlen(number); j++)
		{
			if (number[j] == '.')
			{
				return 1;
			}
		}
		return 0;
	}

}
char is_special_character(char * number)
{
	int i = 0;
	int j = 0;
	int lenght = strlen(number);

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j <lenght; j++)
		{
			if (isalpha(number[j]) || isdigit(number[j]) || number[j]=='-')
			{

			}
			else
			{
				return 1;
			}
			
		}
		return 0;
	}
}
char isalphabet(char * number)
{
	int i = 0;
	int j = 0;
	int lenght = strlen(number) - 1;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j <= lenght; j++)
		{
			if (isalpha(number[j]))
			{
				return 1;
			}
		}
	}
	return 0;

}