#pragma warning (disable:4996)

#include <stdio.h>
int get_temperature();
void decision(int temp);

int main()
{
	get_temperature();
	getch();
	return 0;
}
int get_temperature()
{

	int temp = 0;

	printf("Test Data: ");
	scanf("%d", &temp);
	decision(temp);
	
}
void decision(int temp)
{
	if (temp < 0)
	{
		puts("Freezing weather");
	}
	else if (temp >= 0 && temp < 10)
	{
		puts(" Very Cold weather");
	}
	else if (temp >= 10 && temp < 20)
	{
		puts("Cold weather");
	}
	else if (temp >= 20 && temp < 30)
	{
		puts("Normal in Temp");
	}
	else if (temp >= 30 && temp < 40)
	{
		puts("Its hot");
	}
	else
	{
		puts("Its very hot");
	}
}