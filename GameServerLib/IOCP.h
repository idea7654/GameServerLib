#pragma once

#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <thread>
#include <vector>
#include <mutex>
#include <iostream>


#define MAX_BUFFER	1024
#define SERVER_PORT 9190

enum OVERLAPPED_TYPE
{
	ACCEPT = 1,
	RECV,
	SEND,
	CLOSE
};

struct stSOCKETINFO
{
	WSAOVERLAPPED	overlapeed;
	WSABUF			dataBuf;
	SOCKET			socket;
	char			messageBuffer[MAX_BUFFER];
	int				recvBytes;
	int				sendBytes;
};

class IOCompletionPort
{
public:
	IOCompletionPort();
	~IOCompletionPort();

	// ���� ��� �� ���� ���� ����
	bool			Initialize();
	// ���� ����
	void			StartServer();
	// �۾� ������ ����
	bool			CreateWorkerThread();
	// �۾� ������
	virtual void	WorkerThread();

	// ����
	virtual void	Receive(unsigned char pPacket[], stSOCKETINFO* pSocket);
	//�۽�
	virtual void	SendMsg(unsigned char* sendMsg, stSOCKETINFO* pSocket, int packetSize);
	void			Send(stSOCKETINFO* pSocket);

	stSOCKETINFO*	GetpSocketInfo();

private:
	stSOCKETINFO*	m_pSocketInfo;		// ���� ����
	SOCKET			m_listenSocket;		// ���� ���� ����
	HANDLE			m_hIOCP;			// IOCP ��ü �ڵ�
	bool			m_bAccept;			// ��û ���� �÷���
	bool			m_bWorkerThread;	// �۾� ������ ���� �÷���
	//HANDLE*			m_pWorkerHandle;	// �۾� ������ �ڵ�
	std::mutex		mMutex;
	std::vector<std::thread> mThreadVec;
};