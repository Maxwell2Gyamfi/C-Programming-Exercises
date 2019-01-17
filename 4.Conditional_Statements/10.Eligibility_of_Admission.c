#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int *get_marks();
void decide_elegibility(int *marks);

int getvalidnumber(int minimum, int maximum);
int hasdot(char *number);
char is_special_character(char * number);
char isalphabet(char * number);

int main()
{
	int *marks;
	marks = get_marks();
	decide_elegibility(marks);
	
	getch();
	return 0;
}
int *get_marks()
{
	int i = 0;
	static int marks[8];
	char subjects[4][13] = { "Physics","Chemistry","Mathematics" };


	printf("Marks Input\n");
	printf("--------------\n");


	for (i = 0; i < 3; i++)
	{
		printf("Input the marks obtained in %s : ", subjects[i]);
		marks[i] = getvalidnumber(0, 100);
	}
	return marks;
}

void decide_elegibility(int *marks)
{
	int i = 0;
	int j = 0;
	int l = 0;

	for (i = 0; i < 3 - 2; i++)
	{
		for (j = i + 1; j < 3 - 1; j++)
		{
			for (l = i + 2; l < 3; l++)
			{
				if (((marks[i] >= 55) && (marks[j] >= 50) && marks[l] >= 65))
				{
					fputs("\nThe candidate is eligible for admission.", stdout);
				}
				else if ((marks[i] + marks[j] + marks[l] >= 180) || ((marks[i] + marks[l] >= 140)))
				{
					fputs("\nThe candidate is eligible for admission.", stdout);
				}
				else
				{
					fputs("\nThe candidate is not eligible for admission.", stdout);
				}
			}
		}
	}


}



/*******************************************************************
-Functions which checks for the presence of a vialid input integer

-Will loop until one is inputted

-Will report every error a user commits such as special, characters
  floats and alphabest

-Also checks the range of inputted integer

********************************************************************/
int getvalidnumber(int minimum, int maximum)
{
	static char numbers[10];
	int success = 0;
	int number = 0;

	do {

		scanf("%s", numbers);//reads input as string

		if (hasdot(numbers))//checks if is a float
		{
			printf("Floats not allowed, input a valid integer: ");
		}
		else if (is_special_character(numbers))//checks if special character
		{
			printf("Special characters not allowed, input a valid integer: ");
		}
		else if (isalphabet(numbers))//checks if is an alphabet
		{
			printf("Alphabets not allowed, input a valid integer: ");
		}
		else
		{
			number = atoi(numbers);//converts string input to integer
			if ((number < minimum) || number > maximum)//checks for the range
			{
				printf("Out of range, input a valid integer: ");
			}
			else
			{
				success = 1;//quit loop and return valid number
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