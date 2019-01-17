#pragma warning(disable:4996)
#include <stdio.h>

int get_number();
void leap_year(int number);

int main()
{
	int number = 0;
	number = get_number();
	leap_year(number);

	getch();
	return 0;
}
int get_number()
{
	int number = 0;
	printf("Enter the number: ");
	scanf("%d", &number);

	return number;

}
void leap_year(int number)
{
	if (number % 4 == 0)
	{
		printf("%d is a leap year", number);
	}
	else
	{
		printf("%d is not a leap year", number);
	}
}