#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char hasalpha(char *number);
int hasdotnumber(char * number);
int getvalid_integer(int minimum, int maximum);
char has_special_character(char * number);
int read_numbers(int *lenght);
void decide_numbers(int *numbers, int lenght, int *postive, int *negative);
void print_out_numbers(int first, int second);

int main()
{

	int positive = 0;
	int negative = 0;
	int *numbers_read = 0;
	int lenght = 0;

	
	numbers_read = read_numbers(&lenght);
	decide_numbers(numbers_read, lenght, &positive,&negative);
	print_out_numbers(positive, negative);

	free(numbers_read);
	getch();
	return 0;
}

int read_numbers(int *lenght)
{
	int size = 5;
	int i = 0;
	*lenght = size;

	int *save_numbers = 0;

	save_numbers = (int*)malloc(size * sizeof(int));
	if (save_numbers == NULL)
	{
		printf("Error occured");
		exit(0);
	}

	for (i = 0; i < size; i++)
	{
		*(save_numbers + i) = getvalid_integer(-100,100);
	}
	return save_numbers;

}
void decide_numbers(int *numbers, int lenght, int *positive, int *negative)
{
	int i = 0;
	int negative_number = 0;
	int positive_number = 0;

	for (i = 0; i < lenght; i++)
	{
		if (numbers[i] < 0)
		{
			negative_number++;
		}
		else
		{
			positive_number++;
			
		}
	}
	*positive = positive_number;
	*negative = negative_number;
}
void print_out_numbers(int first, int second)
{
	printf("Number of positive numbers %d", first);
	printf("\nNumber of negative numbers %d", second);
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
			if (isalpha(number[j]) || isdigit(number[j]) || number[j]=='-')
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