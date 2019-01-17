#pragma warning(disable:4996)
#include <stdio.h>
int get_number();
int isodd_even(int n);
int main()
{
	int n = get_number();

	isodd_even(n) ? printf("The number is even") :
		                      printf("The number is odd");

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Input a number: ");
	scanf("%d", &n);
	return n;
}
int isodd_even(int n)
{
	return (n % 2 == 0 ? 1 : 0);
}