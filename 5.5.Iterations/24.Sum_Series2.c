#pragma warning(disable:4996)

#include <math.h>
#include <stdio.h>

int get_sum(int n, int x);
int get_n_rows();
int numberofterms();
void get_sum_series(int x, int n);
int main()
{
	int x = 0;
	int n = 0;

	n = get_n_rows();
	x = numberofterms();
	get_sum(x, n);
	getch();

	return 0;
}
int get_n_rows()
{
	int n = 0;
	printf("Input the value of x: ");
	scanf("%d", &n);

	return n;
}
int numberofterms()
{
	int n = 0;
	printf("Input the number of terms: ");
	scanf("%d", &n);

	return n;
}
int get_sum(int n, int x)
{
	long int sum = 0;
	int i = 0;
	int value = 0;
	int odd = 0;
	int l = 1;
	int odd2 = 1;

	while (odd < n)
	{
		if (l % 2 != 0)
		{
			if (odd2 == 0)
			{
				value = pow((double)x, l)* -1;
				sum += value;
				printf("%ld\n", value);
				odd++;
				odd2 = 1;
			}
			else
			{
				if (l == 1)
				{
					value = pow((double)x, l);
					sum = value;
					printf("%ld\n", value);
					odd++;
					odd2 = 0;
				}
				else
				{
					value = pow((double)x, l);
					sum += value;
					printf("%ld\n", value);
					odd++;
					odd2 = 0;
				}
				
			}
		}
		l++;
	}
	printf("The sum = %ld", sum);
		
}
