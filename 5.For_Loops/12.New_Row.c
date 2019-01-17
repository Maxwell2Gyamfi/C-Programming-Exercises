#pragma warning(disable:4996)

#include <stdio.h>
void get_row(int n);
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

	get_row(n);

}
void get_row(int n)
{
	int l = 1;
	int i = 0;
	int j = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d ",l);
			l++;
		}
		printf("\n");
	}
}