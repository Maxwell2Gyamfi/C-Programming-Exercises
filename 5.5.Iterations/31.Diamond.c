#pragma warning (disable:4996)

#include <stdio.h>

void get_n();
void diamond(int n);

int main()
{
	get_n();

	getch();
	return 0;
}
void get_n()
{
	int n = 0;
	printf("Input n terms: ");
	scanf("%d", &n);
	diamond(n);

}
void diamond(int n)
{
	int i = 0;
	int j = 0;
	int l = 0;
	int k = n;
	int m = 0;

	for (i = 1; i <= n; i++)
	{
		for (l = 0; l < k; l++)
		{
			printf(" ");
		}
		k--;
		for (j = 0; j < i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for (i = n; i > 0; i--)
	{
		for (l = m; l > 0; l--)
		{
			printf(" ");
		}
		m++;
		for (j = i; j > 0; j--)
		{
			printf(" *");
		}
		printf("\n");
	}
}