#pragma warning(disable:4996)

#include <stdio.h>
int sum_series(int start, int sum);
int main()
{
	int sum = 0;
	sum = sum_series(1, 0);

	printf("The sum of the series is : %d", sum);
	getch();

	return 0;
}
int sum_series(int start, int sum)
{
	int factorial = 1;
	int i = 0;
	float a = 0;
	if (start > 5)
	{
		return sum;
	}
	else
	{
			for (i = 1;i <=start;i++)
			{
				factorial *= i;
			}
			sum+= factorial / start;	
		}
		sum_series(start+1, sum, 1);
	}
	

