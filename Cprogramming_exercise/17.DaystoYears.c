#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>
void get_years(int days);
void get_years_two(int days);
int main()
{
	int days = 0;
	printf("Enter days: ");
	scanf("%d", &days);
	get_years(days);
	get_years_two(days);
	getch();
	return 0;
}

void get_years(int days)
{
	int years = 0;
	int months = 0;
	int weeks = 0; 
	int days1 = 0;
	int hours = 0;
	int minutes = 0;
	int seconds=0;

	do
	{
		if (days >= 365)
		{
			days = days - 365;
			years++;
		}
		else if (days < 365 && days >= 30)
		{
			days = days - 30;
			months++;
		}
		else if (days < 30 && days >= 7)
		{
			days = days - 7;
			weeks++;
		}
		else if (days < 7)
		{
			if (days >= 1)
			{
				days1 = days - 1;
				hours = 23;
				minutes = 59;
				seconds = 59;
				days = 0;
			}
		
		}
	} while (days >=1);
	printf("%d Years %d Months %d Weeks %d Days %d Hours %d Minutes %d Seconds\n", years, months, weeks, days1, hours, minutes, seconds);


}
void get_years_two(int days)
{
	int hours = 23;
	int minutes = 59;
	int seconds =59;

	int years = days / 365;
	int months = (days % 365) / 30;
	int weeks = ((days % 365) % 30) / 7;
	int days1 = (((days % 365) % 30) % 7)-1;


	printf("%d Years %d Months %d Weeks %d Days %d Hours %d Minutes %d Seconds", years, months, weeks, days1, hours, minutes, seconds);

}