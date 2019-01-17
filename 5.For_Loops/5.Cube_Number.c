#pragma warning(disable:4996)

#include <math.h>
#include <stdio.h>

int get_cube(int n);
int get_n();

int main()
{
	int n = 0;
	n = get_n();
	get_cube(n);
	getch();

	return 0;
}
int get_n()
{
	int n = 0;

	printf("Test data: ");
	scanf("%d", &n);
	return n;

}
int get_cube(int n)
{
	size_t i;

	for (i = 1; i <= n; i++)
	{
		printf("Number is : %d and cube of the %d is :%.0lf\n", i, i, pow((double)i, 3));
	}
}