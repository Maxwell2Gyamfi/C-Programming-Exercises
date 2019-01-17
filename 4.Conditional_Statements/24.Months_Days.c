#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

void get_month_number();
void get_days(char *number);
int main()
{
	get_month_number();


	getch();
	return 0;
}
void get_month_number()
{
	static char buffer[2];
	int number = 0;


	scanf("%d", &number);
	sprintf(buffer, "%d", number);

	get_days(buffer);
 
}
void get_days(char *number)
{
	int lenght = strlen(number);

	if (lenght == 1)
	{ 
		switch (number[0])
		{
		case '1':case'3':case'5':case'7':case'8':printf("31 days"); break;
		case '4':case'6':case '9':printf("30 days"); break;
		case '2':printf("28 days, 29 days leap year"); break;
		default:printf("Incorrect input"); break;
		}
	}
	if (lenght==2)
	{
		switch (number[1])
		{
		case '0':case '2':printf("31 days"); break;
		case '1':printf("30 days"); break;
		default:printf("Incorrect input"); break;
		}
	}
}
