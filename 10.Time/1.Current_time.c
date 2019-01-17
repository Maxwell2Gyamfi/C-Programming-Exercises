#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
int main()
{
	time_t k;
	struct tm *local;
	time(&k);

	local = localtime(&k);
	printf("%s", asctime(local));

	getch();
	return 0;
}