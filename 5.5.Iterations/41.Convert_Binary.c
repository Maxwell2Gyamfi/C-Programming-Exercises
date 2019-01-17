#pragma warning(disable:4996)
#include <stdio.h>
int get_n();
int get_binary(int n, int range);
int main()
{
	int n = 0;
	int range = 0;
	n = get_n(&range);
	get_binary(n,range);

	getch();
	return 0;
}
int get_n(int *range)
{
	int n = 0;

	printf("Enter a number to convert: ");
	scanf("%d", &n);

	if (n < 128) *range = 128;
	else if(n < 256) *range = 256;
	else if (n < 512) *range = 512;
	else if (n < 1024) *range = 1024;
	else if (n < 2048) *range = 1024;
	else if (n < 4096) *range = 4096;

	return n;
}
int get_binary(int n,int range)
{
	int i = 0;
	int result = 0;

	printf("The binary of %d is:  ",n);
	for (i = range; i > 0; i=(i/2))
	{
		if (i > n)
		{
			printf("0");
		}
		else
		{
			printf("1");
			n = n - i;
		}
	}
}