#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <math.h>

void get_number(char *number, int *lenght1);
void verify_armstrong_number(char *number, int lenght);

int main()
{
	int lenght = 0;
	char number[10];
	get_number(number, &lenght);
	verify_armstrong_number(number, lenght);

	getch();
	return 0;
}
void get_number(char *number, int *lenght1)
{
	int lenght = 0;
	int number1=0;
	char buffer[10];

	fputs("Input a number: ", stdout);
	scanf("%d", &number1);

	sprintf(buffer, "%d", number1);
	lenght = strlen(buffer);
	strcpy(number, buffer);

	*lenght1 = lenght;
}
void verify_armstrong_number(char *number,int lenght)
{
	int sum = 0;
	int i = 0;
	int value2 = 0;
	int value = 0;

	sscanf(number, "%d", &value2);

	for (i = 0; i < lenght; i++)
	{
		value = number[i] -'0';
		sum += pow((double)value, lenght);
	}
	if (sum == value2)
	{
		printf("%d is an Armstrong number", value2);
	}
	else
	{
		printf("%d is not an Armstrong number", value2);
	}
}