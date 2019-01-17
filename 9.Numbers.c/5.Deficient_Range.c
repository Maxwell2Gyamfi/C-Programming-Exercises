#pragma warning(disable:4996)
#include <stdio.h>
void get_deficients();
int main()
{
	get_deficients();
	getch();
	return 0;
}
void get_deficients()
{
	int i = 0;
	int j = 0;
	int sum = 0;

	for (i = 1;i < 100;i++)
	{
		for (j = 1;j < i;j++)
		{
			if (i%j == 0)
			{
				sum += j;
			}
		}
		if (sum < i)printf("%d ", i);
		sum = 0;
	}
}