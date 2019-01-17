#pragma warning(disable:4996)
#include <stdio.h>
int get_range();
int get_evens(int i, int end);
int get_odds(int i, int end);
int main()
{
	int i = 1;
	int range = get_range();
	get_evens(i, range);
	get_odds(i, range);

	getch();
	return 0;
}
int get_range()
{
	int n = 0;
	printf("Input a range from 1: ");
	scanf("%d", &n);
	return n;
}
int get_evens(int i,int end)
{
	if (i > end)
	{
		return 1;
	}
	else
	{
		if (i == 1)
			printf("All even numbers from 1 to %d are: ", end);
		if (i % 2 == 0)printf("%d ", i);
		get_evens(i+1,end);
	}
}
int get_odds(int i, int end)
{
	if (i > end)
	{
		return 1;
	}
	else
	{
		if (i == 1)
			printf("All odd numbers from 1 to %d are: ", end);
		if (i % 2 != 0)printf("%d ", i);
		get_odds(i + 1, end);
	}
}