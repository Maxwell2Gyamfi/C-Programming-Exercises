#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

void get_upper_lower_limit(int*upper, int *lower);
int get_count(int n, int*numbers);
void get_narcissistic(int upper, int lower);
int get_sum(int *numbers, int count);
int *allocate_memory();

int main()
{
	int upper, lower=0;
	get_upper_lower_limit(&upper, &lower);
	get_narcissistic(upper, lower);
	getch();

	return 0;
}
void get_upper_lower_limit(int*upper, int *lower)
{
	int temp = 0;
	printf("Input the lower limit: ");
	scanf("%d", lower);
	printf("Input the upper limit: ");
	scanf("%d", upper);

	if (*lower > *upper)
	{
		temp = *upper;
		*upper = *lower;
		*lower = temp;
	}
}
int get_count(int n,int*numbers)
{
	int i = 0;
	while (n)
	{
		numbers[i] = n % 10;
		n = n / 10;
		i++;
	}
	return i;
}
void get_narcissistic(int upper,int lower)
{
	int sum = 0;
	int count = 0;
	int i = 0;

	for (i = lower;i < upper;i++)
	{
		int *numbers = allocate_memory();
		count = get_count(i, numbers);
		sum = get_sum(numbers, count);
		if (sum == i)printf("%d ", i);
		free(numbers);
	}
}
int get_sum(int *numbers,int count)
{
	double n = 0;
	int i = 0;
	int sum = 0;

	for (i = 0;i < count;i++)
	{
		n = numbers[i];
		sum += pow(n, (double)count);
	}
	return sum;
}
int *allocate_memory()
{
	int *numbers = (int*)calloc(10, sizeof(int));

	if (numbers == NULL)
	{
		fputs("Error allocating memory", stderr);
		exit(0);
	}
	return numbers;
}