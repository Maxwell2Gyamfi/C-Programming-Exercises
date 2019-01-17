#pragma warning(disable:4996)

#include <math.h>
#include <stdio.h>


int get_n();
void moltiplication_table(int n);
int main()
{
	int n = 0;
	n=get_n();
	moltiplication_table(n);

	
	return 0;
}
int get_n()
{
	int n = 0;

	printf("Test data: ");
	scanf("%d", &n);
	return n;
}
void moltiplication_table(int n)
{
	
	int i = 0;

	for (i = 1; i <=10; i++)
	{
		printf("%d * %d = %d\n", n, i, n*i);
	}
}