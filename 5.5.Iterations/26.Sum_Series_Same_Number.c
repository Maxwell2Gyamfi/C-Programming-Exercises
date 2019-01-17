#pragma warning (disable:4996)
#include <stdio.h>

struct numbers get_numbers();
int get_sum(struct numbers q);

typedef struct numbers
{
	int x;
	int n;

}number;

int main()
{
	number q;

	q = get_numbers();
	get_sum(q);

	getch();
	return 0;
}
struct numbers get_numbers()
{
	number q;

	printf("Input the value: ");
	scanf("%d", &q.x);

	printf("Input n terms: ");
	scanf("%d", &q.n);

	return q;
}
int get_sum(struct numbers q)
{
	int sum = q.x;
	int k = q.x;
	int i = 0;

	printf("%d", q.x);

	for (i = 1; i < q.n; i++)
	{
		k = k * 10 + q.x;
		sum += k;
		printf(" + %d", k);
	}

	printf("\nThe sum is %d", sum);
}