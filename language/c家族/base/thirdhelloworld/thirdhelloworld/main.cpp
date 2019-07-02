#include <cstdio>
#include <iostream>
#include "first.h"

/*
	1,using namespace
	2,class object
	3,public private
	4,��������Ԫ
	5,thisָ��

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
private:
	char name[10];
};

MyThis::MyThis(char *name)
{
	name = name;
}

void MyThis::print()
{
	//cout << "thisָ��:" << this.name << endl;
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

	//getchar();
	return 0;
}
