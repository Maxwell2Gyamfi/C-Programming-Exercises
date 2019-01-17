#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_strong_number(int n, int lenght);
int check_lenght(int n);
int get_number();

int main()
{
	get_number();

	getch();
	return 0;
}

int get_number()
{
	int n = 0;
	int lenght = 0;

	printf("Enter number: ");
	scanf("%d", &n);

	lenght = check_lenght(n);
	check_strong_number(n, lenght);

}

int check_strong_number(int n,int lenght)
{
	char buffer[10];

	int i = 0;
	int j = 0;
	int sum = 1;
	int value = 0;
	int total = 0;

	itoa(n, buffer, 10);

	for (i = 0; i < lenght; i++)
	{
		value = buffer[i] - '0';

		for (j = 1; j<=value; j++)
		{
			sum = sum * j;
		}
		total += sum;
		sum = 1;
	}
	if (total == n) printf("%d is a strong number",n);
	else printf("%d is not a strong number", n);

}

int check_lenght(int n)
{
	int digits = 0;

	if (n < 0) n = n * -1;
	
	do
	{
		digits++;
		n = n / 10;
	} while (n);

	return digits;
}