#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>

char *getstring(int *lenght_string);
void get_reverse_string(char * reverse_string, int lenght, char **reversed_string);
int main()
{
	int i = 0;
	int lenght = 0;

	char *get_string = 0;
	char *print_string = 0;

	get_string = getstring(&lenght);
	get_reverse_string(get_string, lenght, &print_string);

	printf("%s", print_string);

	free(get_string);
	getch();

	return 0;
}
char *getstring(int *lenght_string)
{
	int size = 21;
	char *string = 0;

	if (size == NULL)
	{
		printf("Error, you cant allocate 0");
		exit(0);
	}
	string = (char*)malloc(size * sizeof(char));
	printf("Enter the string(max 20 characters): ");
	scanf("%s", string);

	*lenght_string = strlen(string)-1;
	
	return string;

}
void get_reverse_string(char * reverse_string, int lenght, char **reversed_string)
{
	int first_character_postion = 0;
	int second_character_postion = lenght;
	char temp = 0;
	int i = 0;

		for (i = 0; i < lenght; i++)
		{
			temp = *(reverse_string + first_character_postion);
			*(reverse_string + first_character_postion)= *(reverse_string + second_character_postion);
			*(reverse_string + second_character_postion) = temp;
		
			first_character_postion++;
			second_character_postion--;
			if (first_character_postion / second_character_postion ==1)
			{
				break;
			}
			
		}
		*reversed_string = reverse_string;
}