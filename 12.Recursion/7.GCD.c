#pragma warning(disable:4996)
#include <stdio.h>
int get_numbers(int *first, int *second);
int get_gcd(int smaller_number, int i, int first, int second, int gcd);
int main()
{
	int smaller_number = 0;
	int i = 0;
	int first = 0;
	int second = 0;
	int gcd = 0;

	smaller_number = get_numbers(&first, &second);
	gcd = get_gcd(smaller_number, i + 1, first, second, gcd);

	printf("The GCD of %d and %d is: %d", first, second, gcd);
	getch();
	return 0;
}
int get_numbers(int *first, int *second)
{

	printf("Input first number: ");
	scanf("%d", first);
	printf("Input second number : ");
	scanf("%d", second);
	return (*first < *second ? *first : *second);
}
int get_gcd(int smaller_number, int i, int first, int second,int gcd)
{
	if (i > smaller_number)
	{
		return gcd;
	}
	else
	{
		if (first%i == 0 && second%i == 0)
		{
			gcd = i > gcd ?i:gcd;
		}
		get_gcd(smaller_number, i + 1, first, second, gcd);
	}
}