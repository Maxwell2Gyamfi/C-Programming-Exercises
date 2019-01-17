#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
void get_numbers(int *n1, int *n2);
void get_amicable(int n1, int n2);
int loop_sum(int n);
int main()
{
	int n1, n2 = 0;
	get_numbers(&n1, &n2);
	get_amicable(n1, n2);
	getch();

	return 0;
}
void get_numbers(int *n1, int *n2)
{
	printf("Input 1st and 2nd number : ");
	scanf("%d%d", n1, n2);
}
void get_amicable(int n1, int n2)
{
	int sum1, sum2 = 0;

	sum1 = loop_sum(n1);
	sum2 = loop_sum(n2);

	if (sum1 == n2 && sum2 == n1)
	{
		printf("The given numbers are an Amicable pair.");
	}
	else
	{
		printf("The given numbers are not an Amicable pair.");
	}
}
int loop_sum(int n)
{
	int sum = 0;
	int i = 0;
	for (i = 1;i <n/2+1;i++)
	{
		if (n%i == 0)
		{
			sum += i;
		}
	}
	return sum;

}