#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

struct MyStruct get_numerator();
struct MyStruct get_denominator(struct MyStruct *m);
void result(struct MyStruct m);

typedef struct MyStruct
{
	int numerator;
	int denominator;

}numbers;

int main()
{
	numbers m;
	numbers *j;


	m = get_numerator();
	get_denominator(&m);
	result(m);

	getch();
	return 0;
}
struct MyStruct get_numerator()
{
	numbers p;

	printf("Enter numerator: ");
	scanf("%d", &p.numerator);

	return p;

}
struct MyStruct get_denominator(struct MyStruct *m)
{
	
	printf("Enter numerator: ");
	scanf("%d", &m->denominator);

}
void result(struct MyStruct m)
{

	int quotient = m.numerator / m.denominator;
	int remainder = m.numerator%m.denominator;

	printf("Quotient: %d, Remainder %d", quotient, remainder);


}
