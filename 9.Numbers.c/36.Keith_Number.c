#pragma warning(disable:4996)
#include <stdio.h>
int get_lenght(int n);
void keith(int n);
int get_numbers(int*numbers, int count, int n);
int get_sum(int start, int count, int *numbers);
int main()
{

	int n = 0;
	printf("Enter a number: ");
	scanf("%d", &n);
	keith(n);

	getch();
	return 0;
}
void keith(int n)
{
	int flag = 0;
	int start = 0;
	int numbers[100];
	int count = 0;
	int sum = 0;


	count = get_lenght(n);
	get_numbers(numbers, count, n);

	while (sum <= n)
	{
		sum = get_sum(start, count, numbers);
		start++;
		count++;
		if (sum == n)flag = 1;
	}
	if (flag == 1)printf("%d is a Keith number",n);
	else printf("%d is not a Keith number",n);
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
int get_numbers(int*numbers, int count,int n)
{
	while (n)
	{
		numbers[count - 1] = n % 10;
		n = n / 10;
		count--;
	}
}
int get_sum(int start,int count,int *numbers)
{
	int *k = &numbers[0];
	int i = 0;
	int sum = 0;
	for (i = start;i < count;i++)
	{
		sum += numbers[i];
	}
	k[count] = sum;
	return sum;
}