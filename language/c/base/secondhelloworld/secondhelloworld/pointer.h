/*

�����Ĵ洢λ�þ��Ǹñ����ĵ�ַ���õ�ַ���ǡ�ָ�롰��������ȡ����ͨ����ָ�롰

*����[ָ�����]���������һ�������ĵ�ַ��ָ����������;�������һ�����������ͣ�ָ�������Ϊ�����ĵ�ַ���ݣ��������ֵ���ݡ�

&����� �� *����� ��*�������ȡֵ��&�������ȡ��ַ�������ǻ������㡣���ȼ�Ϊ��2

������ָ�룺��������������׵�ַ����ָ�����ָ�����ҵ�����Ԫ�أ�ռ�ڴ��٣��ٶȿ� a[] , *p=&a[0]<=>*p=a , ����Ԫ�ص����ֱ�﷨��a[i]=*(a+i)

*/
#include <stdio.h>

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
	rintf("ָ�� --------- array[1]=%d \n", pa+1);
	printf("*(pa +1)=%d \n", *(pa + 1));
}
