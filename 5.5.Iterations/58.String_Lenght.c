#pragma warning(disable:4996)
#include <stdio.h>

void get_string(char *n, int lenght);
int calculate_lenght(char *n);

int main()
{
	char string[20];
	int lenght = 0;


	printf("Input a string: ");
	get_string(string,sizeof(string));

	lenght = calculate_lenght(string);
	string[lenght] = '\0';

	printf("The string contains %d number of characters", lenght);
	printf("\nSo, the length of the string %s is : %d", string, lenght);

	getch();
	return 0;
}
void get_string(char *n,int lenght)
{

	fgets(n, lenght, stdin);

}
int calculate_lenght(char *n)
{
	int i = 0;
	
	while (n[i] != '\n')
	{
		i++;
	}
	return i;
}