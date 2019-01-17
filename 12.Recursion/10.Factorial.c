#pragma warning(disable:4996)
#include <stdio.h>
int number();
int factorial(int n, int sum, int i);
int main()
{
	int sum = 1;
	int number1 = 0;
	number1 = number();
	sum = factorial(number1,sum, 1);
	printf("The factorial of %d is: %d ", number1, sum);
	getch();
	return 0;
}
int number()
{

	int n = 0;
	printf("Input a number: ");
	scanf("%d", &n);
	return n;
}
int factorial(int n, int sum,int i)
{
	if (i > n)
	{
		return sum;
		
	}
	else
	{
		sum *= i;
		factorial(n, sum, i + 1);
	}

}