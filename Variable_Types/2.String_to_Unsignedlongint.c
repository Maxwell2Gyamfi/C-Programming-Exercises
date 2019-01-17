#pragma warning(disable:4996)
#include <stdio.h>

int conver_to_long_int(char value);
int conver_string_to_integer(char value);

int main()
{
	char n = 25;
	unsigned long int m;

	m = conver_to_long_int(n);
	conver_string_to_integer(n);
	printf("%lu", m);

	getch();
	return 0;
}
int conver_to_long_int(char value)
{
	unsigned long int m;

	m = (unsigned long int)value;
	return m;

}
int conver_string_to_integer(char value)
{
	int i;

	i = (int)value;

	printf("%d\n", i);
}