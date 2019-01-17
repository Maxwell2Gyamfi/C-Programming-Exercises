#pragma warning(disable:4996)

#include <stdio.h>
int get_n_rows();
void get_pyramid(int n);

int main()
{
	int n = 0;

	n=get_n_rows();
	get_pyramid(n);

	getch();
	return 0;
}
int get_n_rows()
{
	int n = 0;
	printf("Enter the number of rows: ");
	scanf("%d", &n);

	return n;
}
void get_pyramid(int n)
{
	size_t i;
	size_t j;

	for (i = 1; i <=n; i++)
	{
		if (i % 2 != 0)
		{
			for (j = 1; j <= i; j++)
			{
				if (j % 2 != 0)
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
			}
		}
		else
		{
			for (j = 1; j <= i; j++)
			{
				if (j % 2 != 0)
				{
					printf("0");
				}
				else
				{
					printf("1");
				}
			}
		}
		puts("");
	}
}