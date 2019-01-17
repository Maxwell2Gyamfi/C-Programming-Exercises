#pragma warning(disable:4996)

#include <stdio.h>
void get_row(int n);
int get_n();

void get_pyramid(int n);
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

	get_pyramid(n);

}
void get_pyramid(int n)
{

	int i = 0;
	int l = 1;
	int j = 0;
	int m = 0;
	int k = n;

	for (i = 1; i <= n; i++)
	{
		for (m = 0; m<k; m++)
		{
			printf(" ");
		}

		k = k - 1;

		for (j = 1; j <=i; j++)
		{
			printf("%d ", l);
			l++;
		}
		printf("\n");
	}
}