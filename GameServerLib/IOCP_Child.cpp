#include "stdafx.h"
#include "IOCP_Child.h"

void IOCP_Child::Receive(std::string str)
{
	printf_s("receive client msg\n");
}

void IOCP_Child::SendMsg(const char* sendMsg)
{
	// 서버 -> 클라이언트, 메시지를 송신할 때 처리함수

	// 소켓에 대한 정보를 담는 포인터를 저장
	stSOCKETINFO* pSocketInfo;
	pSocketInfo = GetpSocketInfo();

	// 클라이언트로 메세지 송신
	int nSendLen = send(pSocketInfo->socket, sendMsg, strlen(sendMsg), 0);

	// 에러 처리
	if (nSendLen == -1)
	{
		printf_s("Error : %d\n", WSAGetLastError());
	}

	printf_s("Message sended : bytes[%d], message : [%s]\n", nSendLen, sendMsg);
}
