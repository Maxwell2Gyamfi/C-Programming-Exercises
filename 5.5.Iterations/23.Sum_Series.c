#pragma warning(disable:4996)
#include <math.h>
#include <stdio.h>

int get_n_rows();
int numberofterms();
void get_sum_series(int x, int n);
int main()
{
	int x = 0;
	int n = 0;

	n = get_n_rows();
	x = numberofterms();
	get_sum_series(x, n);
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
void get_sum_series(int x,int n)
{
	double k = 1.0;
	int i = 0;
	
	double sum = 1.0;

	for (i = 1; i < n; i++)
	{
		k = pow((double)x, (double)i)/ (double)i;
		sum += k;
	}
	printf("%lf", sum);
}