#pragma once
#ifndef RJSONREAD_H
#define RJSONREAD_H



typedef struct rJson
{
	char *key;
	int type;
	char *valueString;
	int valueInt;
	float valueFloat;
}rJson;


void ReadJson(const char *fileName, char **str1);

//char* ReadJson(char *fileName)
//{
//	printf("Start Read File.\n");
//
//	FILE *file = NULL;
//	if ((file = fopen(fileName, "r+")) == NULL)
//	{
//		printf("File not exit.\n");
//		return NULL;
//	}
//	fseek(file, 0, SEEK_END);
//
//	int fileSize = ftell(file);
//
//	char *str = (char*)malloc(fileSize);
//	str[0] = 0;
//
//	rewind(file);
//	char buffer[1024];
//
//	while ((fgets(buffer, 1024, file)) != NULL)
//	{
//		strcat(str, buffer);
//	}
//	fclose(file);
//	printf("End Read File.\n");
//	return str;
//}


#endif // !RJSONREAD_H
