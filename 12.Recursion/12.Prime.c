#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
int number();
int isprime(int n, int i, int count, int end);
int main()
{
	int count = 0;
	int i = 1;
	double end = 0;

	int n = number();
	end = floor((double)(n/ 2));
	isprime(n, i, count, end);

	getch();
	return 0;
}
int number()
{
	int n = 0;
	printf("Inuput any number: ");
	scanf("%d", &n);
	return n;
}
int isprime(int n,int i,int count,int end)
{
	if (i>=end)
	{
		count == 1 ? printf("%d is a prime number", n) :
			printf("%d is not a prime number", n);
		return 1;
	}
	if (count > 1)
	{
		printf("%d is not a prime number", n);
		return 1;
	}
	else
	{
		if (n%i == 0)
		{
			count++;
		}
		isprime(n, i+1, count,end);

	}
}
