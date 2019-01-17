#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef struct employee
{
	char *name;
	char srtname[20];
	int pincode;

}employer;

int main()
{
	employer *k;
	employer m;
	
	m.name = "marco";
	strcpy(m.srtname, "arzignano");
	m.pincode = 456;

	k = &m;
	printf("%s from %s, postcode %d", k->name, (*k).srtname, k->pincode);

	getch();
	return 0;
}