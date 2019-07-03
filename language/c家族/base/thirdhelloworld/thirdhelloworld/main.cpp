#include <cstdio>
#include <iostream>
#include "first.h"
#include <string>

/*
	1,using namespace
	2,class object
	3,public private
	4,��������Ԫ
	5,thisָ��
	6,��������������ִ��Ч�ʣ���ʡ����ʱ�䣬���ڴ棬�ռ任ʱ��ķ�ʽ��inline��
	7,static����ľ�̬��Ա����
	8,ָ�����ָ��
	9,��̬�ڴ漼�����ڴ���䣩 ��ջ + �ѣ� 
		ջ���ں����ڲ����������б�������ռ��ջ���ڴ档
		�ѣ�(��ȷ���ڴ���Ҫ����)�ڳ�����δʹ�õ��ڴ棬��������ʱ��̬�����ڴ档new ������ڴ棬delete�ͷ�new���ڴ�
    10��string
*/

using namespace std;

class Math
{
public:
	int compare(int a, int b);
	Math(int *p);
	void print();
private:
	int *k;
};

int Math::compare(int a, int b)
{
	if (a>b)
	{
		return 1;
	}
	else if (a==b)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

Math::Math(int *p)
{
	k = p;
}

void Math::print()
{
	cout << *k << endl;
}

class Number
{
public :
	Number(int i);
	~Number();/*��������*/
	Number(Number&copyObj); /*�������캯��*/
	void print();
    void print(Number number);
	friend void print(Number number); /*��Ԫ�����Ƿǳ�Ա����������ʹ�ö����˽�б���*/
	friend class MyNumber; /*��Ԫ�� ���Է������������˽�б���*/
private:
	int *u;
};

Number::Number(int i)
{
	u = new int;
	*u = i;
}

Number::Number(Number&copy)
{
	u = new int;
	*u = *copy.u;
}

Number::~Number()
{
	u = NULL;
	cout << "�����������ͷ��ڴ�!" << endl;
}

void Number::print()
{
	cout << *u << endl;
}

void Number::print(Number number)
{
	cout << *number.u << endl;
}

void print(Number number)
{
	cout << *number.u << endl;
}

class MyNumber {
public:
	void print(Number nu);
};

void MyNumber::print(Number nu)
{
	cout << "��Ԫ��:" << *nu.u << endl;
}

class MyThis {
public:
	MyThis(char *name);
	void print();
	void say();
	static int count;
	static void useStatic() {
		cout << "��̬" << count << endl;
	};
private:
	char name[10];
};

int MyThis::count = 0;

MyThis::MyThis(char *name)
{
	name = name;
	count++;
}

void MyThis::say()
{
	cout << "this ���õĺ���" << endl;
}

void MyThis::print()
{
	cout << "thisָ����õĳ�Ա����:" << this->name << endl;
	this->say();
}

inline int compare(int a,int b)
{
	return (a > b ? a : b) ;
}

int main(void)
{
	int a = 9;
	Math math(&a);
	int rslt = math.compare(23,68);
	cout << rslt << endl;
	math.print();

	cout << "=====" << endl;
	Number number(10);
	Number numberCopy(number);
	print(numberCopy);

	cout << "=====" << endl;
	MyNumber ber;
	ber.print(numberCopy);

	cout << "=====" << endl;
	char name[6] = "adfsa";
	MyThis mythis(name);
	MyThis mythis1(name);
	mythis.print();

	cout << compare(10, 20) << endl;

	MyThis::useStatic();

	cout << "ָ�����ָ��" << endl;
	MyThis *clazz;
	clazz = &mythis1;
	cout << "" << clazz->count << endl;
		
	cout << "��̬�ڴ漼��" << endl;
	int *girl = NULL;
	girl = new int(32);
	delete girl;

	int *girls = new int[10];
	delete[] girls;

	int **boys = new int*[10];
	for (int i = 0; i < 10; i++)
	{
		boys[i] = new int[10];
	}
	for (int i = 0; i < 10; i++)
	{
		delete[] boys[i];
	}

	cout << "string" << endl;
	string s2;
	string s1 = "12312313";
	string s3(3, 'C');
	s2 = s1;
	cout << s3 << s3.length() << s2 << endl;

	//getchar();
	return 0;
}
