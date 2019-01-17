#pragma warning(disable: 4996)

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *get_pair_of_numbers(int *size);
void sort_numbers(int *numbers, int size);
int isodd_number(int number);
int *get_odd_numbers(int *numbers, int *size);
void print_odd_numbers(int *numbers, int size);
int get_sum(int *numbers, int size);


int getvalidnumber(int minimum, int maximum);
char is_special_character(char * number);
char isalphabet(char * number);
int hasdot(char *number);

/*Acceps 2 integers and print the odd numbers between them and also print their sum*/


int main()
{
	int size = 0;
	int size2 = 0;
	int sum = 0;
	int *odd_numbers = 0;
	int *pair_of_numbers = 0;

	pair_of_numbers = get_pair_of_numbers(&size);
	sort_numbers(pair_of_numbers, size);
	odd_numbers = get_odd_numbers(pair_of_numbers, &size2);
	print_odd_numbers(odd_numbers, size2);
	sum = get_sum(odd_numbers,size2);

	printf("Sum =%d", sum);
	getch();
	return 0;
}
int *get_pair_of_numbers(int *size)
{
	int i = 0;
	int pair = 2;
	int *numbers = (int*)malloc(pair * sizeof(int));

	if (numbers == NULL)
	{
		printf("Error allocating memory");
		exit(1);
	}

	printf("Enter the pair of numbers: ");
	for (i = 0; i < 2; i++)
	{
		numbers[i] = getvalidnumber(1, 200);
	}
	*size = pair;
	return numbers;
}
void sort_numbers(int *numbers, int size)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	

	for (i=0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (*(numbers+i) > *(numbers + j))
			{
				temp = *(numbers + i);
				*(numbers + i) = *(numbers + j);
				*(numbers + j) = temp;
			}
		}
	}
}
int *get_odd_numbers(int *numbers, int *size)
{
	int i = 0;
	int size2 = numbers[1];

	int *numbers2 = (int*)malloc(size2 * sizeof(int));

	for (i = numbers[0]; i < numbers[1]; i++)
	{
		if (isodd_number(i))
		{
			numbers2[i] = i;
		}
		else
		{
			numbers2[i] = 0;
		}
	}
	*size = numbers[1];
	return numbers2;

}
void print_odd_numbers(int *numbers,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (numbers[i] <= 0){}

		else
		{
			printf("%d\n", numbers[i]);
		}
	}
}
int get_sum(int *numbers, int size)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < size; i++)
	{
		if (numbers[i] <= 0)
		{
			numbers[i] = 0;
		}
		else
		{
			sum += numbers[i];
		}
	}
	return sum;
}
int isodd_number(int number)
{
	if (number % 2 != 0)
	{
		return 1;
	}
	return 0;
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