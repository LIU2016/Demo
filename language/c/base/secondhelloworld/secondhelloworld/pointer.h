/*

�����Ĵ洢λ�þ��Ǹñ����ĵ�ַ���õ�ַ���ǡ�ָ�롰��������ȡ����ͨ����ָ�롰��ָ�����������ԣ�ָ�����/����ĵ�ַ�ͳ���

*����[ָ�����]���������һ�������ĵ�ַ��ָ����������;�������һ�����������ͣ�ָ�������Ϊ�����ĵ�ַ���ݣ��������ֵ���ݡ�
	**����������ָ�룿����

&����� �� *����� ��*�������ȡֵ��&�������ȡ��ַ�������ǻ������㡣���ȼ�Ϊ��2 �� �ַ����飨�ַ�������ָ����� �� ++ ���㡣

������ָ�룺��������������׵�ַ����ָ�����ָ�����ҵ�����Ԫ�أ�ռ�ڴ��٣��ٶȿ� a[] , *p=&a[0]<=>*p=a , ����Ԫ�ص����ֱ�﷨��a[i]=*(a+i) ��ָ����Կ���������±�
	����ָ�룺����ָ�������ָ������ ������������׵�ַ��a[] ,*p=a�������壺(*p)[n]  (**p)[n]:�������ָ��
	ָ�����飺�������飬��ŵ���ָ�룬���壺*p[n]

�ַ�����ָ�룺�ַ���ָ������ַ������׵�ַ������һ���ַ��ĵ�ַ������ʹ���ַ���ָ�������������ַ��char *str = "learning C language!" ;

����ָ����ָ�뺯����
	����ָ�룺{������ (*������)(���������б�)} ָ������ʵ���ϻ���ָ�룬ռ4���ֽڡ�
	ָ�뺯����ʵ�����Ǻ���������ĳ�����͵�ָ�룬{������ *������(���������б�)} �� ��Լ�ڴ� ��
	int(*(*pFunc)(int,int))(int);

voidָ�룺û�����ͣ�����ָ���κ����ͣ���ֵ���������͵�ʱ��Ҫת��. type *p = (type *)voidp . voidָ�벻�ܲ������㣬����ǿ��ת�������ܸ�����

ָ�������ã���ַ��ֵ��const

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
	// scanf_s("%s",&input_username,20);
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

//���庯��ָ��
void(*pointFunc)(int a, int b);

// ����ָ�뱻���õķ���
void point_pointer(int a,int b)
{
	printf("point_pointer ��������,�������:%d ,%d��\n ",a,b);
}

void point_pointer7(void)
{
	//ָ�򱻵��õĺ���
	pointFunc = point_pointer;
	//���ú��� - �൱�� point_pointer();
	(*pointFunc)(1,2);
}

//ָ�뺯��  -
int * sum(int n)
{
	int static sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += i;
	}
	int *p = &sum;
	return p;
}

void point_pointer8(void)
{
	//int *total = NULL;
	//total = sum(10);
	printf("rslt:%d", *sum(10));
}

void point_pointer9(void)
{
	char array[] = { 'a', 'b', 'd', 'e', 'g' };
	char(*p)[] = array;
	//����ָ��
	printf("����ָ��[3]:%c",(*p)[2]);
	printf("����ָ��[3]�ĵ�ַ:%p \n", &((*p)[2]));

	//ָ������
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = '\0';
	char *pp[4];
	pp[0] = &a;
	pp[1] = &b;
	pp[2] = &c;
	printf("ָ������[2]:%c \n", *pp[2]);

	//void��
	int aa = 55;
	void *k = NULL;
	k = &aa;
	int *ppp = (int *)k;
	printf("%d \n", *ppp);

	//
	int array9[50];
	int length = sizeof(array9) / sizeof(int);
	printf("%d \n", length);

}

void point_pointer10(void)
{
	//const ���峣���� ��ֻ�ж���Ȩ��
	const int x = 10;
	const int *p = &x;
	int *pp = &x;
	*pp = 100;
	printf("%d", x);

}
