#pragma warning(disable:4996)
#include <stdio.h>

void get_numbers(struct AP *m);
void get_sum_of_ap(struct AP m);

typedef struct AP
{
	int starting;
	int numberofitems;
	int commondifference;
}m;

int main()
{

	m numbers;
	get_numbers(&numbers);
	get_sum_of_ap(numbers);

	getch();
	return 0;
}
void get_numbers(struct AP *m)
{
	printf("Input the starting number of the A.P. series: ");
	scanf("%d", &(m->starting));
	printf("Input the number of items for the A.P. series: ");
	scanf("%d", &(m->numberofitems));
	printf("Input the common difference of A.P. series: ");
	scanf("%d", &(m->commondifference));
}
void get_sum_of_ap(struct AP m)
{
	int i = 0;
	int done = 0;
	int sum = 0;
	printf("The Sum of the A.P. series are : ");
	for (i = m.starting; done < m.numberofitems; i = i + m.commondifference)
	{
		done++;
		if (done == m.numberofitems)printf("%d = ", i);
		else printf("%d + ", i);
		sum += i;
	}
	printf(" %d", sum);
}
