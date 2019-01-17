#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>

void get_n_terms();
void get_sum(int n);
int main()
{
	get_n_terms();

	getch();
	return 0;
}
void get_n_terms()
{
	int n = 0;
	printf("Input n terms: ");
	scanf("%d", &n);
	get_sum(n);
}
void get_sum(int n)
{
	int value = 0;
	int sum = 0;
	size_t i = 1;

	printf("The square numbers upto to %d terms are: ",n);
	for (i = 1; i <= n; i++)
	{
		value = pow((double)i, 2);
		printf("%d ",value);
		sum += value;
	}
	printf("\nThe Sum of Square Natural Number upto 5 terms = %d", sum);
}

