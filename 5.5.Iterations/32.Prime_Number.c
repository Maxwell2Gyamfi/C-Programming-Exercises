#pragma warning (disable:4996)

#include <stdio.h>

void get_n();
void decide_prime_number(int n);

int main()
{
	get_n();

	getch();
	return 0;
}
void get_n()
{
	int n = 0;
	printf("Input number: ");
	scanf("%d", &n);

	decide_prime_number(n);
}
void decide_prime_number(int n)
{
	int i = 0;
	int prime = 0;

	for (i = 1; i <= n; i++)
	{
		if (n%i == 0)
		{
			prime++;
		}
	}
	if (prime == 2)
	{
		printf("\n%d is a prime number", n);
	}
	else
	{
		printf("\n%d is not a prime number", n);
	}
}