#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int get_string(char *n);
void reverse_string(char *n, int i, int lenght);
int main()
{
	char *k;
	int lenght = 0;
	char n[30];

	lenght = get_string(n);
	k = &n[0];
	reverse_string(k, 0,lenght-1);

	printf("%s", n);
	getch();
	return 0;
}
int get_string(char *n)
{
	int lenght = 0;
	printf("Input any string: ");
	scanf("%s", n);
	lenght = strlen(n);
	return lenght;

}
void reverse_string(char *n, int i, int lenght)
{
	char temp;
    if (i <=lenght)
	{
		temp = n[i];
		n[i] = n[lenght];
		n[lenght] = temp;
		reverse_string(n, i + 1, lenght - 1);
	}
	return;
}