#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int number = 0;
	number = get_number();

	if (happy_number(number, 0)) printf("%d is a happy number", number);
	else printf("%d is not a happy number", number);

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Input a number : ");
	scanf("%d", &n);
	return n;
}
int happy_number(int n,int counter)
{

	int sum = 0;
	int remainder = 0;
	if (n == 1)
	{
		return 1;
	}
	if (counter == 20)
	{
		return 0;
	}
	else
	{
		while (n)
		{
			remainder = n % 10;
			n = n / 10;
			sum += remainder*remainder;
		}
		n = sum;
	}
	happy_number(n,counter+1);
}
