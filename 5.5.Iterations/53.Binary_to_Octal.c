#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <math.h>

int get_binary_number();
void get_valid_binary(char *binary);
void get_octal(int n);
int get_decimal(char *n);
int not_binary(char *n);


int main()
{
	int n = 0;
	n = get_binary_number();
	get_octal(n);

	getch();
	return 0;
}
int get_binary_number()
{
	char buffer[10];
	int number = 0;

	printf("Input a binary number: ");
	get_valid_binary(buffer);

	number = get_decimal(buffer);

	return number;
}
void get_valid_binary(char *binary)
{
	char buffer[10];
	int success = 0;

	int i = 0;

	do
	{
		scanf("%s", buffer);

		if (not_binary(buffer))
		{
			printf("Binary numbers are only 0 and 1, try again: ");
		}
		else
		{
			success = 1;
			strcpy(binary, buffer);
		}

	} while (success == 0);
}
int not_binary(char *n)
{
	int success = 0;

	int i = 0;

	for (i = 0; i < strlen(n); i++)
	{
		if (n[i] == '1' || n[i] == '0') {}
		else
		{
			return 1;
		}
	}
	return 0;

}
int get_decimal(char *n)
{
	int counter = 0;
	int i = 0;
	int l = strlen(n)-1;
	int result = 0;

	for (i = l; i >= 0; i--)
	{
		if (n[i] == '1')
		{
			result += pow((double)2, counter);
		}
		counter++;
	}
	return result;

}
void get_octal(int n)
{
	char buffer[10];
	int i = 0;
	int j = 0;
	int numbers[10];
	int counter = 0;
	for (i = 0; n > 0; i++)
	{
		numbers[i] = n % 8;
		n = n / 8;
		counter++;
	}
	for (j = counter-1; j >= 0; j--)
	{
		printf("%d",numbers[j]);
	}
}
