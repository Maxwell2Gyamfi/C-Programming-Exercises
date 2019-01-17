#pragma warning(disable:4996)
#include <stdio.h>

int get_number();
void decide(int number);
int main()
{
	int number = 0;
	number = get_number();
	decide(number);

	getch();
	return 0;
}
int get_number()
{
	int number = 0;

	printf("Enter a number: ");
	scanf("%d", &number);

	return number;

}
void decide(int number)
{
	if (number % 2 == 0)
	{
		printf("%d is even integer\n",number);
	}
	else
	{
		printf("%d is odd integer\n",number);
	}
}