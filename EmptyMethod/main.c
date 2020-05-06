
#include <stdio.h>
#include <Windows.h>
#include "Include\SortUtils.h"

#include "rJsonRead.h"

#define MAX_LENGTH  2


struct stu {
	int x;
	int y;
	int z;
};
//int ReadJson(const char *fileName, char **str1)
//{
//	printf("Start Read File.\n");
//
//	FILE *file = NULL;
//	if ((file = fopen(fileName, "r+")) == NULL)
//	{
//		printf("File not exit.\n");
//		return -1;
//	}
//
//	fseek(file, 0, SEEK_END);
//
//	int fileSize = ftell(file);
//	printf("File exist.\n");
//
//	*str1 = (char*)malloc(fileSize);
//
//	//memset(*str, 0, fileSize);
//
//	**str1 = 0;
//	//return 0;
//	rewind(file);
//	char buffer[1024];
//
//	while ((fgets(buffer, 1024, file)) != NULL)
//	{
//		strcat(*str1, buffer);
//	}
//	fclose(file);
//	printf("End Read File.\n");
//	//free(*str1);
//	return 0;
//}
int f(int **q)
{
	int a = 10;
	*q = (int*)malloc(sizeof(int));
	**q = a;
	return 0;
}
int main()
{
	printf("Hello World !\n");

	int *p = NULL;
	f(&p);
	printf("%d\n", *p);

	char *json = "./jsonTest.json";
	char *str = NULL;
	ReadJson(json, &str);

	printf("%s\n", str);

	//int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	//int len = (int) sizeof(arr) / sizeof(*arr);
	//bubble_sort(arr, len);

	system("pause");
	return 0;
}



