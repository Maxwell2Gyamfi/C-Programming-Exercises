#pragma warning (disable:4996)
#include <stdio.h>

void get_n();
double sum(int n);

int main()
{

	get_n();

	getch();
	return 0;
}
void get_n()
{
	double sum1 = 0.0;
	int n = 0;

	printf("Enter n terms: ");
	scanf("%d", &n);

	sum1 = sum(n);

	printf("\nSum of Series upto %d terms: %lf",n,sum1);
}
double sum(int n)
{
	int i = 0;
	double sum = 0;

	for (i = 1; i <= n; i++)
	{
		if (i == n)printf("1/%d", i);
		else printf("1/%d + ", i);

		sum += 1.0/i;
	}
	return sum;
}