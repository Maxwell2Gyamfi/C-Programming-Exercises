#pragma warning(disable:4996)

#include<stdio.h>

int get_numbers();
void get_lcm(int first, int second);
int main()
{
	get_numbers();
	getch();

	return 0;
}
int get_numbers()
{
	int ist = 0;
	int nd = 0;
	int temp = 0;

	printf("Input 1st number for LCM:");
	scanf("%d", &ist);
	printf("Input 2nd number for LCM:");
	scanf("%d", &nd);

	if (ist > nd)
	{
		temp = ist;
		ist = nd;
		nd = temp;
	}
	get_lcm(ist, nd);
}
void get_lcm(int first, int second)
{
	int lcm = 0;
	int i = 0;

	for (i = first; lcm<=0; i=i+first)
	{
		if (i%first == 0 && i%second == 0)
		{
			lcm = i;
		}
	}
	printf("The LCM of %d and %d is: %d", first, second, lcm);
}