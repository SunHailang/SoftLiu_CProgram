

#include "Main.h"
#include <stdio.h>

int main()
{
	printf("Hello World.\n");

	char str1[20], str2[30];

	printf("Enter name: ");
	scanf_s("%s", &str1, 20);

	printf("Enter your website name: ");
	scanf_s("%s", &str2, 20);

	printf("Entered Name: %s\n", &str1);
	printf("Entered Website:%s\n", &str2);

	char c[2];
	printf("Enter a letter Close:");
	scanf_s("%s", &c, 2);

	return (0);
}
