#pragma warning(disable:4996)

#include <stdio.h>

int get_decimal();
void get_hex(int n);

int main()
{
	int n = 0;
	n = get_decimal();
	get_hex(n);
	getch();

	return 0;
}
int get_decimal()
{
	int n = 0;
	printf("Input any decimal: ");
	scanf("%d", &n);
	return n;
}
void get_hex(int n)
{
	int i = 0;
	char hex[20];
	int k = 0;
	int count = 0;
	char q='\0';

	for (; n > 0;)
	{

		k = n % 16;
		n = n / 16;

		switch (k)
		{
		case 10:hex[count] = 'A';break;
		case 11:hex[count] = 'B';break;
		case 12:hex[count] = 'C';break;
		case 13:hex[count] = 'D';break;
		case 14:hex[count] = 'E';break;
		case 15:hex[count] = 'F';break;
		default:q = k + '0';hex[count] = q; break;
		}
		count++;
	}
	printf("The equivalent Hexadecimal Number : " );

	for (i = count-1; i >= 0; i--)
	{
		printf("%c", hex[i]);
	}

}