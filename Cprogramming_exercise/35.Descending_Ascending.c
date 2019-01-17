#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getvalidnumber(int minimum, int maximum);
char is_special_character(char * number);
char isalphabet(char * number);
int hasdot(char *number);


int *get_numbers(int *size2);
char *decide(int *numbers, int size);

int main()
{
	int size = 0;
	int *numbers = 0;
	char *decision = 0;

	numbers = get_numbers(&size);
	decision = decide(numbers,size);
	
	printf("%s", decision);

	free(numbers);
	getch();
	return 0;
}
int *get_numbers(int *size2)
{
	int i = 0;
	int *numbers = 0;
	int size = 2;

	numbers = (int*)malloc(size * sizeof(int));

	if (numbers == NULL)
	{
		printf("Error");
		exit(1);
	}
	printf("Enter 2 pair of numbers: ");

for (i = 0; i < size; i++)
{
	numbers[i] = getvalidnumber(1, 300);
}
*size2 = size;
return numbers;
}
char *decide(int *numbers, int size)
{
	int i = 0;
	int j = 0;
	static char decision[15];

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (numbers[i] > numbers[j])
			{
				strcpy(decision, "Descending");
				return decision;
			}
		}
	}
	strcpy(decision, "Ascending");
	return decision;
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
		for (j = 0; j < lenght; j++)
		{
			if (isalpha(number[j]) || isdigit(number[j]) || number[j] == '-')
			{

			}
			else
			{
				if (strlen(number) == 1) && (number[j] == '-'))
				{
				}
}
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