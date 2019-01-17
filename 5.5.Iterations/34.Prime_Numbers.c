#pragma warning(disable:4996)

#include <stdio.h>

int main()
{
	int start, end = 0;
	get_range(&start, &end);
	get_prime_numbers(start, end);

	getch();

	return 0;
}
int get_range(int *start, int *end)
{
	int temp;
	int n = 0;
	printf("Input starting number of range: ");
	scanf("%d", &(*start));
	
	printf("Input ending number of range :");
	scanf("%d", &(*end));

	if (*start > *end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
	}

	if (*start==0)
	{
		*start = 1;
	}
	
}
int get_prime_numbers(int start, int end)
{
	int j = 0;
	int i = 0;
	int prime = 0;

	for (i = start; i < end; i++)
	{
		for (j = 1; j < end; j++)
		{
			if (i % j == 0)
			{
				prime++;
			}
		}
		if (prime == 2)
		{
			printf("%d ", i);
		}
		prime = 0;
	}
}