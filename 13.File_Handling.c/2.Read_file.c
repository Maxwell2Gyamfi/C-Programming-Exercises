#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void read_file(char *n);
int main()
{
	char buffer[50];
	read_file(buffer);
	getch();

	return 0;
}
void read_file(char *n)
{
	int i = 0;
	char buffer[50];
	memset(buffer, 0, sizeof(buffer));
	FILE *file;
	file = fopen("abc.txt", "rb");
	if (file == NULL)
	{
		printf("File does not exit");
		exit(0);
	}
	fread(buffer, sizeof(buffer), 1, file); 
	fclose(file);

	printf("%s", buffer);
}