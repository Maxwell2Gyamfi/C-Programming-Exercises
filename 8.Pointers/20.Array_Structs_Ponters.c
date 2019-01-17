#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

typedef struct employee
{
	char name[20];
	int employee_id;


}employer;


int main()
{
	int counter = 0;
	employer m[20];
	employer *k = NULL;
	employer *s = NULL;
	k = &m[0];


	strcpy(m[counter].name, "Alex");
	m[counter].employee_id = 1001;
	k->employee_id = 300;

	k++;
	k->employee_id = 400;

	printf("\nEmployee Name : %s", (*(k-1)).name);
	printf("\nEmployee ID : %d", (*(k-1)).employee_id);
	printf("\n%d", m[counter + 1].employee_id);
	printf("\n%d", k->employee_id);

	getch();
	return 0;
}