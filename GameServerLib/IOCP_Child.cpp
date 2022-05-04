#include "stdafx.h"
#include "IOCP_Child.h"

void IOCP_Child::Receive(std::string str)
{
	printf_s("receive client msg\n");
}

void IOCP_Child::SendMsg(const char* sendMsg)
{
	// ���� -> Ŭ���̾�Ʈ, �޽����� �۽��� �� ó���Լ�

	// ���Ͽ� ���� ������ ��� �����͸� ����
	stSOCKETINFO* pSocketInfo;
	pSocketInfo = GetpSocketInfo();

	// Ŭ���̾�Ʈ�� �޼��� �۽�
	int nSendLen = send(pSocketInfo->socket, sendMsg, strlen(sendMsg), 0);

	// ���� ó��
	if (nSendLen == -1)
	{
		printf_s("Error : %d\n", WSAGetLastError());
	}

	printf_s("Message sended : bytes[%d], message : [%s]\n", nSendLen, sendMsg);
}
