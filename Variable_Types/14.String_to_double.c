#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

char *get_char();
double convert_to_double(char *name);
double number_divided_by_2(double *number,double value);

int main()
{
	double converted = 0;
	double double_divided = 0;
	char *value;

	value = get_char();
	converted = convert_to_double(value);
	number_divided_by_2(&double_divided,converted);

	printf("The original number is : %lf\n", converted);
	printf("After division by 2 the number is : %lf", double_divided);

	getch();

	return 0;
}
char *get_char()
{
	static char name[3];

	printf("Input a number :");
	scanf("%s", name);

	return name;

}
double convert_to_double(char *name)
{
	double value;

	sscanf(name, "%lf", &value);

	return value;
}
double number_divided_by_2(double *number,double value)
{

	*number = value / 2;

}