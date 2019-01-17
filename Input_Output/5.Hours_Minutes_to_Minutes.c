#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define MINUTES 60

struct times get_minutes();
struct times get_hours(struct times *q);

void print_total_minutes(struct times q);
void get_total_minutes(struct times *q);

typedef struct times
{
	int minutes;
	int hours;
	int total_minutes;

}p;
int main()
{
	p s;
	p *m;
	m = &s;

	s = get_minutes();
	get_hours(m);
	get_total_minutes(m);
	print_total_minutes(s);
	

	getch();

	return 0;
}
struct times get_minutes()
{
	p m;
	char minutes[5];

	fputs("Input minutes: ",stdout);
	fgets(minutes, sizeof(minutes), stdin);

	sscanf(minutes,"%d", &m.minutes);

	return m;
}
struct times get_hours(struct times *q)
{
	char hours[5];

	fputs("Input hours: ", stdout);
	fgets(hours, sizeof(hours), stdin);

	sscanf(hours, "%d", &q->hours);
}
void get_total_minutes(struct times *q)
{
	q->total_minutes = (q->hours * 60) + q->minutes;
}
void print_total_minutes(struct times q)
{
	printf("Total: %d minutes",q.total_minutes);
}
