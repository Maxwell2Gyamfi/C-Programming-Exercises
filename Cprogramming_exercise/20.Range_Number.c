#pragma warning (disable: 4996)

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int get_valid_integer(int minimum, int maximum);
void ranges(int number);
int getvalidinteger_maxwell(int minimum, int maximum);
int hasdot(char * name);
int main()
{
	int item = 0;
	item = getvalidinteger_maxwell(0, 80);
	ranges(item);
	getch();

	return 0;
}
int get_valid_integer(int minimum, int maximum)
{
	int item_read = 0;
	int input = 0;
	int success = 0;
	int i = 0;
	int j = 0;

	do {
		

		 printf("Enter a digit: ");
		 item_read = scanf("%d", &input);
		 fflush(stdin);

		if (item_read == 0)
		{
			printf("Must be a number");
		}
		else if (input != (int)(input))
		{
			printf("Must be an integer");
		}
		else if (input <minimum || input > maximum)
		{
			printf("Out of range");
		}
		else
		{
			success = 1;
		}

	} while (success == 0);

	return input;

}
void ranges(int number)
{
	if (number >= 0 || number < 20)
	{
		printf("Range[0,20]");
	}
	else if (number >= 20 || number < 40)
	{
		printf("Range[20,40]");
	}
	else if (number >= 40 || number < 60)
	{
		printf("Range[40,60]");
	}
	else
	{
		printf("Range[60,80]");
	}
}
int getvalidinteger_maxwell(int minimum, int maximum)
{
	char number[20];
	
	int success = 0;
	int i = 0;
	int j = 0;
	int input = 0;
	do
	{
		printf("Enter a number please : ");
		scanf("%s", number);

		if (hasdot(number))
		{
			printf("Floats not allowed\n");
		}
		else if (isalpha(number[0]))
		{
			printf("No alphabets\n");
		}
		else
		{
			input = atoi(number);

			if (input < minimum || input > maximum)
			{
					printf("Out of range\n");
			}
			else
			{
					success = 1;
					return input;
			}
		}	
	} while (success == 0);
}
int hasdot(char * name)
{
	int success = 0;
	int i = 0;
	int j = 0;
	
		if (strlen(name) > 0)
		{
			for (i = 0; i < 1; i++)
			{
				for (j = 0; j < strlen(name) - 1; j++)
				{
					if (name[j] == '.')
					{
						return 1;
					}
				}
			}
		}
		return 0;
}

