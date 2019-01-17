#pragma warning(disable:4996)
#include <stdio.h>
int count_digit(int digit, int counter);

int main()
{
	int counter = 0;
	int digit = 0;
	printf("Input a number: ");
	scanf("%d", &digit);
	count_digit(digit, counter);
	getch();

	return 0;
}
int count_digit(int digit, int counter)
{
	if (digit <= 0)
	{
		printf("The number of digits in the number is : %d", counter);
	}
	else
	{
		counter++;
		digit = digit / 10;
		count_digit(digit, counter);
	}
}

