#pragma warning(disable:4996)
#include <stdio.h>
int get_number();
void get_factorial(int number, int *factorial);
int main()
{
	int value = 0;
	int *number = 0;
	int factorial = 1;
	number = &factorial;

	value = get_number();
	get_factorial(value, number);

	printf("\nThe Factorial of %d is %d",value,*number);
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
void get_factorial(int number, int *factorial)
{
	int i = 0;
	for (i = 1; i <=number; i++)
	{
		*factorial *= i;
	}
}