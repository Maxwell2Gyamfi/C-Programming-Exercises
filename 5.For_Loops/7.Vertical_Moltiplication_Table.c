#pragma warning(disable:4996)

#include <math.h>
#include <stdio.h>

void get_table(int n);
int get_n();
int main()
{
	int n = 0;
	n = get_n();
	get_table(n);
	getch();


	return 0;
}
int get_n()
{
	int n = 0;

	printf("Input upto the table number starting from 1: ");
	scanf("%d", &n);
	return n;
}
void get_table(int n)
{
	int j = 0;
	int i = 0;

	for (i = 1; i <=10; i++)
	{
		for (j = 1; j <=n; j++)
		{
			if (i == 10 && j == n)
			{
				printf("%dx%d = %d", j, i, j*i);
			}
			else
			{
				printf("%dx%d = %d, ", j, i, j*i);
			}
		}
		printf("\n");
	}
}