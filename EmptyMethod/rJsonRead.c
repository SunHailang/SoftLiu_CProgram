#include "rJsonRead.h"

#include <stdio.h>

void ReadJson(const char *fileName , char **str1)
{
	printf("Start Read File.\n");

	FILE *file = NULL;
	if ((file = fopen(fileName, "r+")) == NULL)
	{
		printf("File not exit.\n");
		return;
	}

	fseek(file, 0, SEEK_END);

	int fileSize = ftell(file);
	printf("File exist.\n");

	*str1 = (char*)malloc(fileSize);

	//memset(str, 0, fileSize);

	**str1 = 0;

	rewind(file);
	char buffer[1024];

	while ((fgets(buffer, 1024, file)) != NULL)
	{
		strcat(*str1, buffer);
	}
	fclose(file);
	printf("End Read File.\n");
}


