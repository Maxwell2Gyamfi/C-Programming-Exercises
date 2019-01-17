#pragma warning(disable:4996)
#include <stdio.h>
void get_name(char *n);
void delete_file(char *n);
int main()
{
	char n[20];
	get_name(n);
	delete_file(n);
	getch();
	return 0;
}
void get_name(char *n)
{
	printf("Input the name of the text_file: ");
	scanf("%s", n);
}
void delete_file(char *n)
{
	int status = 0;

	status = remove(n);
	status == 0 ? printf("File deleted successfully") :
		perror("Error");
}