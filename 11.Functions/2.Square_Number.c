#pragma warning(disable:4996)
#include <stdio.h>
int get_number();
int square(int *number);
int main()
{
	int number = get_number();
	int a = number;
	square(&number);
	printf("The square of %d is %d",a, number);

	return 0;
}
int get_number()
{
	int number = 0;
	printf("Enter a number: ");
	scanf("%d", &number);

	return number;
}
int square(int *number)
{
   *number = *number * *number;
}