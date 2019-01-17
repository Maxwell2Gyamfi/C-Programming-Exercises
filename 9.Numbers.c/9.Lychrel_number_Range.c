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
	int q = 0;
	int start = 1;
	int count2 = 0;
	int number = get_number();

	printf("\nThe Lychrel numbers are: ");
	while (start < number )
	{
		q = lycherel(start, 0);
		start++;
		if (q == 1) count2++;
	}
	printf("\n\nThe number of Lychrel numbers are: %d", count2);

	getch();
	return 0;
}
int get_number()
{
	int number = 0;
	printf("Input the upper limit: ");
	scanf("%d", &number);
	return number;
}
int lycherel(long long int number, int counter)
{
	if (counter == 0)
	{
		s = number;
	}
	if (counter == 500)
	{
		printf("%d ", s);
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
			return 0;
		}
		lycherel(add, counter + 1);
	}
}
void swap(char *buffer, int lenght)
{
	int i = 0;
	lenght = lenght - 1;
	char *ptr = buffer;
	char temp;

	for (i = 0;i <= lenght;i++)
	{
		temp = ptr[i];
		ptr[i] = ptr[lenght];
		ptr[lenght] = temp;
		lenght--;
	}
}
int lenght_convert_tostring(long long int number, char *string)
{
	int count = 0;
	long long int k = number;
	int lenght = 0;
	char buffer[30];

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
	for (i = 0;i <= lenght;i++)
	{
		if (number[i] == number[lenght]){}
		else
		{
			return 0;
		}
		lenght--;
	}
	return 1;
}