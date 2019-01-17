#pragma warning(disable:4996)

#include <stdio.h>
void get_row(int n);
int get_n();

void pyramid(int n);
int get_n();
int main()
{
	get_n();
	getch();


	return 0;
}
int get_n()
{
	int n = 0;
	printf("Test data: ");
	scanf("%d", &n);

	pyramid(n);

}
void pyramid(int n)
{
	int i, j = 0;
	int l = 0;
	int k = 0;
	k = n;


	for (i = 0; i < n; i++)
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
}