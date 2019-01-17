#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int n = 0;
	
	n = get_n_rows();
	get_alphabet_pyramid(n);

	getch();
	return 0;
}
int get_n_rows()
{
	int n = 0;

	printf("Enter number of rows: ");
	scanf("%d", &n);

	if (n > 26)
	{
		n = 26;
	}

	return n;
}
int get_alphabet_pyramid(int n)
{
	int i,j, l, m = 0;
	int k = n;
	char alphabet = 65;//65 on ascii table is A

	for (i = 1; i <= n; i++)
	{
		for (l = 0; l < k; l++)
		{
			printf(" ");
		}
		k--;
		if (i == 1)
		{
			printf("%c", alphabet);
		}
		else
		{
			for (j = 1; j <= i; j++)
			{
				printf("%c", alphabet);
				
				if (j == i)
				{
					for (m = j; m > 1; m--)
					{
						alphabet--;
						printf("%c", alphabet);
					}
				}
				alphabet++;
			}
		}
		alphabet = 65;
		printf("\n");
	}
}