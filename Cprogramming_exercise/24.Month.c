#pragma warning(disable: 4996)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char hasalpha(char *number);
int hasdotnumber(char * number);
int getvalid_integer(int minimum, int maximum);
char has_special_character(char * number);

struct month entermonth();
struct month getmonth(struct month p);

struct month
{
	char ** month;
	int month2;
	int error;
	char themonth[10];
};
int main()
{
	entermonth();
	getch();
	return 0;
}
struct month getmonth(struct month p)
{
	int i = 0;
	int j = 0;

	char month2[13][10]= {"January", "February", "March","April","May","June","July","August","September","October","November","December" };
	
	for (i = 0; i < 13; i++)
	{
		if (i == p.month2)
		{
			printf("The month is %s\n", month2[i-1]);
			p.error = 1;
			strcpy(p.themonth,month2[i-1]);
			return p;
		}
	}
}
struct month entermonth()
{
	struct month p;
	struct month u;
	int i = 0;

	printf("Enter the number of month: ");
	p.month2 = getvalid_integer(1, 12);

	u = getmonth(p);
	
	if (u.error == 1)
	{
		printf("The month is %s\n", u.themonth);
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