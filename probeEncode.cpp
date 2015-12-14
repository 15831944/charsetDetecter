// probeEncode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>
#include <cstdlib>
#include<iostream>
#include "uchardet.h"
#include <stdio.h>
using namespace::std;

#define NUMBER_OF_SAMPLES   (2048)
int main(int argc, char *argv[]){
	FILE* file;
	char buf[NUMBER_OF_SAMPLES];
	int len;
	uchardet_t ud;
	for (int i = 0; i < argc; i++){
		cout << argv[i] << endl;
	}

	/* �򿪱�����ı��ļ�������ȡһ�������������ַ� */
	file = fopen(argv[1], "rt");
	len = fread(buf, sizeof(char), NUMBER_OF_SAMPLES, file);
	fclose(file);

	/* ͨ�������ַ������ı����� */
	ud = uchardet_new();
	if (uchardet_handle_data(ud, buf, len) != 0)	/* ��������ַ���������ô�п��ܵ��·���ʧ�� */
	{
		printf("��������ʧ�ܣ�\n");
		return -1;
	}
	uchardet_data_end(ud);
	printf(uchardet_get_charset(ud));	/* ��ȡ����ӡ�ı����� */
	uchardet_delete(ud);

	return 0;
}

