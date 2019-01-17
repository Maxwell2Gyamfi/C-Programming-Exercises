#pragma warning(disable:4996)
#include <stdio.h>
int sum(int number, int sum1);
int main()
{
	int sum1 = 0;
	int digit = 0;
	printf("Input a number: ");
	scanf("%d", &digit);
	sum1 = sum(digit, sum1);
	printf("The sum of digits of %d is :  %d", digit, sum1);

	getch();
	return 0;
}
int sum(int number, int sum1)
{
	int temp = 0;
	if (number <= 0)
	{
		return sum1;
	}
	else
	{
		temp = number % 10;
		number = number / 10;
		sum1 += temp;

		sum(number, sum1);
	}

}