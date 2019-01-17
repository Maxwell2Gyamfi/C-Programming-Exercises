#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int sum_loop(int n);
int get_pair(int *n, int number);
int get_numbers(int *n);
int main()
{
	int size = 0;
	int numbers[20];
	size = get_numbers(numbers);
	get_pair(numbers,size);

	getch();
	return 0;
}
int get_numbers(int *n)
{
	int i = 0;
	int number = 0;
	printf("Input the number of elements to be stored in the array: ");
	scanf("%d", &number);

	for (i = 0;i < number;i++)
	{
		printf("element - %d : ", i);
		scanf("%d", &n[i]);
	}
	return number;
}
int get_pair(int *n,int number)
{
	int sum1 = 0;
	int sum2 = 0;
	int i = 0;
	int j = 0;
	int pair = 0;

	for (i = 0;i < number - 1;i++)
	{
		sum1 = sum_loop(n[i]);
		for (j = i + 1;j < number;j++)
		{
			sum2 = sum_loop(n[j]);
			if (sum1 == n[j] && sum2 == n[i])
			{
				pair++;
			}
		}
	}
	printf("Number of Amicable pairs presents in the array: %d", pair);
}
int sum_loop(int n)
{
	int sum = 0;
	int i = 0;
	for (i = 1;i < (n / 2)+1;i++)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}
	return sum;
}
