#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>


struct allnumbers get_numberator();
struct allnumbers get_denominator(struct allnumbers *p);
void get_result(struct allnumbers p);

typedef struct allnumbers
{
	int numerator;
	int denominator;

}p;


int main()
{
	p m;
	p *n;
	n = &m;
	m= get_numberator();
	get_denominator(n);
	get_result(m);

	getch();

	return 0;

}
struct allnumbers get_numberator()
{
	p m;

	printf("Enter numberator: ");
	scanf("%d", &m.numerator);

	return m;
}
struct allnumbers get_denominator(struct allnumbers *n)
{
	

	printf("Enter denomerator: ");
	scanf("%d", &n->denominator);

}
void get_result(struct allnumbers p)
{

	int quotient=0;
	int remainder=0;
	div_t result;

	result = div(p.numerator, p.denominator);
	//quotient = p.numerator / p.denominator;
	//remainder = p.numerator%p.denominator;

	printf("quotient = %d , remainder %d", result.quot, result.rem);

}