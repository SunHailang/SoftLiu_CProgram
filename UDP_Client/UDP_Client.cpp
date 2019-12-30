// UDP_Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib") 

typedef struct IOM_t
{
	int x;
}IOM_t;

typedef struct IOME_t
{
	char a;
}IOM_et;

IOM_t t;
IOM_et et;


int main()
{
	

	WORD socketVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	
	if (WSAStartup(socketVersion, &wsaData) != 0)
	{

		printf("Init Windows Socket Failed! Error: %d\n", GetLastError());
		return -1;
	}
	SOCKET sclient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	memset(sin.sin_zero, 0X00, 8); // 函数通常为新申请的内存做初始化工作

	int len = sizeof(sin);

	ebp_header_t *ebp_h;
	printf("%d",sizeof(ebp_header_t));
	ebp_h = (ebp_header_t *)malloc(sizeof(ebp_header_t));

	ebp_h->start_marker = 16979;
	ebp_h->block_size[0] = 0x00;
	ebp_h->block_size[1] = 0x0c;
	ebp_h->source_des = 0;
	ebp_h->group_num = 1;
	ebp_h->service_avail = true;
	ebp_h->ass_health = true;
	for (size_t i = 0; i < sizeof(ebp_h->lowest_seq); i++)
	{
		ebp_h->lowest_seq[i] = 0x00;
	}

	printf("ebp head size: %d\n", sizeof(ebp_header_t));

	while (true)
	{
		char * sendData = "come from Client Data package.\n";
		char str[20];
		printf("input data:");
		scanf("%s", str);
		sendData = str;
		char msg[12];
		msg[0] = 0x42;
		msg[1] = 0x53;
		msg[2] = 0x00;
		msg[3] = 0x0c;
		msg[4] = 0x00;
		msg[5] = 0x00;
		msg[6] = 0x01;
		msg[7] = 0x01;
		msg[8] = 0x00;
		msg[9] = 0x00;
		msg[10] = 0x00;
		msg[11] = 0x00;

		printf("send data: %X  -> length: %d\n", msg, sizeof(msg));

		int sendLen = sendto(sclient, sendData, strlen(sendData), 0, (sockaddr *)&sin, len);
		printf("send len: %d\n", sendLen);

		char recvData[255];
		int ret = recvfrom(sclient, recvData, 255, 0, (sockaddr *)&sin, &len);
		if (ret > 0)
		{
			recvData[ret] = 0x00;
			printf(recvData);
			printf("\n");
		}
	}
	

	closesocket(sclient);
	WSACleanup();

	return 0;
}

