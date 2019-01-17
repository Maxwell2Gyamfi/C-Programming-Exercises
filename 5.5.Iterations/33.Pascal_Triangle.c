#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_n();
void get_pascal(int n);

int main()
{
	get_n();

	getch();
	return 0;
}
void get_n()
{
	int n = 0;
	printf("Input number of rows: ");
	scanf("%d", &n);
	get_pascal(n);

}
void get_pascal(int n)
{
	int positive = 0;
	int sum = 0;
	int i = 0;
	int j = 0;
	int l = 0;
	int k = n;
	int q = 0;
	int z = 0;
	int d = 0;
	int numbers[20];
	int sum2[10];
	numbers[0] = 1;
	sum2[0] = 0;
	sum2[1] = 0;
	sum2[2] = 0;




	for (i = 0; i < n; i++)
	{
		for (l = 0; l < k; l++)
		{
			printf(" ");
		}
		k--;
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				numbers[j] = 1;
			}
			else
			{
				for (z = 1; z <=i; z++)
				{
					sum2[z] = numbers[z-1] + sum2[z];
				}
			}
		}
		for (d = 0; d <= i; d++)
		{
			if (d == 0 || d == i)
			{
				printf("1 ");
			}
			else
			{
				printf("%d ", sum2[d]);
			}
		}
		printf("\n");


	}
}