#pragma warning(disable:4996)
#include <stdio.h>
int get_pronics(int end, int range, int start);
int main()
{
	get_pronics(1000, 0, 1);

	getch();
	return 0;
}
int get_pronics(int end,int range,int start)
{
	int sum = 0;

	if (range >= end)
	{
		return 1;
	}
	else
	{
		sum = start * start + start;
		range = sum;
		if (range <=end)
		{
			printf("%d ", range);
		}
		get_pronics(end, range, start + 1);
		
	}
}