#pragma warning (disable:4996)
#include <stdio.h>
int get_m();
void make_decision(int m);
char yes_or_no();

int main()
{
	get_m();

	getch();
	return 0;
}
int get_m()
{
	char again;
	int m = 0;
	char buffer[5];

	do
	{
		printf("Enter value of m: ");

		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%d", &m);

		make_decision(m);

		fputs("Would you like to try again?(Y/N): ",stdout);
		again = yes_or_no();

	} while (again == 'Y');

}
void make_decision(int m)
{
	if (m > 0)
	{
		puts("The value of n is 1",stdout);
	}
	else if (m == 0)
	{
		puts("The value of n is 0", stdout);
	}
	else
	{
		puts("The value of n is -1", stdout);
	}
}
char yes_or_no()
{
	int success = 0;
	char input;
	char buffer[5];

	do
	{
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%c", &input);

		input = toupper(input);

		if ((input == 'Y') || (input == 'N'))
		{
			success = 1;
			return input;
		}
		else
		{
			fputs("Incorrect input, try again: ", stderr);
		}

	} while (success == 0);

}