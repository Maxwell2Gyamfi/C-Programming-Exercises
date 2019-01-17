#pragma warning(disable:4996)
#include <stdio.h>

int get_number();
void decide_positive_negative(int number);
int main()
{
	int number = 0;
	number = get_number();
	decide_positive_negative(number);

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
void decide_positive_negative(int number)
{
	if (number >= 0)
	{
		printf("%d is positive integer", number);
	}
	else
	{
		printf("%d is negative integer", number);
	}
}