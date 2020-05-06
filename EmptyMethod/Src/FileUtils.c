#include <stdio.h>


void FileWrite(const char *filePath, const char *fileContent, const char *mode)
{
	FILE *fp = NULL;
	fp = fopen(filePath, mode);
	fputs(fileContent, fp);
	fclose(fp);
}