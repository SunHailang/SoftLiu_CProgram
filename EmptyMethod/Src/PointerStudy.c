﻿//#include "../Include/PointerStudy.h"

#include <stdio.h>

/*
	指针的值是指针本身存储的数值，这个值将被编译器当作一个地址，而不是一个一般的数值。
	在32 位程序里，所有类型的指针的值都是一个32 位整数，因为32 位程序里内存地址全都是32 位长。

	指针所指向的内存区就是从指针的值所代表的那个内存地址开始，长度为sizeof(指针所指向的类型)的一片内存区。
	我们说一个指针的值是XX，就相当于说该指针指向了以XX 为首地址的一片内存区域；
	我们说一个指针指向了某块内存区域，就相当于说该指针的值是这块内存区域的首地址。
*/


int PointerStudy_main()
{
	char arr[20] = "the_example";
	int *ptr = (int*)arr;
	printf("%c\n", *ptr);//输出: 't'
	printf("0x%p\n", ptr);
	printf("0x%p\n", &ptr);
	ptr++;
	//指针ptr被加了1，编译器是这样处理的：它把指针ptr 的值加上了sizeof(int)，在32位程序中，是被加上了4。
	//由于地址是用字节做单位的，故ptr 所指向的地址由原来的数组arr的地址向高地址方向增加了4个字节。
	printf("%c\n", *ptr);//输出: arr[4] - 'e'

	/*
	只有当两个指针都指向同一个数组中的元素时，才允许从一个指针减去另一个指针。
	两个指针相减的结果的类型是 ptrdiff_t，它是一种有符号整数类型。
	减法运算的值是两个指针在内存中的距离（以数组元素的长度为单位，而不是以字节为单位），因为减法运算的结果将除以数组元素类型的长度。
	*/
	int a[10] = { 256,2,13,4,5,16,7,10,19,12 };
	int sub;
	int *p1 = &a[0];
	int *p2 = &a[5];
	printf("p1= %p\n", p1);
	printf("p2= %p\n", p2);
	sub = p2 - p1;//减法运算的值是两个指针在内存中的距离,减法运算的结果将除以数组元素类型的长度。
	printf("%d\n", sub);// 输出结果为 5

	int *px = (int*)a;
	printf("px = %d\n", *(px + 2));

	char ch[20] = { '0','1','2','3','4','5','6','7','8','9','x','y' };
	char *py = (char*)ch;
	py++;
	printf("py = %c\n", *py);
	return 0;
}