#pragma once
#include <stdio.h>
#define SIZE 3
/**
fopen_s(&file,"test.txt","r");
fclose(fp);

�ı��ļ�
------------------------------
r  : ��һ���ļ� <=> rt
w : дһ���ļ�
a  : ׷��һ������

�������ļ�
------------------------------
rb  : ��һ���ļ�
wb : дһ���ļ�
ab  : ׷��һ������

r+
w+
a+


�����Ƚ�
-------------------------------
puts putc putchar fputc fputs printf�ڴ浽�նˡ�����
gets getc getchar fgetc fgets scanf �նˡ����̵��ڴ�

fprintf_s:����putϵ�� fscanf_s:����getϵ�� rewind():�ƶ�λ��ָ�뵽��ʼλ��  fseek():�ƶ�λ��ָ�뵽����λ��
-------------------------------

**/

void print_file_r()
{
	FILE* file;
	fopen_s(&file, "text.txt", "r+");
	if (file == NULL)
	{
		printf("�ļ���ʧ��!\n");
		exit(1);
	}
	else {
		printf("�ļ��򿪳ɹ�!\n");
		char ch = fgetc(file);
		while (ch!=EOF)
		{
			putchar(ch);
			ch = fgetc(file);
		}
	}
	fclose(file);
}

void print_file_w()
{
	FILE* file;
	char array[65];

	scanf("%s", array);

	fopen_s(&file, "text.txt", "a");

	for (int i = 0; i < sizeof(array); i++)
	{
		if (array[i]=='#' || array[i]==NULL)
		{
			break;
		}
		fputc(array[i], file);
	}
	
	fclose(file);
}

void print_file_s_r()
{
	FILE *file;
	fopen_s(&file, "text.txt", "r+");
	if (file!=NULL)
	{
		char arr[65];
		fgets(arr, 65, file);
		printf("%s", arr);
	}
	fclose(file);
}

void print_file_s_w()
{
	FILE *file;
	fopen_s(&file, "text.txt", "w+");
	if (file!=NULL)
	{
		char arr[68];
		//scanf("%s",arr);
		gets_s(arr,68);
		fputs(arr, file);
	}
	fclose(file);
}



struct Student {
	char name[10];
	int sex;
}t_student[SIZE];

void print_br_w_r()
{
	FILE *fp = NULL;

	/*
	for (int j=0; j<SIZE ; j++)
	{
		printf("������ѧ�����������Ա�\n");
		scanf("%s", &t_student[j].name);
		scanf("%d", &t_student[j].sex);
	}
	
	fopen_s(&fp, "textrb", "wb");
	for (int i=0; i<SIZE; i++)
	{
		if (fwrite(&t_student[i],sizeof(struct Student),1,fp) != 1)
		{
			printf("���ݴ洢���˶������ļ���");
		}
	}
	fclose(fp);*/
	
	fopen_s(&fp, "textrb", "rb");
	for (int k=0; k<SIZE; k++)
	{
		fread(&t_student[k], sizeof(struct Student), 1, fp);
		printf("%s,%d \n", t_student[k].name, t_student[k].sex);
	}
	fclose(fp);
}

print_fscanf_s()
{
	//fscanf_s(,);
}