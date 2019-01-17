#pragma warning (disable:4996)
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct coordinates get_first_coordinate();
struct coordinates get_second_coordinate(struct coordinates *p);
void decide_quadrant(struct coordinates p);

typedef struct coordinates
{
	int first_coordinate;
	int second_coordinate;

}Quadrant;

int main()
{
	Quadrant m;
	Quadrant *n;

	n = &m;

	m = get_first_coordinate();
	get_second_coordinate(&m);
	decide_quadrant(*n);

	getch();

	return 0;
}
struct coordinates get_first_coordinate()
{
	char buffer[5];
	Quadrant m;


	fputs("Enter first coordinate(X): ",stdout);
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &m.first_coordinate);

	return m;
}
struct coordinates get_second_coordinate(struct coordinates *p)
{
	char buffer[5];

	fputs("Enter second coordinate(Y): ", stdout);
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &p->second_coordinate);

}
void decide_quadrant(struct coordinates p)
{
	if (p.first_coordinate > 0 && p.second_coordinate > 0)
	{
		printf("The coordinate (%d %d) lies int the First Quadrant",p.first_coordinate,p.second_coordinate);
	}
	else if (p.first_coordinate < 0 && p.second_coordinate > 0)
	{
		printf("The coordinate (%d %d) lies int the Second Quadrant", p.first_coordinate, p.second_coordinate);
	}
	else if (p.first_coordinate > 0 && p.second_coordinate < 0)
	{
		printf("The coordinate (%d %d) lies int the Third Quadrant", p.first_coordinate, p.second_coordinate);
	}
	else
	{
		printf("The coordinate (%d %d) lies int the Fourth Quadrant", p.first_coordinate, p.second_coordinate);
	}
}