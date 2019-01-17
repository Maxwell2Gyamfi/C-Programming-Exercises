#pragma warning(disable:4996)
#include <stdio.h>

int get_n();
void get_pyramid(int n);

int main()
{
	get_n();
	getch();

	return 0;
}
int get_n()
{
	int n = 0;
	printf("Testa data: ");
	scanf("%d", &n);

	get_pyramid(n);

}
void get_pyramid(int n)
{
	size_t i;
	size_t j;
	int l=0;
	int k=n;

	for (i = 1; i <= n; i++)
	{
		for (l = 0; l < k; l++)
		{
			printf(" ");
		}

		k--;

		for (j = 0; j < i; j++)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
}