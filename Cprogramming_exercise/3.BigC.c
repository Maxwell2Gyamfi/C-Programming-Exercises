#include <stdio.h>

int main()
{
	int i = 0;
	char bigc[12][12] = { "######", "#", "##" };

	for (i = 0; i <= 8; i++)
	{
		if ((i == 0) || (i==8))
		{
			printf("%9.6s\n",bigc[0]);
		}
		else if ((i == 1) || (i==7))
		{
			printf("%3.2s%8.2s\n", bigc[2], bigc[2]);
		}
		else
		{
			printf("%s\n", bigc[1]);
		}
	
	}

	for (i = 0; i <= 8; i++)
	{
		if ((i == 0) || (i == 8))
		{
			printf("   ######\n");

		}
		else if ((i == 1) || (i == 7))
		{
			printf(" ##      ##\n");

		}
		else
		{
			printf("#\n");
		}

	}
	printf("   ######\n");
	printf(" ##      ##\n");
	printf("#\n");
	printf("#\n");
	printf("#\n");
	printf("#\n");
	printf("#\n");
	printf(" ##      ##\n");
	printf("   ######\n");

	getchar();
	return 0;
}