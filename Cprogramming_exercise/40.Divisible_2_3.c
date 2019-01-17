#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct numbers get_pair_of_numbers(int *size);
void bubblesort(struct numbers *p, int size);
struct numbers * get_loop_number(struct numbers p);
void print_numbers(struct numbers *p);

typedef struct numbers
{
	int malloc_size;
	int pair_of_numbers[3];
	int *number_of_loop;

}container;


container p;

int main()
{
	container *s;
	int i = 0;
	int size = 0;

	p = get_pair_of_numbers(&size);
	s = get_loop_number(p);
	print_numbers(s);

	getch();
	return 0;
}
struct numbers get_pair_of_numbers(int *size)
{
	container *q;

	int size2 = 2;
	int i = 0;

	*size = size2;
	q = &p;

	printf("Enter the pair of number: ");
	for (i = 0; i < size2; i++)
	{
		scanf("%d", &p.pair_of_numbers[i]);
	}
	bubblesort(q, size2);
	return p;

}
struct numbers * get_loop_number(struct numbers p)
{
	container *m;
	int size = 0;
	int i = 0;
	int smaller = 0;
	int bigger = 0;
	

	smaller = p.pair_of_numbers[0];
	bigger = p.pair_of_numbers[1];
	size = bigger - smaller;


	m = (struct numbers*)malloc(size * sizeof(struct numbers));
	m->number_of_loop= (struct numbers*)malloc(size * sizeof(struct numbers));
	
	m->pair_of_numbers[1] = bigger;
	m->pair_of_numbers[0] = smaller;
	

	for (i = smaller; i < bigger; i++)
	{
		if ((i %7 == 2) || (i%7) == 3)
		{
			m->number_of_loop[i] = i;
		}
	}
	return m;
}
void print_numbers(struct numbers *p)
{
	int size1 = 0;
	int size = 0;
	int i = 0;
	size = p->pair_of_numbers[0];
	size1 = p->pair_of_numbers[1];

	for (i =size ; i <= size1; i++)
	{
		if(p->number_of_loop[i]<=0){}
		else
		{
			printf("%d\n", p->number_of_loop[i]);
		}
	}
}
void bubblesort(struct numbers *q, int size)
{
	int temp = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (q->pair_of_numbers[i] > q->pair_of_numbers[j])
			{
				temp = q->pair_of_numbers[i];
			    q->pair_of_numbers[i] = q->pair_of_numbers[j];
				q->pair_of_numbers[j] = temp;
			}

		}
	}
}