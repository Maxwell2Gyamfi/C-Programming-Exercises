#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void swap(char *buffer, int lenght);
int get_number();
int lycherel(long long int number, int counter);
int lenght_convert_tostring(long long int number, char *string);
int ispalindrome(char *number);

int count = 0;
long long int add = 0;
long long int number1 = 0;
char buffer[20];
int lenght = 0;
int s = 0;

int main()
{
	long long int number2 = 0;
	int number = get_number();
	number2 = number;

	lycherel(number2,0);
	getch();
	return 0;
}
int get_number()
{
	int number = 0;
	printf("Input a number: ");
	scanf("%d", &number);
	return number;
}
int lycherel(long long int number,int counter)
{
	if (counter == 0) s = number;
	if (counter == 500)
	{
		printf("%d is a Lycherl number", s);
		return 1;
	}
	else
	{
	    lenght = lenght_convert_tostring(number, buffer);
		swap(buffer, lenght);
		sscanf(buffer, "%lld", &number1);
		add = number + number1;
		sprintf(buffer, "%lld", add);

		if (ispalindrome(buffer))
		{
			printf("The number is a not a Lycherl\n");
			return 1;
		}
		lycherel(add,counter+1);
	}
}
void swap(char *buffer,int lenght)
{
	int i = 0;
	lenght = lenght - 1;
	char *ptr = buffer;
	char temp;

	for (i = 0;i <=lenght ;i++)
	{
		temp = ptr[i];
		ptr[i] = ptr[lenght];
		ptr[lenght] = temp;
		lenght--;
	}
}
int lenght_convert_tostring(long long int number,char *string)
{
	int count = 0;
	long long int k = number;
	int lenght = 0;
	char buffer[20];

	sprintf(buffer, "%lld", number);
	strcpy(string, buffer);

	while (k)
	{
		k = k / 10;
		count++;
	}
	return count;
}
int ispalindrome(char *number)
{
	int i = 0;
	int lenght = strlen(number) - 1;
	for (i = 0;i <=lenght;i++)
	{
		if (number[i] != number[lenght])
		{
			return 0;
		}
		lenght--;
	}
	return 1;
}