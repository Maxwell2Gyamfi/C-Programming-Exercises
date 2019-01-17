#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char get_valid_string(char *input1);
struct client get_client_details(struct client m[], int *numberecords);
int idexist(int *id1, int numberecords, struct client *m);
char get_yes_or_no();
int not_alpha(char *input, int lenght);
int exist(int id, struct client *m, int numberecords);
int get_clients_details2(struct client k[], int numrecords);
int get_valid_integer(int minimum, int maximum);
int isfloat(char *input, int lenght);
int is_special_character(char *input, int lenght);
int isalphabet(char *input, int lenght);
int range(int number, int minimum, int maximum);
void display_client_details(int id, struct client *m);
int display_another_client(int numrecords);

typedef struct client
{
	int client_id;
	char name[20];
	int unit_consumed;
	float amount_charges;
	float surchage_amount;
	float net_amount_paid;
	float rs;

}Electricity;

int main()
{
	int numrecords = 0;
	Electricity m[200];

	
	get_client_details(m, &numrecords);
	get_clients_details2(m, numrecords);
	

	getch();
	return 0;
}
struct client get_client_details(struct client m[], int *numberecords)
{
	char choice = 0; int numrecords = 0;

	do
	{
		idexist(&m[numrecords].client_id, numrecords, m);

		printf("Enter client name: ");
		get_valid_string(m[numrecords].name);

		printf("Enter units consumed: ");
		m[numrecords].unit_consumed = get_valid_integer(100, 1000);


		printf("Would you like to add another record?(Y/N): ");
		choice = get_yes_or_no();

		if (choice == 'Y')
		{
			numrecords++;
			printf("\nAdding new client.....\n");
		}

	} while (choice == 'Y');
	*numberecords = numrecords;
}

int get_clients_details2(struct client k[], int numrecords)
{
	int i = 0;
	int id = 0;
	int count = 0;
	int success = 0;
	int attempts = 3;
	char display = 0;
	
	Electricity *m;
	m = k;

	do
	{
		printf("\nEnter client ID to display their details: ");
		id = get_valid_integer(1, 10000);

		for (i = 0; i <= numrecords; i++)
		{
			if (id == m->client_id)
			{
				if (m->unit_consumed >= 100 && m->unit_consumed < 199)
				{
					m->amount_charges = m->unit_consumed * 1.20;
					m->surchage_amount = 0;
					m->net_amount_paid = m->amount_charges + m->surchage_amount;
					m->rs = 1.20;
				}
				else if (m->unit_consumed >= 200 && m->unit_consumed < 400)
				{
					m->amount_charges = m->unit_consumed *1.50;
					m->surchage_amount = 0;
					m->net_amount_paid = m->amount_charges + m->surchage_amount;
					m->rs = 1.50;
				}
				else if (m->unit_consumed >= 400 && m->unit_consumed < 600)
				{
					m->amount_charges = m->unit_consumed *1.80;
					m->surchage_amount = m->amount_charges * 0.15;
					m->net_amount_paid = m->amount_charges + m->surchage_amount;
					m->rs = 1.80;
				}
				else
				{
					m->amount_charges = m->unit_consumed *2.00;
					m->surchage_amount = m->amount_charges * 0.15;
					m->net_amount_paid = m->amount_charges + m->surchage_amount;
					m->rs = 2.00;
				}

				display_client_details(id, m);
				m = k;
				success = display_another_client(numrecords);

			}
			else
			{
				if (i == numrecords)
				{
					printf("Client id doesnt exist,you have %d attempts\n", attempts);
					attempts--;

					if (attempts == -1)
					{
						printf("Quitting....");
						success = 1;
					}
				}
			}
			if (i < numrecords)
			{
				m++;
			}
		}
	} while ((success == 0) || (display_another_client==0));
}
int display_another_client(int numrecords)
{
	char display = 0;
	int success = 1;

	if (numrecords > 0)
	{
		printf("\nWould you like to display another client?");
		display = get_yes_or_no();

		if (display == 'Y')
		{
			return 0;
		}
		if (display == 'N')
		{
			return 1;
		}
	}
	else
	{
		return success;
	}

}

void display_client_details(int id, struct client *m)
{
	printf("\nCustomer IDNO :%d", m->client_id);
	printf("\nCustomer Name :%s", m->name);
	printf("\nUnit consumed: %d", m->unit_consumed);
	printf("\nAmount Charges:@Rs. %.2f per unit: %.2f", m->rs, m->amount_charges);
	printf("\nSurchage Amount: %.2f", m->surchage_amount);
	printf("\nNet Amount Paid By the Customer: %.2f", m->net_amount_paid);

}
int idexist(int *id1, int numberecords, struct client *m)
{
	int success = 0;
	int i = 0;
	int id = 0;
	do
	{
		printf("Enter client ID: ");
		id = get_valid_integer(0, 10000);

		if (numberecords == 0)
		{
			*id1 = id;
			success = 1;
		}
		else if (exist(id, m, numberecords))
		{
			printf("ID exist already\n");
		}
		else
		{
			*id1 = id;
			success = 1;
		}

	} while (success == 0);


}
int exist(int id, struct client *m, int numberecords)
{
	int id2 = 0;
	int i = 0;

	for (i = 0; i < numberecords; i++)
	{
		id2 = m[i].client_id;

		if (id == id2)
		{
			return 1;
		}
	}
	return 0;

}
char get_valid_string(char *input1)
{
	int ch;
	int success = 0;
	static char buffer[20];
	static char input[20];
	int lenght = 0;

	do
	{
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%s", input);
		lenght = strlen(input);

		if (not_alpha(input, lenght))
		{
			printf("Only alphabets allowed");
		}
		else
		{
			strcpy(input1, input);
			success = 1;
		}

	} while (success == 0);

}
char get_yes_or_no()
{
	int ch = 0;
	char input;
	int success = 0;
	
	do
	{
		scanf("%c", &input);
		while ((ch = getchar()) != '\n' && ch != EOF);

		input = toupper(input);


		if ((input == 'Y') || (input == 'N'))
		{
			success = 1;
			return input;
		}
		else
		{
			printf("Wrong input");
		}


	} while (success == 0);

}
int remove_white_space(char *input, int lenght1, int *lenght2)
{
	size_t i;

	for (i = 0; i < lenght1; i++)
	{
		if (input[i] == '\n')
		{
			*(input + i) = '\0';
			*lenght2 = lenght1 - 1;
		}

	}
}
int not_alpha(char *input, int lenght)
{
	size_t i;

	for (i = 0; i < lenght; i++)
	{
		if (isalpha(input[i])) {}
		else
		{
			return 1;
		}
	}
	return 0;
}
int get_valid_integer(int minimum, int maximum)
{
	int ch = 0;
	int lenght1 = 0;
	int lenght = 0;
	int success = 0;
	static char buffer[10];
	static char input[10];
	int valid_number = 0;

	do
	{
		fgets(buffer, sizeof(buffer), stdin);
		lenght1 = strlen(buffer);
		remove_white_space(buffer, lenght1, &lenght);


		if (isfloat(buffer, lenght))
		{
			printf("Floats not allowed");
		}
		else if (is_special_character(buffer, lenght))
		{
			printf("Special characters not allowed");
		}
		else if (isalphabet(buffer, lenght))
		{
			printf("Alpabets not allowed");
		}
		else
		{
			valid_number = atoi(buffer);
			range(valid_number, minimum, maximum);
			success = 1;
			return valid_number;
		}



	} while (success == 0);

}
int isfloat(char *input, int lenght)
{
	size_t i;

	for (i = 0; i < lenght; i++)
	{
		if (input[i] == '.')
		{

			return 1;
		}
	}
	return 0;

}
int is_special_character(char *input, int lenght)
{
	int i;

	for (i = 0; i < lenght; i++)
	{
		if ((isalpha(input[i])) || (isdigit(input[i])))
		{

		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int isalphabet(char *input, int lenght)
{

	size_t i;

	for (i = 0; i < lenght; i++)
	{
		if (isalpha(input[i]))
		{
			return 1;
		}
	}
	return 0;

}
int range(int number, int minimum, int maximum)
{
	int success = 0;
	int input = 0;
	do {
		if (number < minimum && input >maximum)
		{
			printf("Out of range\n");
		}
		else {
			success = 1;
		}
	} while (success == 0);
}