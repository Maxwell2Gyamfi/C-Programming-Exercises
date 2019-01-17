#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

struct arraynumbers get_array_numbers();
void save_smallest_and_position(struct arraynumbers *p);
void print_smallers_position(struct arraynumbers p);

typedef struct arraynumbers
{
	int numbers[6];
	int smallest;
	int position;


}allnumbers;

int main()
{
	allnumbers q;
	allnumbers *b;
	b = &q;
	q = get_array_numbers();
	save_smallest_and_position(b);
	print_smallers_position(q);
	getch();

	return 0;
}
struct arraynumbers get_array_numbers()
{
	allnumbers p;

	int i = 0;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &p.numbers[i]);
	}
	return p;
}
void save_smallest_and_position(struct arraynumbers *p)
{    
	p->smallest = p->numbers[0];
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (p->numbers[i] <= p->smallest)
		{
			p->smallest = p->numbers[i];
			p->position = i;
		}
	}
}
void print_smallers_position(struct arraynumbers p)
{
	printf("Smallest value: %d\n", p.smallest);
	printf("Position of the element: %d", p.position);
}