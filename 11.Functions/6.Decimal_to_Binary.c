#pragma warning(disable:4996)

#include <stdio.h>
int binary(int n1, char *n, int start, long int max, int n2);
int main()
{
	int a = 0;
	int number = 0;
	char n[20];
	printf("Input any decimal number: ");
	scanf("%d", &number);

	a = number;
    binary(number, n, 0, 65536,a);
	printf("%s", n);

	getch();
	return 0;
}
int binary(int n1,char *n,int start, long int max,int n2)
{
	if (max <= 0)
	{
		n[start] = '\0';
		
		return 1;
	}
	else
	{
		if (n2 < max)
		{
			max = max / 2;
			start = -1;
		}
		else
		{
			if (n1 < max)
			{
				n[start] = '0';
				max = max / 2;
			}
			else
			{
				n[start] = '1';
				n1 = n1 - max;
				max = max / 2;
			}
		}
		binary(n1, n, start+1, max,n2);
	}


}