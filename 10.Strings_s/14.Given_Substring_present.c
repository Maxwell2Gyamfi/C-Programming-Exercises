#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void search(char *n, char *searching);
int count_white_spaces(char *n);
int main()
{
	char searching[50];
	char n[50];
	printf("Input the string : ");
	fgets(n, sizeof(n), stdin);
	printf("Input the substring to be search : ");
	fgets(searching, sizeof(searching), stdin);
	search(n, searching);
	getch();
	return 0;
}
void search(char *n, char *searching)
{
	int s = 0;
	int flag = 0;
	char temp[50];
	int i,j = 0;
	int lenght = strlen(searching);
	searching[lenght - 1] = '\0';
	int count = count_white_spaces(n);

	for (i = 0;i <=count;i++)
	{
		if (i == 4)
		{
			while (n[s] != '\n')
			{
				temp[j] = n[s];
				j++;
				s++;
			}
		}
		else
		{
			while (n[s] != ' ')
			{
				temp[j] = n[s];
				j++;
				s++;
			}
		}
		s++;
		temp[j] = '\0';
		if (strcmp(temp, searching) == 0)
		{
			flag = 1;
			break;
		}
		j = 0;
	}
	if (flag == 1)printf("The substring exists in the string.");
	else printf("The substring does not exist in the string.");

}
int count_white_spaces(char *n)
{
	int count = 0;
	int i = 0;
	while (n[i] != '\n')
	{
		if (n[i] == ' ')count++;
		i++;
	}
	return count;

}