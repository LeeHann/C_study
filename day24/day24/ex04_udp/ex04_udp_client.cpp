#include <iostream>

#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma warning(disable : 4996)
#pragma comment(lib, "ws2_32.lib")

typedef struct calculator
{
	unsigned char d1;
	unsigned char d2;
	unsigned short d3;
	unsigned short d4;
}_data;

typedef struct response
{
    unsigned char d1;
    short d2;
}_res;
int main()
{
    sockaddr_in si_other;
    SOCKET hSocket;
    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("start up error \n");
        return 1;
    }

    hSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (hSocket == SOCKET_ERROR)
    {
        printf("socket create error \n");
        return 1;
    }
    printf("socket create ok\n");

    memset((char*)&si_other, 0, sizeof(si_other));
    InetPton(AF_INET, L"127.0.0.1", &si_other.sin_addr.s_addr);
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(8284);

    printf("send data \n");

    _data message;
    message.d1 = 0x01;
    message.d2 = 0x01;
    message.d3 = 10;
    message.d4 = 20;

    sendto(hSocket, (const char*)&message, sizeof(message), 0, (sockaddr*)&si_other, sizeof(si_other));

    _res response;
    int recv_len;
    int packet_size = sizeof(si_other);
    recv_len = recvfrom(hSocket, (char*)&response, sizeof(_res), 0, (sockaddr*)&si_other, &packet_size);

    char _szIP[256];
    inet_ntop(AF_INET, &si_other.sin_addr, _szIP, sizeof(_szIP));

    printf("from : %s : %d\n", _szIP, ntohs(si_other.sin_port));
    printf("%d,%d\n", response.d1, response.d2);

    printf("close socket \n");
    closesocket(hSocket);
    WSACleanup();
	return 0;
}