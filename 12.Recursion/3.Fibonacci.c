#pragma warning(disable:4996)
#include <stdio.h>

int fibonacci(int first, int second, int count, int sum);
int range();

int main()
{
	int range1 = range();
	fibonacci(1, 1, range1-2, 0);

	getch();
	return 0;
}
int fibonacci(int first,int second,int count,int sum)
{
	if (count == 0)
	{
		return 1;
	}
	else
	{
		sum = first + second;

		printf("%d ",sum);
		first = second;
		second = sum;

		fibonacci(first, second, count - 1, sum);
	}
}
int range()
{
	int range1 = 0;

	printf("Input number of terms for the Series (< 20): ");
	scanf("%d", &range1);

	return range1;
}