#pragma warning (disable:4996)
#include <stdio.h>

struct bothnumbers get_p_q();
void print_lines(struct bothnumbers q);

typedef struct bothnumbers {

	int p;
	int q;

}numbers;

int main()
{
	numbers m;
	m = get_p_q();
	print_lines(m);
	getch();
	return 0;
}
struct bothnumbers get_p_q()
{
	numbers m;
	printf("Input number of lines: ");
	scanf("%d", &m.p);
	printf("Input number of characters in a line: ");
	scanf("%d", &m.q);
    
	return m;

}
void print_lines(struct bothnumbers q)
{
	int i = 0;
	int j = 0;
	int counter = 1;
	printf("\n");
	for (i = 1; i <= q.p; i++)
	{
		for (j = 0; j < q.q; j++)
		{
			printf("%d ", counter);
			counter++;

		}
		printf("\n");
	}

}