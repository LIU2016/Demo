/*
 sockaddr sockaddr_in
*/
/*
	sin_family : ��ַ��
	USHORT sin_port;
	IN_ADDR sin_addr;
	CHAR sin_zero[8];
	#include <Winsock2.h> �� ������ö��嵽second.c����
	*/

#pragma comment(lib,  "ws2_32.lib")

char cName[10];
void print_sock()
{
	char cAddress[50];
	int iModel = 0;
	printf("*******************************************\n");
	printf("************��ӭ������������ϵͳ***********\n");
	printf("*******************************************\n");

	printf("���������ӵ�ip��ַ:\n");
	scanf("%c", &cAddress, 50);

	printf("����������ǳ�:\n");
	scanf("%c", &cName, 10);

	//��ʼ���׽���
	WSADATA wsadata;
	int ret;
	/*
	Ϊ����Ӧ�ó����е����κ�һ��Winsock API������
	���ȵ�һ��������Ǳ���ͨ��WSAStartup������ɶ�Winsock����ĳ�ʼ���������Ҫ����WSAStartup������
	ʹ��Socket�ĳ�����ʹ��Socket֮ǰ�������WSAStartup������
	�ú����ĵ�һ������ָ����������ʹ�õ�Socket�汾�����и�λ�ֽ�ָ�����汾����λ�ֽ�ָ�����汾��
	����ϵͳ���õڶ����������������Socket�İ汾��Ϣ��
	��һ��Ӧ�ó������WSAStartup����ʱ������ϵͳ���������Socket�汾��������Ӧ��Socket�⣬
	Ȼ����ҵ���Socket�⵽��Ӧ�ó����С��Ժ�Ӧ�ó���Ϳ��Ե����������Socket���е�����Socket�����ˡ�
	*/
	if ((ret = WSAStartup(MAKEWORD(2, 2), &wsadata)) != 0)
	{
		printf("��ʼ��ʧ��!");
		return 0;
	}

	// 1,�����׽���
	SOCKET acceptSocket;
	acceptSocket = socket(AF_INET, SOCK_STREAM, 0);

	if (acceptSocket == INVALID_SOCKET) {
		
		printf("�����׽���ʧ��!");
		return 0;
	}

	// 2,����IP�Ͷ˿�
	SOCKADDR_IN server;
	server.sin_family = AF_INET;
	server.sin_port = htons(12266);
	server.sin_addr.s_addr = inet_addr(acceptSocket);

	// 3,����
	if (connect(acceptSocket, (SOCKADDR *)&server, sizeof(server)) == INVALID_SOCKET)
	{
		printf("����ʧ�ܣ�������ת���ɷ�����!");
		iModel = 1;
	}

	//�ͻ���
	if (iModel == 0)
	{
		printf("�ѳɹ����ӷ�����������quit�������ϵͳ!");
	}

	//������
	if (iModel == 1)
	{

	}

}
