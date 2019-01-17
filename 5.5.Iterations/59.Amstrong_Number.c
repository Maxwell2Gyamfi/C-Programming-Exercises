#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <string.h>

int get_number();
int get_lenght(int n);
void get_amstrong(int n);

int main()
{
	int number=0;
	number = get_number();
	get_amstrong(number);

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Input an integer: ");
	scanf("%d", &n);

	return n;
}
int get_lenght(int n)
{
	int count = 0;
	int s = 0;
	do
	{
		count++;
		
		n = n / 10;


	} while (n);
	return count;
}
void get_amstrong(int n)
{
	char buffer[20];
	int i = 0;
	int sum = 0;

	int lenght = get_lenght(n);
	sprintf(buffer, "%d", n);

	for (i = 0; i < lenght; i++)
	{
		int value = buffer[i]-'0';
		sum += pow((double)value, (double)lenght);

	}
	if (sum == n)printf("%d is an Amstrong number", n);
	else printf("%d is not an Armstrong number",n);

}
