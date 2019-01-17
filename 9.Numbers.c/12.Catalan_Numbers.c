#pragma warning(disable:4996)
#include <stdio.h>
long int factorial(int n, int sit, int n1);
long int catalan(int n);
int main()
{
	int catalano = 0;
	int count = 0;
	while (count <10)
	{
		catalano = catalan(count);
		count++;
		printf("%d ", catalano);
	}
	getch();
	return 0;
}
long int factorial(int n,int sit,int n1)
{
	int i = 0;
	long int sum = 1;
	switch (sit)
	{
	case 1:
		for (i = 1;i <= n;i++)
		{
			sum *= i;
		}
		return sum;
		break;
	default:
	{
		for (i = n;i > n1;i--)
		{
			sum *= i;
		}
		return sum;
		break;
	}
	}
}
long int catalan(int n)
{
	long int second = 0;
	long int cat = 0;
	
	long int first = 2 * n;
	first = factorial(first,2,n+1);
	second = factorial(n, 1, n + 1);

	cat = first / second;
	return cat;
}