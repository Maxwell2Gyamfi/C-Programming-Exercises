#pragma warning (disable:4996)
#include <stdio.h>
int get_number();
void check_ugly_number(int number);
int main()
{
	int number = 0;
	number = get_number();
	check_ugly_number(number);

	getch();
	return 0;
}
int get_number()
{
	int number = 0;

	printf("Input a number : ");
	scanf("%d", &number);
	return number;
}
void check_ugly_number(int number)
{
	int x = number;

	if (number <= 0) printf("Ugly numbers are positive numbers\n");
	else
	{
		while (x % 2 == 0)
		{
			x = x / 2;
		}
		while (x % 3 == 0)
		{
			x = x / 3;
		
		}
		while (x % 5 == 0)
		{
			x = x / 5;
		}

		if (x == 1) printf("\n%d is an ugly number", number);
		else printf("\n%d is not an ugly number", number);

	}
}