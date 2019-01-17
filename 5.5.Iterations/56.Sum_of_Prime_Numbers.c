#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

int get_number();
void get_primes(int n);
void get_sum_of_primes(int*primes, int n, int count);

int main()
{
	int n = get_number();
	get_primes(n);

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Enter a number: ");
	scanf("%d", &n);

	return n;
}
void get_primes(int n)
{
	int valid = 0;
	int count = 0;
	int i = 0;
	int j = 0;

	int *prime = (int*)calloc(n, sizeof(int));
	if (prime == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i%j == 0)
			{
				valid++;
			}
		}
		if (valid == 2)
		{
			prime[count] = i;
			count++;
		}
		valid = 0;
	}

	get_sum_of_primes(prime, n, count);
	
	free(prime);
}
void get_sum_of_primes(int*primes,int n,int count)
{

	int i = 0;
	int j = 0;
	int k = 0;


	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (primes[i] + primes[j] == n)
			{
				printf("%d = %d+%d\n",n, primes[i], primes[j]);
				k++;
			}
		}
	}
	if (k == 0)
	{
		printf("Number cannot be Express as Sum of Two Prime Numbers.");
	}
}