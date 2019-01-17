#pragma warning(disable:4996)
#include <stdio.h>
int convert_to_binary(int n, char *m, int start1, int i, int n2);
int get_number();
int main()
{
	char m[20];
	int i = 0;
	long int start1 = 0;
	int n = get_number();
	convert_to_binary(n, m, 65536, i,n);

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Input nay decimal number: ");
	scanf("%d", &n);
	return n;
	
}
int convert_to_binary(int n,char *m,int start1,int i,int n2)
{
	if (start1 <=0)
	{
		m[i]='\0';
		printf("%s", m);
		return 1;
	}
	else
	{
		if (start1 > n2)
		{
			start1 = start1 / 2;
		}
		else
		{
			if (n >= start1)
			{
				m[i++] = '1';
				n = n - start1;
			}
			else
			{
				m[i++] = '0';
			}
			start1 = start1 / 2;
		}
		convert_to_binary(n, m, start1, i,n2);

	}
}