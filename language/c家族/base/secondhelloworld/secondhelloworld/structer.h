/*

�ṹ��Ƕ�ף�

�ṹ�����飺

������(Ҳ�й�����)�� ��ṹ������
	�ṹ��ĳ�Առ���ڴ治ͬ������Ӱ�죬
	������������г�Առ��ͬһ���ڴ棬�޸�һ��Ӱ�����������г�Ա����������ڴ������Ա��ռ���ڴ棬ʹ���ڴ渲�Ǽ�����ͬһʱ��ֻ�ܱ���һ����Ա��ֵ�����³�Ա��ֵ�ͻḲ�Ǿ͵ĳ�Ա��
union ��������
{

}

ö�٣�
enum DAY
{
	
}

�ֽڶ������pragma pack(5) ����5 �����������ڴ��ܹ��洢����������Ͳ���ÿ��������ȥ�����ڴ����´�0���룬�ͻ���������ַ��ͺ���롣Ĭ�������������Ϊ��׼��������
	��Ҫ�ֽڶ���ĸ���ԭ������CPU�������ݵ�Ч������
	���飺�������������Ͷ��룬��һ���������Ķ������ˡ�
	���ϣ�����󳤶ȵ��������Ͷ��롣
	�ṹ�壺ÿ���������Ͷ�Ҫ�����Ͷ��롣
	�����������ͣ�ֻҪ��ַ�������ĳ��ȵ�������
	����Ʋ�ͬCPU��ͨ��Э�飨Ƕ��ʽ���������߱�дӲ�������ļĴ����Ľṹʱ��Ҫ���룬��ʹ��������Ȼ�����ҲҪ���룬���ⲻͬ�±����������Ĵ��벻һ��

typedef�����������е��������� ; typedef int MY_INT


*/
#pragma pack(4)
#include <stdio.h>

struct sBirthday
{
	int year;
	int month;
	int day;

	char sex1;
	char sex2;
};

struct personInfo
{
	char name[10];
	char sex[4];
	/*c++ ���ü�struct*/
	// struct sBirthday birthday;
	// �ṹ��Ƕ��
	struct ssBirthday
	{
		int year;
		int month;
		int day;
	} birthday;
	char addr[200];
} sperson = { "lqd01", "boy1", { 1996, 12, 4 }, "�����껨�������·" };

void print_structer()
{
	// struct personInfo personInfo = { "lqd", "boy", { 1986, 12, 4 }, "�����껨�������·" };
	//birthday.year = 1986;
	//birthday.month = 12;
	//birthday.day = 4;
	//struct personInfo person;
	//person.birthday = birthday;
	// struct personInfo *person = &sperson;// &personInfo;
	struct sBirthday bday;
	bday.year = 1988;
	//person->name 
	printf("year:%d \n", bday.year);
	//printf("name=%s,birthday year:%d \n", personInfo.name, personInfo.birthday.year);
}

void print_structer1()
{
	struct personInfo personInfo[2] = { { "lqd", "boy", { 1986, 12, 4 }, "�����껨�������·" }, { "lqd01", "bo01", { 1999, 12, 4 }, "�����껨�������·" } };
	struct personInfo *person = &personInfo;
	printf("name=%s,birthday year:%d \n", (person+1)->name, (person+1)->birthday.year);
	printf("name=%s,birthday year:%d \n", personInfo[0].name, personInfo->birthday.year);
}

//typedef
typedef int MY_INT;
typedef union dataType
{
	MY_INT i;
	char ch;
	double dou;
} dt;

void print_union()
{
	dt dtype = { 'a' };
	printf("union:%d \n",dtype.i);
	printf("union:%d \n", sizeof(dtype));
}

enum STATUS_TYPE
{
	RUNNING='A',//�Զ���������ֵ STOPΪ��C��
	BLOCKING,
	STOP
};

enum FLAG{ true, false } end, match;

void print_enum()
{
	enum STATUS_TYPE status_type;
	status_type = RUNNING;
	printf("union:%c \n", status_type);
	printf("flag:%d", end);
}

void print_duiqi()
{
	struct personInfo person;
	printf("ռ�õ��ֽ� :%d \n", sizeof(person));
	printf("%p %p", &person.name , &person.sex);
}