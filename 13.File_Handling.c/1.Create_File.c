#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void get_text(char *n);
void create_file(char *n);
int main()
{
	char text[50];
	get_text(text);
	create_file(text);
	getch();
	return 0;
}
void get_text(char *n)
{
	char buffer[50];
	printf("Input a sentence for file: ");
	fgets(buffer, sizeof(buffer), stdin);
	strcpy(n, buffer);

}
void create_file(char *n)
{
	FILE *file;
	file = fopen("abc.txt", "wb");
	if (file == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	fwrite(n, strlen(n), 1, file);
	fclose(file);

}