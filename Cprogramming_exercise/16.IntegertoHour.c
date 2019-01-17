#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>

void integer_to_hour(int seconds);
void integer_to_hour2(int seconds);

int main()
{
	int seconds = 0;

	printf("Input seconds: ");
	scanf("%d", &seconds);

	integer_to_hour(seconds);
	integer_to_hour2(seconds);

	getch();
	return 0;
}

void integer_to_hour(int seconds)
{
	int hours = 0;
	int minutes = 0;
	int seconds1 = 0;
	do
	{
		if (seconds >= 3600)
		{
			seconds = seconds - 3600;
			hours++;
		}
		else if (seconds < 3600 && seconds > 60)
		{
			seconds = seconds - 60;
			minutes++;
		}
		else
		{
			seconds1 = seconds;
			seconds = 0;
		}
	} while (seconds > 0);

	printf("H:M:S - %d:%d:%d\n", hours, minutes, seconds1);
}
void integer_to_hour2(int seconds)
{
	int hours = seconds / 3600;
	int minutes = (seconds % 3600) / 60;
	int seconds1 = ((seconds % 3600) % 60);

	printf("H:M:S - %d:%d:%d", hours, minutes, seconds1);

}