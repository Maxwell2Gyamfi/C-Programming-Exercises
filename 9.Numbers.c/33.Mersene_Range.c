#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
void mersen_number(int n);
int main()
{
	int n = 0;
	int range = 0;
	printf("Input a upper limit [range from 1 to upper limit]: ");
	scanf("%d", &n);

	while (range < n)
	{
		mersen_number(range);
		range++;
	}
	getch();
	return 0;
}
void mersen_number(int n)
{
	int flag = 0;
	int i = 0;
	int mersene = 0;
	int range = 0;
	range = sqrt(n) + 1;

	for (i = 1;i <= range;i++)
	{
		mersene = pow(2.0, (double)i) - 1;

		if (mersene == n)
		{
			if (get_prime(mersene))
			{
				flag = 1;
				break;
			}
		}

	}
	if (flag == 1)printf("%d ", n);

}
int get_prime(int n)
{
	int prime = 0;
	int i = 0;
	for (i = 1;i <= n;i++)
	{
		if (n%i == 0)
		{
			prime++;
		}
	}
	if (prime == 2)
	{
		return 1;
	}
	return 0;
}