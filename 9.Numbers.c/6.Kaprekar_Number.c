#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

void get_kaprekar(int number);
int main()
{
	int number = 0;
	printf("Enter a number : ");
	scanf("%d", &number);
	get_kaprekar(number);

	getch();
	return 0;
}
void get_kaprekar(int number)
{
	int convert = 0;
	int lenght = 0;
	int i = 0;
	int l = 0;
	int s = 0;
	lenght = lenght_number(number);

	char *firsthalf = (char*)calloc(lenght,sizeof(char));
	char  *seconhalf = (char*)calloc(lenght , sizeof(char));

	if (lenght % 2 == 0)
	{
		 s = (lenght / 2)-1;
		 l = (lenght / 2)-1;
	}
	else
	{
		s = (lenght / 2)-1;
	    l = s + 1;
	}

	if (firsthalf == NULL)
	{
		printf("Error");
		exit(0);
	}
	if (seconhalf == NULL)
	{
		printf("Error");
		exit(0);
	}
	int square = number * number;

	while (square)
	{
		if (i < lenght/2)
		{
			convert = square % 10;
			firsthalf[s--] = convert + '0';
		}
		else
		{
			convert = square % 10;
			seconhalf[l--] = convert + '0';
		}
		square = square / 10;
		i++;
	}
	sscanf(firsthalf, "%d", &l);
	sscanf(seconhalf, "%d", &s);
	int sum = s + l;

	if (sum == number)printf("%d is a kaprekar number", number);
	else printf("%d is not a kaprekar number", number);

	free(firsthalf);
	free(seconhalf);
}
int lenght_number(int number)
{
	int count = 0;
	int square = number * number;

	while (square)
	{
		square = square / 10;
		count++;
	}
	return count;
}