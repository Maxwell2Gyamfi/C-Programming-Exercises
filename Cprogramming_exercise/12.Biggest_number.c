#pragma warning(disable :4996)

#include <stdio.h>
#include<string.h>
#include <ctype.h>

int main()
{
	int temp = 0;

	temp = bigger_number();
	printf("Bigger is %d\n", temp);
	getch();
	return 0;
}
int bigger_number()
{

	int i = 0;
	int numbers[3];
	int bigger = 0;
	int smaller = 100;
	printf("Enter 3 numbers\n");
	
	for (i = 0; i < sizeof((int)numbers)-1; i++)
	{
		scanf("%d", &numbers[i]);
	}
	for (i = 0; i < sizeof((int)numbers) - 1; i++)
	{
		if (numbers[i] > bigger)
		{
			bigger = numbers[i];
		}
		if (numbers[i] < smaller)
		{
			smaller = numbers[i];
		}
	}
	printf("Smaller is %d\n", smaller);
	return bigger;
}