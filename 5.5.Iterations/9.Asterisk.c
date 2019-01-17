#pragma warning(disable:4996)


#include<stdio.h>
int asterisk();
int main()
{

	asterisk();

	getch();
	return 0;
}
int asterisk()
{
	int row;
	int i = 0;
	int j = 0;

	printf("Enter number of rows: ");
	scanf("%d", &row);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <=i; j++)
		{
			printf("*");
		}
		printf("\n");

	}
}