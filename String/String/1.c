/*
 * 编写一个函数，把一个char组成的字符串循环右移n位。例如：原来是”abcdefghi”，如果n = 2，移位后应该是”hiabcdefg”。
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

char * shiftString(char arr[], int n, int i)
{
	char buffer[MAX_LEN];
	strcpy(buffer, arr+(n-i));
	arr[n-i-1] = '\0';
	strcpy(buffer+i, arr);
	return buffer;
}

int main()
{
	char str[] = "hewlkjfosiafewfewf";
	char *s = shiftString(str, sizeof(str)-1, 5);
	printf("%s\n", s);
	return 0;
}

