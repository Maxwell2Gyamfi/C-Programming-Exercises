#pragma warning (disable:4996)

#include <string.h>
#include <stdio.h>

int get_digit();
void get_word(int number);

int main()
{

	get_digit();
	getch();

	return 0;
}
int get_digit()
{

	int number = 0;
	
	printf("Test data: ");
	scanf("%d", &number);
	get_word(number);

}
void get_word(int number)
{
	char buffer[3];
	char *digits[11] = { "zero","one","two",
		                 "three","four","five",
		                "six","seven","eight",
		                 "nine","ten"};

	sprintf(buffer, "%d", number);
	int lenght = strlen(buffer);

	if (lenght == 1)
	{
		switch (buffer[0])
		{
		case '0':printf("%s", digits[0]);break;
		case '1':printf("%s", digits[1]);break;
		case '2':printf("%s", digits[2]);break;
		case '3':printf("%s", digits[3]);break;
		case '4':printf("%s", digits[4]);break;
		case '5':printf("%s", digits[5]);break;
		case '6':printf("%s", digits[6]);break;
		case '7':printf("%s", digits[7]);break;
		case '8':printf("%s", digits[8]);break;
		case '9':printf("%s", digits[9]);break;
		default:printf("Incorrect input"); break;
		}
	}
	if (lenght == 2)
	{
		switch (buffer[0])
		{
		case '1':
			switch (buffer[1])
			{
			case '0':printf("%s", digits[10]);break;
			default:printf("Incorrect input");break;
			}
		}
	}
}
