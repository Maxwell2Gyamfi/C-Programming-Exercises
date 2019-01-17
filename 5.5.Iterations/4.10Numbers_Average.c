#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int get_numbers();
int getvalidnumber(int minimum, int maximum);
char is_special_character(char * number);
char isalphabet(char * number);
int hasdot(char *number);

int main()
{
	get_numbers();
	getch();
	return 0;
}
int get_numbers()
{
	int sum = 0;
	int i = 0;
	int numbers[11];
	float average = 0;

	printf("Input 10 numbers: ");
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("Number %d: ", i + 1);
		numbers[i] = getvalidnumber(0,1000);
		sum += numbers[i];
	}
	printf("\nThe sum of 10 numbers is %d", sum);
	printf("The average is %f", (double)sum / 10);
}

int getvalidnumber(int minimum, int maximum)
{
	static char numbers[10];
	int success = 0;
	int number = 0;

	char ch;

	//while ((ch = getchar()) != '\n' && ch != EOF);

	do {

		scanf("%s", numbers);

		if (hasdot(numbers))
		{
			printf("Floats not allowed\n");
		}
		else if (is_special_character(numbers))
		{
			printf("Special characters not allowed\n");
		}
		else if (isalphabet(numbers))
		{
			printf("Alphabets not allowed\n");
		}
		else
		{
			number = atoi(numbers);
			if ((number < minimum) || number > maximum)
			{
				printf("Out of range\n");
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


	for (j = 0; j < strlen(number); j++)
	{
		if (number[j] == '.')
		{
			return 1;
		}
	}
	return 0;

}
char is_special_character(char * number)
{
	int i = 0;
	int j = 0;
	int lenght = strlen(number);


	for (j = 0; j < lenght; j++)
	{
		if (isalpha(number[j]) || isdigit(number[j]) || number[j] == '-')
		{
			if ((lenght == 1) && (number[j] == '-'))
			{
				return 1;
			}
		}
		else
		{
			return 1;

		}
	}

	return 0;
}
char isalphabet(char * number)
{
	int i = 0;
	int j = 0;
	int lenght = strlen(number) - 1;


	for (j = 0; j <= lenght; j++)
	{
		if (isalpha(number[j]))
		{
			return 1;
		}
	}

	return 0;

}