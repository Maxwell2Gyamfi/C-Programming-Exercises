#pragma warning (disable:4996)
#include <stdio.h>
#include <ctype.h>

int getvalidnumber(int minimum, int maximum);
char is_special_character(char * number);
char isalphabet(char * number);
int hasdot(char *number);

int *getnumbers(int *size);
void getbigger_numbeer_index(int *number, int size, int *index, int *biggest);
void print_biggest(int index, int biggest);

int main()
{
	int size = 0;
	int index = 0;
	int biggest = 0;

	int *numbers = getnumbers(&size);

	getbigger_numbeer_index(numbers, size, &index, &biggest);
	print_biggest(index, biggest);
	getch();

	return 0;
}

int *getnumbers(int *size)
{
	*size = 5;
	int i = 0;
	static int numbers[6];

	printf("Enter 5 numbers: ");
	for (i = 0; i < 5;i++)
	{
		numbers[i] = getvalidnumber(0,200);
	}
	return numbers;
}
void getbigger_numbeer_index(int *number, int size, int *index, int *biggest)
{
	int i = 0;
	int j = 0;
	int bigger = 0;
	int index1 = 0;

	for (i = 0; i <size; i++)
	{
		if (number[i] > bigger)
		{
			bigger = number[i];
			index1 = i;
		}
		
	}
	*biggest = bigger;
	*index = index1 + 1;

}
void print_biggest(int index, int biggest)
{

	printf("Highest value: %d", biggest);
	printf("\nPosition: %d", index);

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
			if (isalpha(number[j]) || isdigit(number[j]) || number[j] == '-')
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