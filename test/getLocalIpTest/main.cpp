/*
 * UdpBroadMain.c
 * UDP�㲥����
*/

#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <winsock.h>
#include <CONIO.H>

#pragma comment(lib, "Ws2_32.lib")

#ifdef SERVER

int main( int argc, char *argv[] )
{
    WSADATA             wsaData;
    SOCKET              s;
    struct sockaddr_in  sin, sto;
    char				pBuf[1024];
	bool				fBroadcase = true;
	int					ncount = 0;

	// ���WinSock�汾�����ܵ���1.1
    if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)
    {
        printf("\r\nUnable to initialize WinSock for host info");
        exit(0);
    }

	// �����ͻ����׽���
    s = socket( AF_INET, SOCK_DGRAM, 0 );		// UDP
    if( s < 0 )
    {
        printf("failed socket (%d)\n",WSAGetLastError());
        goto leave;
    }
	// �����׽���Ϊ�㲥��ʽ
	setsockopt( s, SOL_SOCKET, SO_BROADCAST, (char*)&fBroadcase, sizeof(bool) );


    sin.sin_family      = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);	// ����IP��ַ
    sin.sin_port        = htons(0);				// �������˿�

	// ���׽��֣����󶨣�ϵͳ���Զ�Ϊ�׽���ָ������IP��ַ���������˿ں�
    if ( bind( s, (struct sockaddr*)&sin, sizeof(sin) ) != 0 )	
    {
        printf("failed bind socket (%d)\n",WSAGetLastError());
        goto leave;
    }	

	sto.sin_family      = AF_INET;
    sto.sin_addr.s_addr = htonl(INADDR_BROADCAST);	// ָ���㲥��ַ255.255.255.255
	//sto.sin_addr.s_addr = inet_addr("192.168.1.255");	// ������192.168.0.xxx�ڵĹ㲥
    sto.sin_port        = htons(7001);					// ���͵��˿�								

	while( !_kbhit() )		// ����Ƿ��м������룬�����������ִ�У������������ѭ��
	{
		sprintf( pBuf, "Message %d", ncount++);

		sendto( s, pBuf, lstrlen(pBuf), 0, (struct sockaddr*)&sto, sizeof(sockaddr_in) );					// ��������

		printf("Send To %s:%d : %s\n", inet_ntoa(sto.sin_addr), ntohs(sto.sin_port), pBuf );

		Sleep(1000);		// �ȴ�1s�����ͷ����ٶ�
	}

leave:
    if( s >= 0 )
        closesocket( s );

    WSACleanup();

	return 0;
}

#else

int main( int argc, char *argv[] )
{
    WSADATA             wsaData;
    SOCKET              s;
    struct sockaddr_in  sin, sfrom;
    char				pBuf[1024];
	bool				fBroadcase = true;
	int					nSize = 0, nbSize;

	// ���WinSock�汾�����ܵ���1.1
    if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)
    {
        printf("\r\nUnable to initialize WinSock for host info");
        exit(0);
    }

	// �����ͻ����׽���
    s = socket( AF_INET, SOCK_DGRAM, 0 );		// UDP
    if( s < 0 )
    {
        printf("failed socket (%d)\n",WSAGetLastError());
        goto leave;
    }

    sin.sin_family      = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);	
   // sin.sin_addr.s_addr = inet_addr("192.168.157.1");
    sin.sin_port        = htons(1234);				

    if ( bind( s, (struct sockaddr*)&sin, sizeof(sin) ) != 0 )	// ���׽���
    {
        printf("failed bind socket (%d)\n",WSAGetLastError());
        goto leave;
    }	

	while( !_kbhit() )		// ����Ƿ��м������룬�����������ִ�У������������ѭ��
	{
		nSize = sizeof(sockaddr_in);
		nbSize = recvfrom( s, pBuf, sizeof(pBuf), 0, (struct sockaddr*)&sfrom, &nSize );
		if ( nbSize == SOCKET_ERROR )					// ��������
		{
			printf("Receive Error\n");
			break;
		}

		pBuf[nbSize] = '\0';
		printf("recv from %s:%d : %s\n", inet_ntoa( sfrom.sin_addr ), ntohs(sfrom.sin_port), pBuf);
	}

leave:
    if( s >= 0 )
        closesocket( s );

    WSACleanup();

	return 0;
}

#endif