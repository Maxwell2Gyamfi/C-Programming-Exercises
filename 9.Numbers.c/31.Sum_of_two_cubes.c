#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int get_sum();

int main()
{
	get_sum();
	getch();
	return 0;
}
int get_sum()
{
	int first, second, third, fourth=0;
	int count = 0;
	int secondpower = 0;
	int first_power = 0;
	int j = 0;
	unsigned int i = 0;
	int l = 0;
	for (i = 1;i <100000;i++)
	{
		for (j = 1;j <=i;j++)
		{
			first_power = pow((double)j, 3.0);
			if (first_power > i)
			{
				break;
			}
			for (l = 1;l <=i;l++)
			{
				secondpower = pow((double)l, 3.0);
				if (secondpower > i)
				{
					break;
				}
				if (secondpower + first_power == i)
				{
					count++;
					if (count <= 2)
					{
						first = j;
						second = l;
					}
					if (count > 2)
					{
						third = j;
						fourth = l;
					}		
					break;
				}
			}
		}
		if (count == 4)
		{
			printf("%d = %d^3+%d^3=%d^3+%d^3\n",i, first, second, third, fourth);

		}
		count = 0;
	}

}
