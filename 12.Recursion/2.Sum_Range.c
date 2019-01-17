#pragma warning(disable:4996)
#include <stdio.h>
int range();
void sum(int i, int range, int sum1);
int start = 0;
int main()
{
	int sum1 = 0;
	int i = 1;

	int range1 = range();
	sum(i, range1,sum1);

	getch();
	return 0;
}
int range()
{
	int range = 0;
	printf("Input the last number of the range starting from 1 : ");
	scanf("%d", &range);
	return range;

}
void sum(int i, int range,int sum1)
{

	if (i > range)
	{
		printf("The sum of the numbers from %d to %d is %d", start, range, sum1);
	}
	else
	{
		i == 1 ? start = 1:1;
		sum1 += i;
		sum(i+1, range, sum1);

	}
}