#pragma warning(disable:4996)
#include <stdio.h>
int get_number(int *n, int *power);
int get_power(int number, int power, int count);
int main()
{
	int n=0;
	int power = 0;
	get_number(&n, &power);
	get_power(n, power, 1);
	getch();
	return 0;
}
int get_number(int *n, int *power)
{
	printf("Input the base value: ");
	scanf("%d", n);
	printf("Input the power: ");
	scanf("%d", power);
}
int get_power(int number, int power, int count)
{
	static int sum = 1;
	if (count > power)
	{
		printf("The value of %d to the power of %d is %d", number, power, sum);
		return;
	}
	else
	{
		sum *= number;
		get_power(number, power, count+1);
	}

}