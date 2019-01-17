#pragma warning(disable:4996)
#include <stdio.h>
void get_file_name(char *n);
void read_file(char *n);
int main()
{
	char k[60];
	get_file_name(k);
	read_file(k);

	getch();
	return 0;
}
void get_file_name(char *n)
{
	printf("Input the name of the file to be opened: ");
	scanf("%s", n);
}
void read_file(char *n)
{
	char k = 0;
	int word = 0;
	int characters = 0;
	FILE *file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	printf("The content of the file %s are : ");
	printf("\n");
	while (!feof(file))
	{
		k = fgetc(file);
		printf("%c", k);
		k == '\n' || k == ' ' ? word++ : characters++;
	}
	fclose(file);
	printf("\nThe number of words int the file %s are : %d", n, word);
	printf("\nThe number of characters int the file %s are : %d",n, characters-1);

}