#pragma warning(disable:4996)

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char remove_white_line(char *input);
void get_month(char *buffer);
void get_number();

int main()
{
	get_number();
	getch();
	return 0;
}
void get_number()
{
	char *buffer = (char *)malloc(2 * sizeof(char));

	if (buffer == NULL)
	{
		fputs("Error allocating memory", stderr);
		exit(0);
	}

	fputs("Test data: ",stdout);
	fgets(buffer, sizeof(buffer), stdin);

	remove_white_line(buffer);
	get_month(buffer);
	
}
void get_month(char *buffer)
{
	int number = 0;
	sscanf(buffer, "%d", &number);

	switch (number)
	{
	case 1:printf("January"); break;
	case 2:printf("Febuary"); break;
	case 3:printf("March"); break;
	case 4:printf("April"); break;
	case 5:printf("May"); break;
	case 6:printf("June"); break;
	case 7:printf("July"); break;
	case 8:printf("August"); break;
	case 9:printf("September"); break;
	case 10:printf("October"); break;
	case 11:printf("November"); break;
	case 12:printf("December"); break;
	default:printf("Incorrect input"); break;
	}

}
char remove_white_line(char *input)
{
	int lenght = strlen(input);
	int i = 0;
	char input1[2];

	while (input[i] !='\n')
	{
		
		input1[i] = input[i];
		i++;
	}
	strcpy(input, input1);
}