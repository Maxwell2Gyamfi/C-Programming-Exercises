#pragma warning(disable:4996)

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int get_number();
char *get_day(int number);

int main()
{
	char *name;
	int number = 0;
	number = get_number();
	name = get_day(number);
	printf("%s", name);

	getch();
	return 0;
}
int get_number()
{
	int number = 0;
	printf("Enter number of the week: ");
	scanf("%d", &number);

	return number;
}
char *get_day(int number)
{
	static char days[20];

	switch (number)
	{
	case 1:
		strcpy(days, "Monday");
		break;
	case 2:
		strcpy(days, "Tuesday");
		break;
	case 3:
		strcpy(days, "Wednesday");
		break;
	case 4:
		strcpy(days, "Thursday");
		break;
	case 5:
		strcpy(days, "Friday");
		break;
	case 6:
		strcpy(days, "Saturday");
		break;
	case 7:
		strcpy(days, "Sunday");
		break;
	default:
		strcpy(days, "Invalid number");
		break;
	}
	return days;

}