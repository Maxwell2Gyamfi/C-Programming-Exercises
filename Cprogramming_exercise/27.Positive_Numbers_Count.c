#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>

int sort_all_numbers(int amount, int **numbers);
int *decide_positive_numbers(int amount, int *numbers, int *positives);
int *getnumbers(int *amount);
int getavearge(int *numbers, int amount);
void print_all_poitives(int *numbers, int amount);
int getvalid_integer(int minimum, int maximum);
int hasdotnumber(char * number);
char hasalpha(char *number);
char has_special_character(char * number);

int main()
{
	int *allnumbers = 0;
	int amount = 0;
	int average = 0;
	int amount_positive_numbers = 0;
	int *all_positive_numbers = 0;
	

	allnumbers = getnumbers(&amount);
	all_positive_numbers = decide_positive_numbers(amount, allnumbers, &amount_positive_numbers);
	print_all_poitives(all_positive_numbers,amount);
	average = getavearge(all_positive_numbers,amount);
	printf("Average of positive numbers is %d", average);

	free(allnumbers);
	getch();
	return 0;
}
int *getnumbers(int *amount)
{
	int i = 0;
	int *numbers = 0;
	int size = 25;
	
	numbers = (int*)malloc(size * sizeof(int));
	printf("Enter 5 numbers: ");
	for (i = 0; i < 5; i++)
	{
		*(numbers + i) = getvalid_integer(-100, 400);
	}

	*amount = 5;
	return numbers;

}
int *decide_positive_numbers(int amount, int *numbers, int *positives)
{
	int positive = -1;
	static int positive_numbers[6];
	int i = 0;
	
	for (i = 0; i < amount; i++)
	{
		if (*(numbers + i) > 0)
		{
			positive_numbers[i] = *(numbers + i);
			positive++;
		}
	}
	*positives = positive;
	sort_all_numbers(amount, &positive_numbers);
	return positive_numbers;

}
int getavearge(int *numbers, int positive)
{
	int i = 0;
	int average = 0;
	int positives = -1;

	for (i = 0; i < positive; i++)
	{
		if ((*numbers + i) > 0)
		{
			average += *(numbers + i);
			positives++;
		}
	
	}
	return average / positives;

}
void print_all_poitives(int *numbers,int amount)
{
	int i = 0;
	for (i = 0; i < amount; i++)
	{
		printf("%d ", *(numbers + i));
	}
}
int sort_all_numbers(int amount, int **numbers)
{
	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < amount; i++)
	{
		for (j = i; j < amount; j++)
		{
			if (*(numbers + i) < *(numbers + j))
			{
				temp = *(numbers + i);
				*(numbers + i) = *(numbers + j);
				*(numbers + j) = temp;
			}
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