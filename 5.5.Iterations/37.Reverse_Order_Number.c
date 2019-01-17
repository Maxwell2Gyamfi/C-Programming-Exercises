#pragma warning (disable:4996)
#include <string.h>
#include <stdio.h>
int get_number();
int get_reverse(int n);
char reverse_string(char *n);
int main()
{
	int n = 0;
	n = get_number();
	get_reverse(n);

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Input the number: ");
	scanf("%d", &n);

	return n;
}
int get_reverse(int n)
{
	int number = 0;
	char buffer[15];
	char local_varaiable[15];


	sprintf(buffer, "%d", n);
	strcpy(local_varaiable, buffer);
	reverse_string(local_varaiable);
    
	number = atoi(local_varaiable);

	printf("The reverse of the number is %d", number);
}
char reverse_string(char *n)
{
	int i = 0;
	char temp;
	int lenght = strlen(n);

	char buffer[10];
	strcpy(buffer, n);

	for (i = 0; i < lenght; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[lenght-1];
		buffer[lenght-1] = temp;

		lenght--;
		if (lenght - i == 0)
		{
			break;
		}
	}
	strcpy(n, buffer);
}