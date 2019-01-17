#pragma warning(disable:4996)
#include <stdio.h>
#include<math.h>
int get_lenght(int n);
int disarium(int n, int count);
int main()
{
	disarium(1, 0);

	getch();
	return 0;
}
int get_lenght(int n)
{
	int count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return count;
}
int disarium(int n,int count)
{
	int remainder = 0;
	int i = 0;
	int k = n;
	int lenght = get_lenght(n);
	int sum = 0;

	if (count == 1000)
	{
		return 1;
	}
	for (i = lenght;i > 0;i--)
	{
		remainder = k % 10;
		sum += pow((double)remainder,(double) i);
		k = k / 10;
	}
	if (sum == n)
	{
		printf("%d ", n);
	}
	disarium(n + 1, count + 1);
}