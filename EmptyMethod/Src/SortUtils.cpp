#include <stdio.h>

#pragma region 冒泡排序 默认升序
void bubble_sort(int arr[], int len, bool sortMode = true)
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			bool mode = arr[j] > arr[j + 1];
			if (!sortMode)
			{
				mode = arr[j] < arr[j + 1];
			}
			if (mode)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
#pragma endregion

#pragma region 选择排序

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selection_sort(int arr[], int len)
{
	int i, j;

	for (i = 0; i < len - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < len; j++)     //走访未排序的元素
		{
			if (arr[j] < arr[min])    //找到目前最小值
			{
				min = j;    //记录最小值
			}
		}
		swap(&arr[min], &arr[i]);
	}
}
#pragma endregion

#pragma region 插入排序
void insertion_sort(int arr[], int len)
{
	int i, j, temp;
	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}
#pragma endregion

#pragma region 希尔排序
void shell_sort(int arr[], int len)
{
	int gap, i, j;
	int temp;
	for (gap = len >> 1; gap > 0; gap = gap >> 1)
	{
		for (i = gap; i < len; i++)
		{
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
			{
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = temp;
		}
	}
}
#pragma endregion