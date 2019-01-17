#pragma warning(disable:4996)
#include <stdio.h>
int get_sum(int n);
int harshad_number(int range, int number);
void get_range(int *range);
int main()
{

	int range = 0;
	get_range(&range);
	harshad_number(range, 1);

	getch();
	return 0;
}
void get_range(int *range)
{
	printf("Input the range : ");
	scanf("%d", range);
}
int harshad_number(int range,int number)
{
	int sum = 0;
	sum = get_sum(number);
	if (number == range+1)
	{
		return 1;
	}
	if (number%sum==0)
	{
		printf("%d ", number);
	}
    harshad_number(range, number + 1);
	
}
int get_sum(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}