#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <math.h>

int get_octal(char *n);
void get_valid_octal(char *n);
int valid_number(char *n, int lenght);
void convert_to_binart(char *n, int lenght);

int main()
{
	char n[10];
	int lenght = 0;

	lenght = get_octal(n);
	convert_to_binart(n, lenght);

	getch();
	return 0;
}
int get_octal(char *n)
{
	
	printf("Input an octal number (using digit 0 - 7) : ");
	get_valid_octal(n);

	int lenght = strlen(n);

	return lenght;

}
void get_valid_octal(char *n)
{
	char buffer[10];
	int success = 0;
	int lenght = 0;
	do
	{
		scanf("%s", buffer);
		lenght = strlen(buffer);

		if (valid_number(buffer, lenght))
		{
			printf("Error,octal numbers goes from(0-7),try again: ");
		}
		else
		{
			strcpy(n, buffer);
			success = 1;
		}

	} while (success == 0);

}
int valid_number(char *n,int lenght)
{
	int i = 0;
	int value = 0;

	for (i = 0; i < lenght; i++)
	{
		value = n[i] - '0';
		if (value < 0 || value>7)
		{
			return 1;
		}
	}
	return 0;
}
void convert_to_binart(char *n,int lenght)
{
	int i = 0;
	int value = 0;
	int j = 0;
	int numbers[20];
	int start = 0;
	int square = 0;

	
	for (i = 0; i < lenght; i++)
	{
		value = n[i] - '0';

		for (j = 2; j>=0;j--)
		{
			square = pow((double)2, j);

			if (value >=square)
			{
				numbers[start] = 1;
				value = value - square;
			}
			else
			{
				numbers[start] = 0;
			}
			start++;
		}
	}
	printf("\nThe octal number: %s ",n);
	printf("\nThe equivalent Binary Number: ");
	for (i = 0; i < start; i++)
	{
		printf("%d", numbers[i]);
	}
	

}