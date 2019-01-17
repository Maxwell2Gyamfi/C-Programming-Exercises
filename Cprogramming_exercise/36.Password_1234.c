#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getpassword();
void print_result(char *response);


int main()
{
	char *password = 0;
	password = getpassword();
	print_result(password);
    
	getch();
	return 0;
}

char *getpassword()
{
	static char password[6];
	static char response[20];
	int success = 0;

	do
	{
		printf("Enter the password: ");
		scanf("%s", password);

		if (strcmp(password, "1234") == 0)
		{
			success = 1;
			strcpy(response, "Correct password");
			return response;
		}
		else
		{
			printf("Incorrect password, please try again\n\n");

		}

	} while (success == 0);
	

}
void print_result(char *response)
{
	int lenght = strlen(response);

	int i = 0;
	for (i = 0; i < lenght;i++)
	{
		printf("%c", response[i]);
	}

}