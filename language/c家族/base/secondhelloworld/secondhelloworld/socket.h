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

struct sClient
{
	SOCKET s;
	SOCKADDR_IN sin;
};

/*����������ɫ*/
void setColor(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

/*�ͻ��˽�����Ϣ�ĺ���*/
DWORD WINAPI client_recevice_Thread(LPVOID lp)
{
	SOCKET *s = lp;
	while (true)
	{
		int inRecv;
		char cBuffer[1024];
		inRecv = recv(*s,cBuffer,1024,0);
		if (inRecv > 0)
		{
			cBuffer[inRecv] = '\0';
			setColor(14);
			printf("%s\n", cBuffer);
			setColor(8);
		}
		if (inRecv == SOCKET_ERROR)
		{
			printf("��������Ѿ��Ͽ������������ӣ�");
		}
	}
	return 0;
}

void print_sock()
{
	char cAddress[50];
	int iModel = 0;

	setColor(7);

	printf("*******************************************\n");
	printf("************��ӭ������������ϵͳ***********\n");
	printf("*******************************************\n");

	printf("���������ӵ�ip��ַ:\n");
	scanf("%s", &cAddress, 50);

	printf("����������ǳ�:\n");
	scanf("%s", &cName, 10);

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
		setColor(15);
		printf("�ѳɹ����ӷ�����������quit�������ϵͳ!");
		setColor(7);

		char cBuf[1024];//�û����������
		char cSendBuf[256];//�ǳ�

		memset(cBuf, 0, sizeof(cBuf)); //��ʼ���ַ�����
		memset(cSendBuf, 0, sizeof(cSendBuf)); //��ʼ���ַ�����

		/*
		ƴ����Ϣ����
		*/
		strcpy_s(cBuf,1024 ,"��������");
		strcpy_s(cSendBuf,58 , cName);
		strcat_s(cSendBuf, 10, '˵');
		strcat_s(cSendBuf,1024, cBuf);

		/*
		������Ϣ
		*/
		ret=send(acceptSocket, cSendBuf, sizeof(cSendBuf), 0);
		if (ret == SOCKET_ERROR)
		{
			printf("��Ϣ����ʧ�ܣ������·��ͣ�");
			return 0;
		}
	
		/*
		����������Ϣ���߳�ָ�����
		*/
		LPVOID *lp = (LPVOID*) &acceptSocket;
		HANDLE hThread0;

		//����������Ϣ�̲߳�ִ��
		CreateThread(NULL,0, client_recevice_Thread,lp,0,NULL);

		//���̷߳�������
		while (true)
		{
			memset(cBuf, 0, sizeof(cBuf)); //��ʼ���ַ�����
			scanf_s("%s", cBuf, 1024);

			//�ж��Ƿ���quit
			if (strcmp(cBuf,"quit")==0)
			{
				break;
			}

			memset(cBuf, 0, sizeof(cBuf));
			strcpy_s(cSendBuf,58, cName);
			strcat(cSendBuf, '˵');
			strcat(cSendBuf, cBuf);

			/*
			������Ϣ
			*/
			ret = send(acceptSocket, cSendBuf, sizeof(cSendBuf), 0);
			if (ret == SOCKET_ERROR)
			{
				printf("��Ϣ����ʧ�ܣ������·��ͣ�");
			}
		}

		if (iModel ==1)
		{
			u_long ul = 1;
			struct sClient c[80];
			WSAEVENT eventarray[80];
			int total = 0; //ͳ���׽��ֵĸ���
			c[0].s = socket(AF_INET, SOCK_STREAM, 0);
			ioctlsocket(c[0].s, FIONBIO, &ul);

			//���ip�Ͷ˿�
			SOCKADDR_IN sin;
			sin.sin_addr.S_un.S_addr = INADDR_ANY;
			sin.sin_family = AF_INET;
			sin.sin_port = htons(12266);
			c[0].sin = sin;

			//�󶨵�ַ�Ͷ˿�
			if (bind(c[0].s,(SOCKADDR *)&c[0].sin,sizeof(c[0].sin))==SOCKET_ERROR)
			{
				printf("��ʧ�ܣ������¼�飡");
				return 0;
			}

			//��������ģʽ
			listen(c[0].s,5);
			WSAEVENT event = WSACreatEvent();
			WSAEventSelect(c[0].s,event,FD_ACCEPT | FD_CLOSE);
			eventarray[total] = event; //�׽��ּ�������
			total++;
		}

		closesocket(acceptSocket);
		WSACleanup();
		CloseHandle(hThread0);
	}
}
