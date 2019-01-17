#pragma warning(disable: 4996)
#include <stdio.h>


int get_odd_n_rows();
void odd_asterisk(int n);
int main()
{
	int n = 0;
	n = get_odd_n_rows();
	odd_asterisk(n);

	getch();
	return 0;
}
int get_odd_n_rows()
{
	int n = 0;
	do
	{
		printf("Enter a number greater or equal to 3: ");
		scanf("%d", &n);
	} while (n < 3);
	return n;
}
void odd_asterisk(int n)
{
	size_t i;
	size_t j;
	size_t l = n;
	size_t k = 0;

	for (i = 1; i <=n*2; i++)
	{
		if (i % 2 != 0)
		{
			for (k = 0; k < l; k++)
			{
				printf(" ");
			}
			for (j = 1; j <= i; j++)
			{
				printf("*");
			}
			l--;
		}
		puts("");
	}
}