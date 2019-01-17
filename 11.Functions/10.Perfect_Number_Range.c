#pragma warning(disable:4996)
#include <stdio.h>
int perfect(int n, int sum);
int main()
{
	int sum = 0;
	int n = 1;

	perfect(n, sum);
	getch();

	return 0;

}
int perfect(int n,int sum)
{
	int i = 0;

	if (sum == n)
	{
		printf("%d ", n);
	}
	if (n == 100)
	{
		return 1;
	}
	else
	{
		n = n + 1;
		sum = 0;
		for (i = 1; i < n / 2+1; i++)
		{
			n%i == 0 ? sum += i : 0;
		}
		perfect(n,sum);
	}	
}