#include <stdio.h>


int main()
{
	int i = 0;

	char name[4][7] = { "#", "######","#####"};

	printf("######\n");
	printf("#\n");
	printf("#\n");
	printf("#####\n");
	printf("#\n");
	printf("#\n");
	printf("#\n");

	for (i = 0; i <= 6; i++)
	{
		if (i == 0)
		{
			printf("%s\n", name[1]);
		}
		else if (i == 3)
		{
			printf("%s\n", name[2]);
		}
		else
		{
			printf("%s\n", name[0]);
		}
	}

	for (i = 0; i <=6; i++)
	{
		if (i == 0)
		{
			printf("######\n");
		}
		else if (i == 3)
		{
			printf("#####\n");
		}
		else
		{
			printf("#\n");
		}
	}

	getchar();
	return 0;
}