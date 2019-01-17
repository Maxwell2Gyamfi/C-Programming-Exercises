#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#define MAX_SIZE 50

int has_special_characters(char *n);
void get_valid_name(char *n);
void save_to_file(int numrecords, struct client m[]);
int read_records(struct client m[]);
void print_all_details(struct client m[], int numrecords);
void menu();
int has_digit(char *n);
void get_email(char *n, struct client m[], int numrecords);
int has_at_domain(char *n);
void get_get_client_details(struct client m[], int *numrecords);
void get_password(char *n);
int has_upper(char *n);
int has_digit1(char *n);
char get_yes_or_no();

typedef struct client
{
	char name[MAX_SIZE];
	char email[MAX_SIZE];
	char password[MAX_SIZE];

}clientdetails;
int main()
{
	int choice = 0;
	
	clientdetails k[200];
	int numrecords = 0;
	numrecords = read_records(k);
	menu();
	printf("Input your choice: ");
	scanf("%d%*c", &choice);
	
	switch (choice)
	{
		case 1:
			break;
		case 2:
			get_get_client_details(k, &numrecords);
			break;
		case 3:
			print_all_details(k, numrecords);
			break;
		default:
			printf("Wrong choice\n");
			break;
	}
	getch();
	return 0;
}
void menu()
{
	printf("1.Login with your details\n");
	printf("2.Create new account\n");
	printf("3.Print all clients details\n");

}
void get_get_client_details(struct client m[], int *numrecords)
{
	int num = *numrecords;
	char reply = '\0';
	do
	{
		get_valid_name(m[num].name);
		get_email(m[num].email, m, num);
		get_password(m[num].password);
		num++;
		printf("Add another record?: (Y/N)");
		reply = get_yes_or_no();

	} while (reply == 'Y');
	save_to_file(num, m);
	*numrecords = num;
}
void print_all_details(struct client m[], int numrecords)
{
	int i = 0;
	for (i = 0; i < numrecords; i++)
	{
		printf("%s", m[i].email);
		printf("\n%s", m[i].name);
		printf("\n");
	}
}
int read_records(struct client m[])
{
	int i = 0;
	clientdetails temp;
	int numrecords = 0;
	FILE *file;
	file = fopen("database.txt", "rb");
	if (file == NULL)
	{
		printf("No file found\n");
		return 0;
	}
	while (!feof(file))
	{
	    fread(&m[numrecords], sizeof(struct client), 1, file);
		numrecords++;
	}
	fclose(file);
	return numrecords;
}
void save_to_file(int numrecords,struct client m[])
{
	int i = 0;
	FILE *file;
	file = fopen("database.txt", "wb");
	if (file == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	for (i = 0; i < numrecords; i++)
	{
		fwrite(&m[i], sizeof(struct client), 1, file);
	}
	fclose(file);

}
void get_valid_name(char *n)
{
	int lenght = 0;
	char buffer[MAX_SIZE];
	int success = 0;
	do
	{
		printf("Input client name: ");
		fgets(buffer, sizeof(buffer), stdin);
		lenght = strlen(buffer);
		buffer[lenght-1] = '\0';

		if (has_special_characters(buffer))
		{
			printf("A name only has alphabets\n");
		}
		else if (strlen(buffer) > MAX_SIZE)
		{
			printf("Your name is too long,try again\n");
		}
		else
		{
			strcpy(n, buffer);
			success = 1;
		}
		
	} while (success == 0);
}
int has_special_characters(char *n)
{
	int i = 0;
	int lenght = strlen(n);
	for (i = 0; i < lenght; i++)
	{
		if (isalpha(n[i])){}
		else if (n[i] == ' ' || n[i] == '-'){}
		else
		{
			return 1;
		}
	}
	return 0;
}
void get_email(char *n,struct client m[],int numrecords)
{
	int success = 0;
	char buffer[MAX_SIZE];
	do
	{
		printf("Input your email: ");
		scanf("%s", buffer);
		if (has_at_domain(buffer))
		{
			if (has_digit(buffer))
			{
				if (!email_exists(m, numrecords, buffer))
				{
					if (strlen(buffer) > 15)
					{
						strcpy(n, buffer);
							success = 1;
							break;
					}
					else
					{
						printf("Email too short\n");
					}
				}
				else
				{
					printf("email exist already\n");
				}
			}
			else
			{
				printf("Email needs a digit\n");
			}
		}
		else
		{
			printf("Wrong email format,try again\n");
		}
	} while (success == 0);

}
int email_exists(struct client m[],int numrecords,char *email)
{
	int i = 0;
	for (i = 0; i < numrecords; i++)
	{
		if (strcmp(m[i].email, email) == 0)
		{
			return 1;
		}
	}
	return 0;

}
int has_digit(char *n)
{
	int i = 0;
	for (i = 0; i < strlen(n); i++)
	{
		if (isdigit(n[i]))
		{
			return 1;
		}
	}
	return 0;
}
int has_at_domain(char *n)
{

	char domain[][15] = { "hotmail.co.uk","gmail.co.uk","outlook.co.uk",
                          "hotmail.it","gmail.it","outlook.it",
						   "hotmail.com","gmail.com","outlook.com"};
	int s = 0;
	char buffer[20];
	char buffer2[20];
	memset(buffer, 0, sizeof(buffer));
	memset(buffer2, 0, sizeof(buffer2));
	int j = 0;
	int i = 0;
	for (i = 0; i < strlen(n); i++)
	{
		if (n[i] == '@')
		{
			j = i+1;
			while (n[j] != '\0')
			{
				buffer[s++] = n[j++];
			}
			for (j = 0; j < 9; j++)
			{
				strcpy(buffer2, domain[j]);
				if (strcmp(buffer, buffer2) == 0)
				{
					return 1;
				}
			}
			return 0;
		}
	}
	return 0;
}
void get_password(char *n)
{
	char buffer[MAX_SIZE];
	int success = 0;
	do
	{
		printf("Enter a password: ");
		scanf("%s%*c", buffer);
		if (!has_upper(buffer))
		{
			printf("You need at least a capital letter\n");
		}
		else if (!has_digit1(buffer))
		{
			printf("You need a digit\n");
		}
		else if (strlen(buffer) < 10)
		{
			printf("Password too short,try again\n");
		}
		else
		{
			strcpy(n, buffer);
			success = 1;
		}

	} while (success == 0);
}
int has_upper(char *n)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < strlen(n); i++)
	{
		if(isupper(n[i]))
		{
			count++;
		}
	}
	return (count > 0 ? 1 : 0);


}
int has_digit1(char *n)
{
	int i = 0;
	for (i = 0; i < strlen(n); i++)
	{
		if (isdigit(n[i]))
		{
			return 1;
		}
	}
	return 0;
}
char get_yes_or_no()
{
	int success = 0;
	char reply = '\0';
	do
	{
		scanf("%c%*c", &reply);
		reply = toupper(reply);
		if (reply == 'Y' || reply == 'N')
		{
			success = 1;
			return reply;
		}
		else
		{
			printf("Incorrect character,try again\n");
		}

	} while (success == 0);
}