#pragma warning(disable:4996)

#include <stdio.h>
int get_rows();
int get_palindrome(int n);

int main()
{
	int n = 0;
	n = get_rows();
	get_palindrome(n);

	getch();
	return 0;
}
int get_rows()
{

	int n = 0;
	printf("Input rows: ");
	scanf("%d", &n);
	return n;
}
int get_palindrome(int n)
{
	int i, j, l, m = 0;
	int k = n;

	for (i = 1; i <= n; i++)
	{
		for (l = 1; l <= k; l++)
		{
			printf(" ");
		}
		k--;
		if (i == 1)
		{
			printf("1");
		}
		else
		{
			for (j = 1; j <= i; j++)
			{
				printf("%d", j);

				if (j == i)
				{
					for (m = i - 1; m > 0; m--)
					{
						printf("%d", m);
					}
				}
			}
		}
		printf("\n");
	}
}
