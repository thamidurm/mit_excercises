#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <chrono>
#include <cstdio>
#include <ctime>
#include <thread>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>

#pragma comment(lib, "Ws2_32.lib")

constexpr auto DEFAULT_PORT = "27015";
constexpr auto DEFAULT_BUFLEN = 512;

// Server waits for a connection from a client
// Once received, it checks the payload and if it is "Give_Time" returns the time
// otherwise, returns "Unexpected Request"

int main()
{
	WSADATA wsaData;

	int iResult;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSA Startup failed: %d\n", iResult);
		return 1;
	}

	struct addrinfo* result = nullptr, * ptr = nullptr, hints;

	ZeroMemory(&hints, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo(nullptr, DEFAULT_PORT, &hints, &result);
	if (iResult)
	{
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	SOCKET ListenSocket = INVALID_SOCKET;

	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	if (ListenSocket == INVALID_SOCKET)
	{
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);


	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	SOCKET ClientSocket = INVALID_SOCKET;
	while (true) {

		ClientSocket = accept(ListenSocket, nullptr, nullptr);
		std::thread thread([ClientSocket]()
			{
				if (ClientSocket == INVALID_SOCKET)
				{
					printf("accept failed: %d\n", WSAGetLastError());
					WSACleanup();
				}

				char recvbuf[DEFAULT_BUFLEN];
				int iSendResult;
				int recvbuflen = DEFAULT_BUFLEN;
				int iResult;
				do
				{
					iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
					if (iResult > 0)
					{
						char response[DEFAULT_BUFLEN];
						if (strcmp(recvbuf, "GIVE_TIME"))
						{
							auto cur = std::chrono::system_clock::now();
							std::time_t time = std::chrono::system_clock::to_time_t(cur);
							strcpy(response, std::ctime(&time));
						}
						else
						{
							strcpy(response, "Unexpected request");
						}
						iSendResult = send(ClientSocket, response, (int)strlen(response) + 1, 0);

						if (iSendResult == SOCKET_ERROR)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(ClientSocket);
						}
					}
					else if (iResult == 0)
					{
						printf("Connection closing..\n");
					}
					else
					{
						printf("recv failed: %d\n", WSAGetLastError());
						closesocket(ClientSocket);
						
					}
				} while (iResult > 0);

				iResult = shutdown(ClientSocket, SD_SEND);
				if (iResult == SOCKET_ERROR)
				{
					printf("shutdown failed: %d\n", WSAGetLastError());
					closesocket(ClientSocket);
				}

				closesocket(ClientSocket);
			});
		thread.detach();
	}

	WSACleanup();

	
	return 0;
}