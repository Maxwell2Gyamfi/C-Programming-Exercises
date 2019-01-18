/*******************************************************************************************
* Program Description:
*    -This program will allow a client to manage precious items disposed in a warehouse. 
*     At the start of the program the user will be presented with the Main Menu which
*     will allow them either to create a new account or login with their credentials.
*   
* Main functionalities are:
*    -Login with Email and Password:if successfully logged in, will be presented with the 
*     main warehouse systems menu(Admin/User mode).
*
*    -Admin Mode Functionalities consists of :
*	   -Switch to User Mode
*	   -Display all users accounts
*	   -Search a user account
*	   -Suspend a user account
*	   -Remove account from suspended list
*      -Change Password
*              
*     -User Mode Functionalities consists of:
*      -Add an Item to warehouse
*	   -View all warehouse items
*	   -Search an Item in warehouse
*	   -Delete an Item from warehouse
*	   -Change personal password
*	   -Delete personal account
*
*	  -Create new account: which allows user to create a new account if not present
*      in the system.
*
* User-interface variables:-
*	   *OUT (Return values):
*			- int : Success indicator (0 failure, 1 success)
*	   *IN (Value Parameters):
*			- Uses Value Parameters
*	   *IN and OUT (Reference Parameters):
*			- Uses Reference Parameters
*
* History [Date (Author): Description)]:-
*   2019-17-01 (Maxwell Gyamfi): Warehouse Login Systems
*******************************************************************************************/

//disables visual studio default functions
#pragma warning(disable:4996)

// Standard C library header files (#include ....):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//definitions
#define EMAIL_LENGHT 20
#define PASSWORD_LENGHT 15
#define MAX_LENGHT_DESCRIPTION 40
#define MAX_ACCOUNTS 9999
#define POUND_SIGN 156

//Record data-types declarations
typedef struct Items
{
	int item_number;
	char item_description[MAX_LENGHT_DESCRIPTION];
	float item_price;

}items;

//Record data-types declarations
typedef struct User
{
	int user_id;
	char user_email[EMAIL_LENGHT];
	char user_password[PASSWORD_LENGHT];
	int is_admin;
	int login_attempts;
	int is_suspended;
	int total_items;

}userdetails;

//Record data-types declarations
typedef struct Items_linked_list
{
	items item;
	struct Items_linked_list *next;

}linked_list_items;

//Function prototypes/declarations
void insert(items user_items, linked_list_items **item);
void get_valid_string(char *string);
void display_items(linked_list_items * start);
void append(linked_list_items **linked);
void user_account_menu();
int user_menu(struct User *user, int count, int position);
void Pause();
void admin_account_menu();
int admin_account(struct User *users, int count);
void display_all_accounts(struct User *users, int count);
int remove_account(struct User *users, int count, int position, linked_list_items**head);
int login(struct User *user, int count);
char get_valid_yes_or_no();
void main_display_menu();
int get_valid_integer(int minimum, int maximum);
int isfloat(char *string, int length);
int is_integer(char *string, int length);
int get_string_length(char *string);
int convert_string_to_integer(char *string, int count, int lenght, int sum);
int convert_character_to_integer(char character, char *string, int sum, int value, int count);
int create_account(int *count, struct User *new_user);
void get_valid_password(char *password);
int hasdigit(char *string, int lenght);
int has_upper_case(char *string, int lenght);
void get_valid_email(int number_of_accounts, struct User *users, int login, char *email);
int email_exist(struct User *users, int number_of_accounts, char *string);
int has_at_email(char *string, int lenght);
int has_domain(char *string, int lenght);
void copy_string(char *source, char*destination);
int read_users_file(struct User *users, char *name);
void save_users_files(struct User *users, int count,char *name);
int valid_login_email(struct User *user, int count, char *email);
void save_items_to_file(linked_list_items *item, char *account_email);
void insert(items user_items, linked_list_items **item);
int read_items_from_file(linked_list_items **item, char *account_email);
linked_list_items * sortedmerge(linked_list_items* a, linked_list_items* b);
void frontbacksplit(linked_list_items* head, linked_list_items** aref, linked_list_items** bref);
void mergesort(linked_list_items** headref);
void search_item(linked_list_items* head);
void delete_item(linked_list_items** head);
void change_password(struct User *user, int position);
int check_item_number_duplicate(linked_list_items *head, int item_number);
int load_default_file(linked_list_items** head);
void free_linked_list_items(linked_list_items **head);
int merge_sort(struct User *user, int min, int max);
void merge(struct User *user, int min, int middle, int middle2, int max);
void binary_search_account(struct User *user, int count);
void update_total_elements(linked_list_items *head, struct User *user, int position);
void cipher_password(char *password, char *key, char *pswd, int value);
void suspend_user(struct User *user, int count);
void unsuspend_user(struct User *user, int count);
void send_email(struct User *user, int position);

int main()
{
	//local variables
	int choice = 0;
	int count = 0;

	//allocate memory for user accounts
	userdetails *users =(userdetails*)calloc(MAX_ACCOUNTS,sizeof(userdetails));
	count = read_users_file(users,"all_users.txt");
	
	
	do
	{
		system("cls");//clear screen
		main_display_menu();
		//action selection menu
		choice = get_valid_integer(1, 3);
		switch (choice)
		{
		case 1:
			count == 0 ? printf("\nThere are no accounts in the system"),Pause() :
				(count = login(users, count));
			break;
		case 2:
			create_account(&count, users);
			save_users_files(users, count,"all_users.txt");
			Pause();
			break;
		default:
			printf("\nQuitting!!!");
			Pause();
			break;
		}
	} while (choice != 3);
	//free dynaically allocated memory
	free(users);
	return 0;
}
/**************************************************************************
* Function Name: main_display_menu()
*
* Funtion Description:
*   -This function displays the main menu of the program prompting the user
*    to select an option between, login with email and password and create
*    a new user account.
*          
* User-interface variables:-
*	*OUT (Return values):
*			- NONE
*	*IN (Value Parameters):
*			- NONE
*	*IN and OUT (Reference Parameters):
*			- NONE
*
* History [Date (Author): Description)]:-
* 2019-17-01 (Maxwell Gyamfi): displays main menu
****************************************************************************/
void main_display_menu()
{
	printf("\n\n");
	printf("               WAREHOUSE SYSTEMS MAIN MENU\n");
	printf("               ---------------------------\n");
	printf("  1 ---> Login with email and password\n");
	printf("  2 ---> Create a new account\n");
	printf("  3 ---> Exit program\n\n");
	printf("---> Select an option(1-3): ");
}

/*******************************************************************************
* Function Name: get_valid_integer(int minimum, int maximum)
*
* Funtion Description:
*   -This function requests a user to input an integer value between a mini-
*    mum and a maximum. It will prompt the user to re-input integer value and
*    display a specific error message if wrong input provided. It returns 
*    correct integer value if provided.
*
* User-interface variables:-
*	*OUT (Return values):
*			- int value
*	*IN (Value Parameters):
*			- int minimum, int maximum
*	*IN and OUT (Reference Parameters):
*			- NONE
*
* History [Date (Author): Description)]:-
* 2019-17-01 (Maxwell Gyamfi): gets valid integer input
*******************************************************************************/
int get_valid_integer(int minimum, int maximum)
{
	//local variables
	int sum = 0;
	int lenght = 0;
	int value = 0;
	int success = 0;
	char buffer[10];
	do
	{

		fgets(buffer, sizeof(buffer), stdin);//request string input
		lenght = get_string_length(buffer);//calculate string lenght
		buffer[lenght-1] = '\0';
		lenght = lenght - 1;

		if (isfloat(buffer,lenght))//checks if float value
		{
			printf("\nYou entered a float value, please try again(%d-%d): ",minimum,maximum);
		}
		else if (!is_integer(buffer, lenght))//checks if special character inputted
		{
			printf("\nYou didnt enter an integer, please try again(%d-%d): ", minimum, maximum);
		}
		else
		{
			value = convert_string_to_integer(buffer,0,lenght,sum);//convert value to integer
			if (value< minimum || value > maximum)//changes integer range
			{
				printf("\nThe value is out of range, try again(%d-%d): ", minimum, maximum);
			}
			else
			{
				success = 1;
				return value;
			}
		}

	} while (success == 0);

}

/********************************************************************
* Function Name: char get_valid_yes_or_no()
*
* Funtion Description:
*   -This function requests a user to input a character 'Y'or 'N'
*   -Display specific error message and request to re-input correct
*    input until provided. It will returns the correct character
*   
* User-interface variables:-
*	*OUT (Return values):
*			- char input
*	*IN (Value Parameters):
*			- NONE
*	*IN and OUT (Reference Parameters):
*			- NONE
*
* History [Date (Author): Description)]:-
* 2019-17-01 (Maxwell Gyamfi): gets valid yes or no
***********************************************************************/
char get_valid_yes_or_no()
{
	//local variables
	char input=0;
	int success = 0;
	do
	{
		scanf("%c%*c", &input);//request character and discards scanf buffer
		if (isalpha(input))
		{
			input = toupper(input);//convert character to upper-case
			if (input == 'Y' || input == 'N')
			{
				success = 1;
			}
			else
			{
				printf("Wrong input, please input (Y/N): ");
			}
		}
	} while (success == 0);

	return input;
}

/********************************************************************
* Function Name: isfloat(char *string,int length)
*
* Funtion Description:
*   -This function checks if a '.' character is present in an array
*    of characters.
*
* User-interface variables:-
*	*OUT (Return values):
*			bool(1:True,0:False)
*	*IN (Value Parameters):
*			- char *string,int length
*	*IN and OUT (Reference Parameters):
*			- NONE
*
* History [Date (Author): Description)]:-
* 2019-17-01 (Maxwell Gyamfi): checks if string has '.' value
***********************************************************************/
int isfloat(char *string,int length)
{
	//local variable
	int i = 0;
	
	//loops and look for '.' character
	for (i = 0; i < length; i++)
	{
		if (string[i] == '.')
		{
			return 1;
		}
	}
	return 0;
}

/********************************************************************
* Function Name: int is_integer(char *string,int length)
*
* Funtion Description:
*   -This function checks if an array of characters contains only 
*    numeric values.
*
* User-interface variables:-
*	*OUT (Return values):
*			bool(1:True,0:False)
*	*IN (Value Parameters):
*			- char *string,int length
*	*IN and OUT (Reference Parameters):
*			- NONE
*
* History [Date (Author): Description)]:-
* 2019-17-01 (Maxwell Gyamfi): checks if string has '.' value
***********************************************************************/
int is_integer(char *string,int length)
{
	//local variable
	int i = 0;

	//loops and checks if all characters in array are numeric
	for (i = 0; i < length; i++)
	{
		if (string[i] >= '0' && string[i] <='9'){}
		else
		{
			return 0;
		}
	}
	return 1;
}
int get_string_length(char *string)
{
	int count = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		count++;
		i++;
	}
	return count;
}
int convert_string_to_integer(char *string,int count,int lenght,int sum)
{
	char arr_value = '\0';
	switch(lenght)
	{
	case 1:
		sum = convert_character_to_integer(arr_value, string, sum, 1, count);
		return sum;
		break;
	case 2:
		sum = convert_character_to_integer(arr_value, string, sum, 10, count);
		convert_string_to_integer(string, count+1, lenght-1, sum);
		break;
	case 3:
		sum = convert_character_to_integer(arr_value, string, sum, 100, count);
		convert_string_to_integer(string, count + 1, lenght - 1, sum);
		break;
	case 4:
		sum = convert_character_to_integer(arr_value, string, sum, 1000, count);
		convert_string_to_integer(string, count + 1, lenght - 1, sum);
		break;
	case 5:
		sum = convert_character_to_integer(arr_value, string, sum, 10000, count);
		convert_string_to_integer(string, count + 1, lenght - 1, sum);
		break;
	case 6:
		sum = convert_character_to_integer(arr_value, string, sum, 100000, count);
		convert_string_to_integer(string, count + 1, lenght - 1, sum);
		break;
	default:
		sum = atoi(string);
		return sum;
		break;
	}
}
int convert_character_to_integer(char character, char *string, int sum, int value,int count)
{
	int number = 0;
	character = string[count];
	number = character - '0';
	sum += (number * value);
	return sum;
}
int create_account(int *count,struct User *new_user)
{
	char ptr[20];
	char password[20];
	int flag = 0;
	int id = 0;

	system("cls");
	printf("\n\n");
	printf("            CREATE A NEW ACCOUNT MENU\n");
	printf("            -------------------------\n");
	printf(" ---> Input email: ");
	get_valid_email(*count, new_user,0,ptr);

	while (flag == 0)
	{
		printf(" ---> Input password: ");
		get_valid_password(ptr);
		printf("\n ---> Re-input password: ");
		get_valid_password(password);
		if (strcmp(ptr, password) == 0)flag = 1;
		else printf("\nInputted password didn't match!!\n");
	}
	cipher_password(ptr, new_user[*count].user_email, password, 0);
	strcpy(new_user[*count].user_password, password);

	if (*count == 0)
	{
		new_user[*count].is_admin = 1;
		new_user[*count].login_attempts = 3;
		printf("\nFirst account in system as a result, admin account");
		printf("\nPlease contact developer('Maxwell2.Gyamfi@live.uwe.ac.uk')if wish to change");
	}
	else
	{
		new_user[*count].is_admin = 0;
		new_user[*count].login_attempts = 3;
	}
	new_user[*count].user_id = *count + 100;
	new_user[*count].is_suspended= 0;
	new_user[*count].total_items = 0;
	*count = *count + 1;


	printf("\nAccount created successfully!!!");
}
void get_valid_password(char *password)
{
	int i = 0;
	int k = 0;
	int lenght = 0;
	char ch = '\0';
	char buffer[PASSWORD_LENGHT];
	
	int success = 0;
	do
	{
		memset(buffer, 0, sizeof(buffer));
		while(k<PASSWORD_LENGHT)
		{
			ch = getch();
			if (ch == '\r')
			{
				break;
			}
			else if (ch == '\b')
			{
				if (i > 0)
				{
					i--;
					k--;
					printf("\b \b");
				}
			}
			else
			{
				buffer[i++] = ch;
				ch = '*';
				printf("%c", ch);
				k++;
			}
		}
		lenght = get_string_length(buffer);
		if (lenght > PASSWORD_LENGHT)
		{
			printf("\nPassword is too long,try again: ");
		}
		else if (lenght < 8)
		{
			printf("\nPassword too short,try again: ");
		}
		else if(!hasdigit(buffer,lenght))
		{
			printf("\nYour password should contain at least an integer,try again: ");
		}
		else if (!has_upper_case(buffer, lenght))
		{
			printf("\nYour password should contain at least an upper-case character,try again: ");
		}
		else
		{
			copy_string(buffer,password);
			success = 1;

		}

	} while (success == 0);
}
void cipher_password(char *password,char *key,char *pswd,int value)
{
	int i, j = 0;
	int len_password = strlen(password);
	int len_key = strlen(key);

	char *new_key = (char*)malloc(len_password*sizeof(char));
	char *encrypted_msg = (char*)malloc(len_password*sizeof(char));
	char *decrypted_msg = (char*)malloc(len_password*sizeof(char));

	for (i = 0,j=0; i < len_password; i++,j++)
	{
		if (j == len_key)
		{
			j = 0;
		}
		new_key[i] = key[j];
	}
	new_key[i] = '\0';

	switch (value)
	{
	case 0:
		for (i = 0; i < len_password; i++)
		{
			encrypted_msg[i] = ((password[i] + new_key[i])) + 'A';
		}
		encrypted_msg[i] = '\0';
		strcpy(pswd, encrypted_msg);
		break;
	case 1:
		for (i = 0; i < len_password; i++)
		{
			decrypted_msg[i] = ((password[i] - new_key[i])) - 'A';
		}
		decrypted_msg[i] = '\0';
		strcpy(pswd, decrypted_msg);
		break;
	default:
		break;
	}
}
int hasdigit(char *string,int lenght)
{
	int i = 0;
	for (i = 0; i < lenght; i++)
	{
		if (string[i] >= '0' && string[i] <='9')
		{
			return 1;
		}
	}
	return 0;
}
int has_upper_case(char *string, int lenght)
{
	int i = 0;
	for (i = 0; i < lenght; i++)
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
		{
			return 1;
		}
	}
	return 0;

}
void get_valid_email(int number_of_accounts,struct User *users,int login,char *email)
{
	char buffer[EMAIL_LENGHT];
	int success = 0;
	int lenght = 0;

	do
	{
		fgets(buffer, sizeof(buffer), stdin);
		lenght = get_string_length(buffer);
		buffer[lenght - 1] = '\0';
		lenght = lenght - 1;

		if (lenght > EMAIL_LENGHT)
		{
			printf("\nEmail is too long,try again: ");
		}
		else if (!has_at_email(buffer,lenght))
		{
			printf("\nAn email has at least one '@' character,try again: ");
		}
		else if (!has_domain(buffer,lenght))
		{
			printf("\nYou inputted a wrong domain,try again: ");
		}
		else if (email_exist(users, number_of_accounts,buffer))
		{
			if (login == 1)
			{
				copy_string(buffer, email);
				success = 1;
				break;
			}
			printf("\nYour inputted email exists already, try again: ");
		}
		else
		{
			login == 1?
			    copy_string(buffer, email):
				copy_string(buffer, users[number_of_accounts].user_email);

			success = 1;	
		}
	} while (success == 0);
}
int email_exist(struct User *users, int number_of_accounts,char *string)
{

	int i = 0;
	for (i = 0; i < number_of_accounts; i++)
	{
		if (strcmp(string, users[i].user_email)==0)
		{
			return 1;
		}
	}
	return 0;
}
int has_at_email(char *string, int lenght)
{
	int i = 0;
	for (i = 0; i < lenght; i++)
	{
		if (string[i] == '@')
		{
			return 1;
		}
	}
	return 0;
}
int has_domain(char *string, int lenght)
{
	int i = 0;
	int j = 0;
	char temp[20];
	char string_domain[25];

	memset(temp, 0, sizeof(temp));
	memset(string_domain, 0, sizeof(string_domain));

	char domains[][25] = { "aol.com","att.net","comcast.net","facebook.com","gmail.com",
						 "gmx.com","googlemail.com","google.com","hotmail.com","hotmail.co.uk",
						 "mac.com","me.com", "mail.com","msn.com","live.com","sbcglobal.net",
						 "verizon.net","yahoo.com","yahoo.co.uk","email.com","fastmail.fm",
						 "games.com","gmx.net","hush.com", "hushmail.com","icloud.com",
						 "iname.com","inbox.com","lavabit.com","love.com","outlook.com",
						 "pobox.com","protonmail.com","rocketmail.com","safe-mail.net","wow.com",
						 "ygm.com","ymail.com","zoho.com","yandex.com","hotmail.it","btinternet.com",
						 "virginmedia.com","blueyonder.co.uk","freeserve.co.uk","live.co.uk",
						 "ntlworld.com","o2.co.uk","orange.net","sky.com","talktalk.co.uk",
						 "tiscali.co.uk","virgin.net","wanadoo.co.uk","bt.com","uwe.ac.uk"
	};
	while (string[i] != '\0')
	{
		if (string[i] == '@')
		{
			i++;
			while (string[i] != '\0')
			{
				string_domain[j++] = string[i++];
			}
			break;
		}
		i++;
	}
	for (i = 0; i < 56; i++)
	{
		strcpy(temp, domains[i]);
		if (strcmp(string_domain, temp) == 0)
		{
			return 1;
		}
	}
	return 0;
}
void copy_string(char *source, char*destination)
{
	int i = 0;
	int lenght = get_string_length(source);
	for (i = 0; i < lenght; i++)
	{
		destination[i] = source[i];
	}
	destination[lenght] = '\0';
}
int read_users_file(struct User *users,char *name)
{
	FILE *file;
	int i = 0;
	char s = 0;
	file = fopen(name, "rb");
	if (file == NULL)
	{
		return 0;
	}
	while (s=fgetc(file))
	{
		if (s == EOF)
		{
			break;
		}
		else
		{
			fseek(file, -1, SEEK_CUR);
			fread(&users[i], sizeof(userdetails), 1, file);
			i++;		
		}
	}
	fclose(file);
	return i;
}
void save_users_files(struct User *users, int count,char*name)
{
	int i = 0;
	FILE *file;
	file = fopen(name, "wb");
	if (file == NULL)
	{
		printf("Error saving to file");
		exit(0);
	}
	for (i = 0; i < count; i++)
	{
		fwrite(&users[i], sizeof(struct User), 1, file);
	}
	fclose(file);
}
int login(struct User *user, int count)
{
	int option = 0;
	int position = 0;
	int success = 0;
	char pswd[20];
	char email[EMAIL_LENGHT];
	char password[PASSWORD_LENGHT];
	userdetails *ptr = &user[0];

	memset(email, 0, sizeof(email));
	memset(password, 0, sizeof(password));
	memset(pswd, 0, sizeof(pswd));

	do
	{
		system("cls");
		printf("\n\n");
		printf("          LOGIN MENU\n");
		printf("          ----------\n");
		printf("\n ---> Input email: ");
		get_valid_email(count, user, 1,email);
        
		position = valid_login_email(user, count, email);
		if (position>=0 && user[position].login_attempts > 0 && user[position].is_suspended==0)
		{
			do
			{
				printf(" ---> Input password(attempts remaining:%d): ", user[position].login_attempts);
				get_valid_password(password);
				cipher_password(password, user[position].user_email, pswd, 0);
				if (strcmp(user[position].user_password, pswd) == 0)
				{
					if (user[position].is_admin == 1)
					{
						count = admin_account(user, count);
					}
					else
					{
						count = user_menu(user, count, position);
					
					}
					ptr[position].login_attempts = 3;
					success = 1;
					break;
				}
				else
				{
					ptr[position].login_attempts-=1;
					if (ptr[position].login_attempts == 0)
					{
						ptr[position].is_suspended = 1;
						
						if (ptr[0].is_suspended == 0)
						{
							printf("This account is banned, please contact an admin(%s)", user[0].user_email);
						}
						else if (ptr[0].is_suspended == 1)
						{
							printf("Admin account is banned, please contact developer('Maxwell2.Gyamfi@live.uwe.ac.uk')");
						}
						Pause();
						break;
					}
					system("cls");
					printf("\n\n  PASSWORD INPUT\n");
					printf("      --------------\n");
					printf("\nEmail : %s", user[position].user_email);
					printf("\nIncorrect password(attempts remaining:%d)\n", user[position].login_attempts);
					printf("\n  ---> 1. Try again");
					printf("\n  ---> 2. Send password to email");
					printf("\n  ---> 3. Return to Login Menu");
					printf("\n\n Select an option(1-3): ");
					option = get_valid_integer(1, 3);
					if (option == 2)
					{
						send_email(user, position);
						break;
					}

				}
				success = 1;
			} while (user[position].login_attempts > 0 && option != 3);
		}
		else
		{
			if (user[position].login_attempts == 0 && user[position].is_suspended==1)
			{
				printf("\nThis account is banned, please contact an admin(%s)", user[0].user_email);
				Pause();
				success = 1;
			}
			else
			{
				printf("\nInputted email is not in the system");
				Pause();
				return count;
			}
		}

	} while (success == 0);

	save_users_files(user, count,"all_users.txt");
	return count;
}
int valid_login_email(struct User *user, int count,char *email)
{

	int i = 0;
	for (i = 0; i < count; i++)
	{
		if (strcmp(user[i].user_email, email) == 0)
		{
			return i;
		}
	}
	return -1;
}
void admin_account_menu()
{
	system("cls");
	printf("\n\n");
	printf("             ADMIN MENU\n");
	printf("             ----------\n");
	printf("  1 ---> Switch to user Mode\n");
	printf("  2 ---> Display all users accounts\n");
	printf("  3 ---> Search a user account\n");
	printf("  4 ---> Suspend a user account\n");
	printf("  5 ---> Remove account from suspended list\n");
	printf("  6 ---> Change Password\n");
	printf("  7 ---> Return to main menu\n");
	printf("\nSelect an option(1-7): ");

}
int admin_account(struct User *users, int count)
{
	int choice = 0;
	
	do
	{
		admin_account_menu();
		choice = get_valid_integer(1, 7);
		switch (choice)
		{
		case 1:
			count = user_menu(users,count,0);		
			break;
		case 2:
			merge_sort(users, 0, count - 1);
			display_all_accounts(users, count);
			Pause();
			break;
		case 3:
			merge_sort(users, 0, count - 1);
			binary_search_account(users, count - 1);
			Pause();
			break;
		case 4:
			suspend_user(users, count);
			Pause();
			break;
		case 5:
			unsuspend_user(users, count);
			Pause();
			break;
		case 6:
			change_password(users,0);
			Pause();
			break;
		default:
			break;
		}
	} while (choice != 7);
	return count;
}
void display_all_accounts(struct User *users,int count)
{
	char buffer[20];
	memset(buffer, 0, 20);
	int i = 0;
	char admin = 0;
	char password[20];

	system("cls");
	printf("\n\n");
	printf("                   DISPLAY ALL ACCOUNTS\n");
	printf("                   --------------------\n");
	if (count == 0)
	{
		printf("\nThere are no accounts to display");
		return;
	}

	printf("ID   Email                Password         Admin      Suspended       Total Items\n");
	printf("--   -----                --------         -----      ---------       -----------\n");
	
	for (i = 0; i < count; i++)
	{
			if (users[i].is_suspended == 1)
				strcpy(buffer, "True");
			else
				strcpy(buffer, "False");
			if (users[i].is_admin == 1)
				admin = 'Y';
			else
				admin = 'N';

			cipher_password(users[i].user_password, users[i].user_email, password, 1);
			printf("%-4d %-20s %-16s %-10c %-16s%-4d\n",
				users[i].user_id,
				users[i].user_email,
				password,
				admin, buffer, users[i].total_items);
	}
}
void binary_search_account(struct User *user, int count)
{
	int value = 0;
	int start = 0;
	int half = 0;
	int end = count;
	int success = 0;
	char buffer[20];
	char admin;
	char password[20];
	memset(buffer, 0, 20);

	system("cls");
	printf("\n\n");
	printf("        SEARCH A USER MENU\n");
	printf("        ------------------\n");
	printf(" ---> Input user ID: ");
	value = get_valid_integer(1, 30000);

	while (start <= end)
	{
		    half = (start +end) / 2;
		
			if (user[half].user_id == value)
			{
				if (user[half].is_suspended == 1)
					strcpy(buffer, "True");	
				else
				   strcpy(buffer, "False");	
				if (user[half].is_admin == 1)
					admin = 'Y';	
				else
					admin = 'N';

				cipher_password(user[half].user_password, user[half].user_email, password, 1);

				printf("\nID   Email                Password         Admin      Suspended       Total Items\n");
				printf("--   -----                --------         -----      ---------       -----------\n");
				printf("%-4d %-20s %-16s %-10c %-16s%-4d\n",
					user[half].user_id,
					user[half].user_email,
					password,
					admin, buffer,user[half].total_items);
				    
				success = 1;
				break;
			}
			else
			{
				if (value > user[half].user_id)
				{
					start = half + 1;
				}
				else
				{
					end = half - 1;
				}
			}	
	}
	if (success == 0)
	{
		printf("Element not found");
	}
}
int merge_sort(struct User *user, int min, int max)
{

	int middle;

	if (min < max)
	{
		middle = (min + max) / 2;

		merge_sort(user, min, middle);
		merge_sort(user, middle + 1, max);
		merge(user, min, middle, middle + 1, max);
	}

}
void merge(struct User *user, int min, int middle, int middle2, int max)
{
	struct User temp[MAX_ACCOUNTS];

	int l = 0;
	int i = min;
	int j = middle2;

	while (i <= middle && j <= max)
	{
		if (user[i].user_id < user[j].user_id)
		{
			temp[l++] = user[i++];
		}
		else
		{
			temp[l++] = user[j++];
		}
	}
	while (i <= middle)
	{
		temp[l++] = user[i++];
	}
	while (j <= max)
	{
		temp[l++] = user[j++];
	}
	for (l = min, j = 0; l <= max; l++, j++)
	{
		user[l] = temp[j];
	}
}
void suspend_user(struct User *user, int count)
{

	int i = 0;
	int id = 0;
	char choice = 0;
	struct User *temp = user;

	system("cls");
	printf("\n\n");
	printf("              SUSPEND A USER ACCOUNT\n");
	printf("              -----------------------\n");
	if (count > 1)
	{
		display_all_accounts(user, count);
		printf("\nSelect account to suspend(%d-%d): ",user[1].user_id,user[count-1].user_id);
		id = get_valid_integer(user[1].user_id, user[count - 1].user_id);
		
		for (i = 0; i < count; i++)
		{
			if (id == user[i].user_id)
			{
				printf("\nConfirm suspending account?(Y/N): ");
				choice = get_valid_yes_or_no();
				if (choice == 'Y')
				{
					user = user + i;
					user->is_suspended = 1;
					user->login_attempts = 0;
					display_all_accounts(temp, count);
					printf("\nAccount succesfully suspended!!!");
					break;
				}
				else
				{
					printf("\nAccount not suspended!!!");
				}
			}
		}
	}
	else
	{
		printf("\nImpossible suspending admin account.\nPlease contact a developer('Maxwell2.Gyamfi@live.uwe.ac.uk')");
	}

}
void unsuspend_user(struct User *user, int count)
{

	int i = 0;
	int id = 0;
	char choice = 0;
	int suspended_counter = 0;
	struct User *suspended_list=(struct User*)calloc(MAX_ACCOUNTS,sizeof(struct User));
	struct User *temp = user;
	
	system("cls");
	printf("\n\n");
	printf("              UNSUSPEND A USER ACCOUNT\n");
	printf("              -------------------------\n");

	if (count <= 1)
	{
		printf("\nThere are no accounts to be unsuspended");
		return;
	}
	else
	{
		suspended_list = (struct User*)calloc(MAX_ACCOUNTS, sizeof(struct User));
		{
			if (suspended_list == NULL)
			{
				printf("Error allocating memory");
				return;
			}
		}
		for (i = 0; i < count; i++)
		{
			if (user[i].is_suspended == 1 && user[i].login_attempts == 0)
			{
				suspended_list[suspended_counter++] = user[i];
			}
		}
		if (suspended_counter > 0)
		{
			display_all_accounts(suspended_list, suspended_counter);
			printf("\nSelect account to unsuspend(%d-%d): ", suspended_list[0].user_id, suspended_list[suspended_counter - 1].user_id);
			id = get_valid_integer(suspended_list[0].user_id, suspended_list[suspended_counter-1].user_id);

			if (id_exist(suspended_list, suspended_counter, id))
			{
				for (i = 0; i < count; i++)
				{
						if (id == user[i].user_id)
						{
							printf("\nConfirm unsuspending account?(Y/N): ");
							choice = get_valid_yes_or_no();
							if (choice == 'Y')
							{
								user += i;
								user->is_suspended = 0;
								user->login_attempts = 3;
								printf("\nAccount succesfully unsuspended!!!");
								break;
							}
							else
							{
								printf("\nAccount was not unsuspended");
								break;
							}
						}
				}
			}
			else printf("\nIncorrect Account ID selection!!!");
		}
		else printf("\nThere are no accounts to be unsuspended!!!");
		free(suspended_list);
	}
}
int id_exist(struct User*banned, int count,int id)
{
	int i = 0;

	for (i = 0; i < count; i++)
	{
		if (banned[i].user_id == id)
		{
			return 1;
		}
	}
	return 0;
}
int remove_account(struct User *users, int count,int position,linked_list_items**head)
{
	int status = 0;
	int i = 0;
	char choice = '\0';
	int old_position = position;
	userdetails temp;
	userdetails *ptr = &users[0];

	if (position == 0)
	{
		printf("\n\Admin account cannot be removed,\nPlease contact developer('Maxwell2.Gyamfi@live.uwe.ac.uk')");
		return count;
	}
	
	printf("\nConfirm removing your account?(Y/N): ");
	choice = get_valid_yes_or_no();
	if (choice == 'Y')
	{
		free_linked_list_items(head);
		status = remove(users[position].user_email);

		while (position < count)
		{
			temp = ptr[position];
			ptr[position] = ptr[position + 1];
			ptr[position + 1] = temp;
			position++;
		}
		count -= 1;
		save_users_files(users, count,"all_users.txt");
		printf("\nAccount removed successfully!!!!");
	}
	else
	{
		printf("\nAccount not removed");
	}
	return count;
}
void user_account_menu()
{
	system("cls");
	printf("\n\n            USER MENU\n");
	printf("            ---------\n\n");
	printf("  1  ---> Add an Item\n");
	printf("  2  ---> View all items\n");
	printf("  3  ---> Search an Item\n");
	printf("  4  ---> Delete an Item\n");
	printf("  5  ---> Change password\n");
	printf("  6  ---> Delete account\n");
	printf("  7  ---> Return to Main Menu");

}
int user_menu(struct User *user,int count,int position)
{
	linked_list_items *head = NULL;
	
	if (!read_items_from_file(&head, user[position].user_email))
	{
		load_default_file(&head);
	}
	int choice = 0;

	do
	{
		update_total_elements(head,user,position);
		user_account_menu();
		printf("\n\nInput your choice(1-7): ");
		choice = get_valid_integer(1, 7);

		switch (choice)
		{
		case 1:
			append(&head);
			update_total_elements(head,user,position);
			Pause();
			save_items_to_file(head, user[position].user_email);
			break;
		case 2:
			mergesort(&head),
			display_items(head);
			Pause();
			break;
		case 3:
			search_item(head);
			Pause();
			break;
		case 4:
			delete_item(&head);
			update_total_elements(head,user,position);
			Pause();
			save_items_to_file(head, user[position].user_email);
			break;
		case 5:
			change_password(user,position);
			Pause();
			break;
		case 6:
			count = remove_account(user,count,position,&head);
			Pause();
			return count;
			break;
		}
	} while (choice != 7);
	free_linked_list_items(&head);
	return count;
}
void append(linked_list_items **linked)
{
	linked_list_items * new_linked_list = malloc(sizeof(linked_list_items));
	linked_list_items *last = *linked;
	linked_list_items *temp = *linked;
	items item;

	if (new_linked_list == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}

	system("cls");
	printf("\n\n");
	printf("        ADD NEW ITEM MENU\n");
	printf("        -----------------\n");

	printf("\nInput item number(1-30000): ");
	item.item_number = get_valid_integer(1, 30000);
	while (check_item_number_duplicate(temp, item.item_number))
	{
		item.item_number = get_valid_integer(1, 30000);
		check_item_number_duplicate(temp, item.item_number);
	}

	printf("Input item description(max char:40): ");
	get_valid_string(item.item_description);

	printf("Input item price(1-9999): ");
	item.item_price = get_valid_integer(1, 9999);

	new_linked_list->item = item;

	new_linked_list->next = NULL;
	if (*linked == NULL)
	{
		*linked = new_linked_list;
		printf("\nItem added successfully!!!");
		Pause();
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_linked_list;
	printf("\nItem added successfully!!!");
	

}
void update_total_elements(linked_list_items *head,struct User *user,int position)
{
	int total_elements = 0;
	while (head != NULL)
	{
		head = head->next;
		total_elements++;
	}
	user[position].total_items = total_elements;
}
void display_items(linked_list_items * start)
{
	
	system("cls");
	printf("\n\n");
	printf("    DISPLAY ALL ITEMS\n");
	printf("    -----------------\n");
	if (start == NULL)
	{
		printf("\nThere are no items to be displayed");
		return;
	}
	else
	{
		printf("\nItem Number              Item Description                         Item Price\n");
		printf("-----------              ----------------                         ----------\n");

		while (start != NULL)
		{
			printf("%-25d%-41s%c %5.1f\n",
				start->item.item_number, start->item.item_description,POUND_SIGN, start->item.item_price);
			start = start->next;
		}
	}
	
}
void get_valid_string(char *string)
{
	char buffer[MAX_LENGHT_DESCRIPTION];
	int success = 0;
	do
	{
		fgets(buffer, sizeof(buffer), stdin);
		int lenght = strlen(buffer);
		buffer[lenght - 1] = '\0';

		if (strlen(buffer) < 1)
		{
			printf("Decription too short, try again: ");
		}
		else if (strlen(buffer) > MAX_LENGHT_DESCRIPTION)
		{
			printf("Decription too long, try again: ");
		}
		else
		{
			strcpy(string, buffer);
			success = 1;
		}
	} while (success == 0);
}
void Pause()
{

	printf("\n\nPress any key to continue...");
	getch();

}
void save_items_to_file(linked_list_items *item,char *account_email)
{
	FILE *file;
	items user_item;
	linked_list_items *head = item;
	file = fopen(account_email, "wb");
	if (file == NULL)
	{
		printf("Error writing to file");
		exit(0);
	}
	while (head != NULL)
	{
		user_item = head->item;
		fwrite(&user_item, sizeof(items), 1, file);
		head = head->next;
	}
	fclose(file);

}
int read_items_from_file(linked_list_items **item, char *account_email)
{

	FILE *file;
	char *s;
	int count = 0;
	items user_item;

	file = fopen(account_email, "rb");

	if (file == NULL)
	{
		return 0;
	}

	while (s = fgetc(file))
	{
		if (s == EOF)
		{
			break;
		}
		else
		{
			fseek(file, -1, SEEK_CUR);
			fread(&user_item, sizeof(items), 1, file);
			insert(user_item, item);
			count++;
		}
	}
	fclose(file);
	return(count > 0 ? 1 : 0);
}
void insert(items user_items, linked_list_items **item)
{

	linked_list_items * new_linked_list = malloc(sizeof(linked_list_items));
	linked_list_items *last = *item;

	if (new_linked_list == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}

	new_linked_list->item = user_items;
	new_linked_list->next = NULL;

	if (*item == NULL)
	{
		*item = new_linked_list;
		return;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_linked_list;
}
linked_list_items * sortedmerge(linked_list_items* a, linked_list_items* b)
{
	linked_list_items* result = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	if (a->item.item_number <= b->item.item_number)
	{
		result = a;
		result->next = sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next);
	}
	return result;
}
void frontbacksplit(linked_list_items* head, linked_list_items** aref, linked_list_items** bref)
{
	linked_list_items* slow;
	linked_list_items* fast;
	if (head == NULL || head->next == NULL)
	{
		*aref = head;
		*bref = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*aref = head;
		*bref = slow->next;
		slow->next = NULL;
	}
}
void mergesort(linked_list_items** headref)
{
	linked_list_items* head = *headref;
	linked_list_items* a;
	linked_list_items* b;
	if ((head == NULL) || (head->next == NULL))
		return;
	frontbacksplit(head, &a, &b);
	mergesort(&a);
	mergesort(&b);
	*headref = sortedmerge(a, b);
}
void search_item(linked_list_items* head)
{
	int item_number = 0;
	linked_list_items * current = head;
	system("cls");
	printf("\n\n      SEARCH AN ITEM MENU\n");
	printf("       -------------------\n");

	printf("---> Input item to be searched(1-30000): ");
	item_number = get_valid_integer(1, 30000);

	while (current != NULL)
	{
		if (current->item.item_number == item_number)
		{
			printf("\nItem Number              Item Description                         Item Price\n");
			printf("-----------              ----------------                         ----------\n");
			printf("%-25d%-41s%c %5.1f\n",
				current->item.item_number, current->item.item_description,POUND_SIGN, current->item.item_price);
			return;
		}
		current = current->next;
	}
	printf("\nItem not found!!!");
	return;


}
void delete_item(linked_list_items** head)
{
	int itemnumber = 0;
	char *choice = '\0';
	linked_list_items *previous =NULL;
	linked_list_items *current = *head;
	
	system("cls");
	printf("\n\n");
	printf("  DELETE AN ITEM MENU\n");
	printf("  -------------------");

	display_items(current);
	printf("\nSelect item to be removed: ");
	itemnumber = get_valid_integer(1, 30000);
	
	if (current != NULL && current->item.item_number == itemnumber)
	{
		printf("Confirm removing selected item?(Y/N): ");
		choice = get_valid_yes_or_no();
		if (choice == 'Y')
		{
			*head = current->next;
			free(current);
			display_items(*head);
			printf("\nSelected item successfully removed!!!");	
			return;
		}
		else
		{
			printf("\nSelected item was not removed!!!");	
			return;
		}
	}

	while (current != NULL && current->item.item_number !=itemnumber)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		printf("Item was not found");
		Pause();
		return;
	}

	printf("\nConfirm removing selected item?(Y/N): ");
	choice = get_valid_yes_or_no();
	if (choice == 'Y')
	{
		previous->next = current->next;
		free(current);
		display_items(*head);
		printf("\nSelected item successfully removed!!!");
		Pause();
		return;
	}
	else
	{
		printf("\nSelected item was not removed!!!");
		Pause();
		return;
	}

}
void change_password(struct User *user,int position)
{
	char buffer[20];
	char ptr[20];
	int flag = 0;
	char password[20];

	system("cls");
	printf("\n\n");
	printf("          CHANGE PASSWORD MENU\n");
	printf("          --------------------\n");

	
	printf("Input previous password: ");
	get_valid_password(buffer);
	cipher_password(buffer, user[position].user_email, password, 0);

	if (strcmp(password, user[position].user_password) == 0)
	{
		while (flag == 0)
		{
			printf("\n ---> Input new password: ");
			get_valid_password(ptr);
			printf("\n ---> Re-input password: ");
			get_valid_password(buffer);

			if (strcmp(ptr, buffer) == 0)
			{
				cipher_password(ptr, user[position].user_email,buffer,0);
				strcpy(user[position].user_password, buffer);
				printf("\nPassword successfully changed!!!");
				flag = 1;
			}
			else printf("\nInputted password didn't match, try again: ");
		}
	}
	else
	{
		printf("\nIncorrect password!!!");
	}
}
int check_item_number_duplicate(linked_list_items *head,int item_number)
{
	
	linked_list_items *current = head;

		while (current != NULL)
		{
			if (current->item.item_number == item_number)
			{
				printf("\nAn item with number '%d' is already in the system,try again: ", item_number);
				return 1;
			}
			current = current->next;
		}
	
	return 0;
}
int load_default_file(linked_list_items** head)
{
	FILE *file;
	char buffer[60];
	long int value = 0;
	float value2 = 0;
	struct Items new_item;

	file = fopen("default.txt", "rb");

	if (file == NULL)
	{
		printf("Error opening file");
		return;
	}
	while (fscanf(file, "%d %s %f", &value, buffer, &value2)==3)
	{
		new_item.item_number = value;
		strcpy(new_item.item_description, buffer);
		new_item.item_price = value2;
		insert(new_item, head);
	}
	
}
void free_linked_list_items(linked_list_items **head)
{
	linked_list_items *temp;
	linked_list_items *current = *head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
void send_email(struct User *user, int position)
{
	char password[20];
	char cmd[100]; 
	char to[20]; 
	char body[20];
	char tempFile[100];     // name of tempfile.
	cipher_password(user[position].user_password, user[position].user_email, password, 1);

	strcpy(body, password);
	strcpy(to, user[position].user_email);
	strcpy(tempFile, tempnam("/tmp", "sendmail"));

	FILE *fp = fopen(tempFile, "w"); // open it for writing.
	fprintf(fp, "%s\n", body);        // write body to it.
	fclose(fp);             // close it.

	sprintf(cmd, "sendmail %s < %s", to, tempFile); // prepare command.
	system(cmd);     // execute it.

	
}


