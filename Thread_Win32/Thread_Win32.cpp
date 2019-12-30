// Thread_Win32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>

#include "../ThirdPartyLib/include/pthread.h"


#pragma comment(lib, "pthreadVC2.lib")

void* thread(void* val);

int main()
{

	pthread_t tid;
	int value = 20;
	pthread_create(&tid, 0, thread, &value);
	printf("thread after\n");

	system("pause");

    return 0;
}

void* thread(void* val)
{
	int value = *((int*)val);
	printf("value: %d\n", value);
	while (value-- > 0)
	{
		printf(" %d\n", value);
	}
	printf("thread end\n");
	return NULL;
}

