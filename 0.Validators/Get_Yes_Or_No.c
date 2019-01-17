#pragma warning(disable:4996)
#include <stdio.h>



char yes_or_no()
{
	int success = 0;
	char input;
	char buffer[5];

	char ch;

	while ((ch = getchar()) != '\n' && ch != EOF);



	do
	{
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%c", &input);

		input = toupper(input);

		if ((input == 'Y') || (input == 'N'))
		{
			success = 1;
			return input;
		}
		else
		{
			fputs("Incorrect input, try again: ", stderr);
		}

	} while (success == 0);

}