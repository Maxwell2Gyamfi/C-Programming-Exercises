#pragma warning(disable:4996)
#include <stdio.h>
void get_abundant_range(int firstnumber, int secondnumber);
int main()
{
	int firstnumber = 0;
	int secondnumber = 0;
	printf("Enter first number and last number : ");
	scanf("%d%d", &firstnumber, &secondnumber);
	get_abundant_range(firstnumber, secondnumber);

	getch();
	return 0;
}
void get_abundant_range(int firstnumber, int secondnumber)
{
	int i = 0;
	int j = 0;
	int sum = 0;

	if (firstnumber <= 0)firstnumber = 1;

	for (i = firstnumber;i < secondnumber;i++)
	{
		
		for (j = 1;j < i;j++)
		{
			if (i%j == 0)
			{
				sum += j;
			}
		}
		if (sum > i)printf("%d ", i);
		sum = 0;

	}
}