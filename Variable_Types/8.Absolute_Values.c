#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

struct absolute *get_numbers();
int get_absolutes(struct absolute *p);
void print_absolutes(struct absolute *p);

typedef struct absolute
{
	int *two_numbers;
	int absolutes[2];


}numbers;


int main()
{
	numbers *q;
	q = get_numbers();
	get_absolutes(q);
	print_absolutes(q);

	free(q);
	getch();
	return 0;
}
struct absolute *get_numbers()
{
	int size = 2;
	numbers *p;
	int i = 0;

	p = (struct absolute*)malloc(sizeof(struct absolute));
	p->two_numbers=(struct absolute*)malloc(size * sizeof(struct absolute));

	if (p->two_numbers == NULL)
	{
		printf("Error");
		exit(1);
	}

	for (i = 0; i < size; i++)
	{
		scanf("%d", &p->two_numbers[i]);
	}
    
	return p;
}
int get_absolutes(struct absolute *p)
{
	int i = 0;
	int big = 0;
	int result = 0;

	for (i = 0; i < 2; i++)
	{
		if (p->two_numbers[i] < 0)
		{
			p->absolutes[i] = p->two_numbers[i] * -1;
		}
		else
		{
			p->absolutes[i] = p->two_numbers[i];
		}
	}
}

void print_absolutes(struct absolute *p)
{
	int i = 0;
	char value[2][10] = { "1st", "2nd" };

	for (i = 0; i < 2; i++)
	{
		printf("The absolute value of %s number is %d\n",value[i], p->absolutes[i]);
	}
}
