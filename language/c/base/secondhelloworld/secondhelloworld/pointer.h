/*

�����Ĵ洢λ�þ��Ǹñ����ĵ�ַ���õ�ַ���ǡ�ָ�롰��������ȡ����ͨ����ָ�롰

*����[ָ�����]���������һ�������ĵ�ַ��ָ����������;�������һ�����������ͣ�ָ�������Ϊ�����ĵ�ַ���ݣ��������ֵ���ݡ�

&����� �� *����� ��*�������ȡֵ��&�������ȡ��ַ�������ǻ������㡣���ȼ�Ϊ��2 �� �ַ����飨�ַ�������ָ����� �� ++ ���㡣

������ָ�룺��������������׵�ַ����ָ�����ָ�����ҵ�����Ԫ�أ�ռ�ڴ��٣��ٶȿ� a[] , *p=&a[0]<=>*p=a , ����Ԫ�ص����ֱ�﷨��a[i]=*(a+i) 

�ַ�����ָ�룺�ַ���ָ������ַ������׵�ַ������һ���ַ��ĵ�ַ������ʹ���ַ���ָ�������������ַ��char *str = "learning C language!" ;

*/
#include <stdio.h>
#include <string.h>

void print_pointer()
{
	printf("-------ָ��---------------\n");
	int x = 500;
	int *y = NULL;
	y = &x;
	printf("x��ֵ�ǣ�%d \n", x);
	printf("x�ĵ�ַ�ǣ�%d \n", &x);
	printf("y��ֵ�ǣ�%d \n", y);
	printf("y�Ľ�����*������ֵ�ǣ�%d \n", *y);
	printf("y�ĵ�ַ�ǣ�%d \n", &y);
	//  printf("y�Ľ���&*������ֵ�ǣ�%d \n", &*y);
	//  printf("y�Ľ���*y++������ֵ�ǣ�%d \n", ++y);
	//  printf("y�Ľ���*y++������ֵ�ǣ�%d \n", *y++);
	//  printf("x��ֵ�ǣ�%d \n", x);
	printf("y�Ľ���(*y)++������ֵ�ǣ�%d \n", ++(*y));
}

void print_pointer1()
{
	int x = 980;

	int *px = &x;
	// ������x�ĵ�ַ�ڵ�ֵ ��*px��ʱ��ֵ�ˡ�
    *px = 489;
	//px = 498;
	printf("%d\n",x);
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap1(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("a=%d,b=%d \n", a, b);
}

void print_pointer2()
{

	printf("---------------");
	int a =90, b =80;
	printf("------1---------");
	// if (a > b) swap(&a,&b);
	if (a > b) swap1(a, b);

	printf("a=%d,b=%d \n", a, b);
}

void print_pointer3()
{
	int array[] = { 23, 22, 33, 56, 67, 11, 21 };
	int *pa = NULL;
	pa = &array[0];

	// --------���鷽��
	printf("���鷽�� --------- array[1]=%d \n", array[1]);
	printf("*(array+1)=%d \n", *(array + 1));

	//---------------ָ��
	printf("ָ�� --------- array[1]=%d \n", pa + 1);
	printf("*(pa +1)=%d \n", *(pa + 1));
}

void copy(char *originalarr, char *copyarr)
{
	/*
	int i=0;
	for (; *(originalarr + i) != '\0'; i++)
	{
	*(copyarr + i) = *(originalarr + i);
	}
	*(copyarr + i) = '\0';*/

	for (; *originalarr != '\0'; originalarr++, copyarr++)
		*copyarr = *originalarr;
	*copyarr = '\0';
}

void print_pointer5()
{
	char array[] = "learning C language ! \n" ;
	printf("�ַ������ӡ���:%s" , array+8);

	char *str = "learning C language! \n";
	printf("�ַ���ָ��:%s", str+8);

	char *tmp = NULL;
	tmp = str;

	tmp = tmp + 3;
	while (*tmp)
	{
		putchar(*tmp);
		tmp++;
	}

	char copyarray[50];
	copy(array,copyarray);
	printf("���ƺ��ֵ:%s", copyarray);
}

void point_pointer6()
{
	char *username = "admin";
	char *password = "123456";

	char input_username[64];
	char input_password[64];

	printf("�������û���:\n");
	gets(input_username);
	printf("����������:\n");
	gets(input_password);

	if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0)
	{
		printf("�û�����������֤�ɹ���");
	}
	else
	{
		printf("�û�����������֤ʧ�ܣ�");
	}

}