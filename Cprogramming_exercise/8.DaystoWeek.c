#pragma warning(disable:4996)
#include<stdio.h>
void calculate_weeks_days(int days);

int main()
{
	int days = 0;
	printf("Enter number of days: ");
	scanf("%d", &days);
	calculate_weeks_days(days);
  
	return 0;
}
void calculate_weeks_days(int days)
{
	int year = 365;
	int week = 7;
	int years = 0;
	int weeks = 0;
	int day = 0;

	if (days >= year)
	{
		years = days / year;
	}
	if (days % year <365)
	{
		weeks = (days % year) / 7;
		//day = days - ((years * year) + (weeks * week));
		day = (days % year) % 7;
		
	}
	
	printf("Years: %d\n", years);
	printf("Weeks: %d\n", weeks);
	printf("Days: %d\n", day);
		
}