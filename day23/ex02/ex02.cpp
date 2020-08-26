#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct Mystruct
{
	char name[32];
	unsigned short x;
	unsigned short y;
	unsigned short w;
	unsigned short h;
}S_SHEET;

int get_data_size(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
	int _size = ftell(fp);
	int _count = _size / sizeof(S_SHEET);

	fseek(fp, 0, SEEK_SET);

	return _count;
}

void trim_space(char* str)
{
	for (int i = 31; i > 0; i--)
	{
		if (str[i] != 20)
		{
			str[i + 1] = 0x00;
			break;
		}
	}
}

int main()
{
	FILE* fp = fopen("../sheet2.bin", "rb");
	int data_size = get_data_size(fp);

	printf("data count : %d\n", data_size);

	void* ptrBuf;
	ptrBuf = malloc(data_size * sizeof(S_SHEET));
	fread(ptrBuf, sizeof(S_SHEET), data_size, fp);

	fclose(fp);

	for (int i = 0; i < data_size; i++)
	{
		S_SHEET* pSheet = ((S_SHEET*)ptrBuf+i);
		//pSheet->name[31] = 0x00;
		trim_space(pSheet->name);
		printf("%4d,%4d,%4d,%4d,%s\n", pSheet->x, pSheet->y, pSheet->w, pSheet->h, pSheet->name);
	}

	return 0;
}