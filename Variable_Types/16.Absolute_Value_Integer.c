#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int get_value();
int get_absolute_value(int *value);
void print_value(int value,int value2);

int main()
{
	int value = 0;
	int value2 = 0;
	value = get_value();
	value2 = value;
	get_absolute_value(&value);
	print_value(value,value2);

	getch();
	return 0;
}
int get_value()
{

	int value;
	printf("Input a positive or negative number: ");
	scanf("%d", &value);

	return value;

}
int get_absolute_value(int *value)
{

	if (*value > 0)
	{
		*value = *value;
	}
	else
	{
		*value = *value *-1;
	}
}
void print_value(int value, int value2)
{
	printf("The absolute value of the given number %d is : %d",value2, value);

}
