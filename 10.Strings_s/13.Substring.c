#pragma warning(disable:4996)
#include <stdio.h>
void get_substring(char *n);
int main()
{
	char string[50];
	printf("Input a string: ");
	fgets(string, sizeof(string), stdin);
	
	get_substring(string);

	getch();
	return 0;
}
void get_substring(char *n)
{
	char local[20];
	int i = 0;
	int position, lenght = 0;
	printf("Input the position to start extraction : ");
	scanf("%d", &position);
	printf("Input the length of substring : ");
	scanf("%d", &lenght);

	while (i < lenght)
	{
		local[i] = n[position-1];
		i++;
		position++;
	}
	local[i] = '\0';
	printf("The substring retrieve from the string is : \"%s\"",local);

}