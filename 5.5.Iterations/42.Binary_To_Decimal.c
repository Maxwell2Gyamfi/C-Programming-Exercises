#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int range = 0;
	char buffer[15];
	int i = 0;
	long int number = 0;
	int lenght = 0;
	int j = 0;
	int sum = 0;

	scanf("%d", &number);
	sprintf(buffer, "%ld", number);

	lenght = strlen(buffer);
	range = pow(2.0, (double)lenght);

	for (i = 1; i <= range; i = i * 2)
	{
		if (buffer[j] == '1')
		{
			sum += i;
		}
		j++;
	}
	printf("%d", sum);

	return 0;
}