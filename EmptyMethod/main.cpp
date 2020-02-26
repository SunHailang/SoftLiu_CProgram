
#include <stdio.h>
#include <Windows.h>
#include "Include\SortUtils.h"


int main()
{
	printf("Hello World !\n");


	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	bubble_sort(arr, len);

	system("pause");
	return 0;
}

