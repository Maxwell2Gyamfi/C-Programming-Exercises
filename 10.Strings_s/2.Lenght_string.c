#pragma warning(disable:4996)
#include <stdio.h>
void get_string(char *name);
int get_count(char *name);
int main()
{
	int count = 0;
	char name[20];
	get_string(name);
	count = get_count(name);
	printf("Length of the string is : %d", count);
	getch();
	return 0;
}
void get_string(char *name)
{

	printf("Input a string: ");
	scanf("%s",name);

}
int get_count(char *name)
{
	int count = 0;
	int i = 0;
	while (name[i] != '\0')
	{
		count++;
		i++;
	}
	return count;
}