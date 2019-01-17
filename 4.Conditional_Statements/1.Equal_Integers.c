
#pragma warning(disable:4996)
#include <stdio.h>

struct numbers get_numbers();
int check_if_equal(struct numbers p);

typedef struct numbers
{
	int first_number;
	int second_number;
}Numbers;

int main()
{
	Numbers q;
	q = get_numbers();
	check_if_equal(q);

	getch();
	return 0;
}
struct numbers get_numbers()
{
	Numbers p;

	printf("Enter 2 numbers: ");
	scanf("%d%d", &p.first_number, &p.second_number);

	return p;
}
int check_if_equal(struct numbers p)
{
	if (p.first_number == p.second_number)
	{
		printf("Number1 and Number2 are equal");
	}
	else
	{
		printf("Number1 and Number2 are not equal");
	}
}