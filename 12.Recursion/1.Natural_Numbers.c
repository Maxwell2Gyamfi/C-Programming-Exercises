#pragma warning(diable:4996)
#include <stdio.h>
int natural_numbers(int i);
int main()
{

	natural_numbers(1);

	getch();
	return 0;
}
int natural_numbers(int i)
{

	if (i == 50)
	{
		printf("%d", i);
		return 1;
	}
	else
	{
		printf("%d ", i);
		natural_numbers(i + 1);
	}

}