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

	// 소켓 등록 및 서버 정보 설정
	bool			Initialize();
	// 서버 시작
	void			StartServer();
	// 작업 스레드 생성
	bool			CreateWorkerThread();
	// 작업 스레드
	virtual void	WorkerThread();

	// 수신
	virtual void	Receive(unsigned char pPacket[], stSOCKETINFO* pSocket);
	//송신
	virtual void	SendMsg(unsigned char* sendMsg, stSOCKETINFO* pSocket, int packetSize);
	void			Send(stSOCKETINFO* pSocket);

	stSOCKETINFO*	GetpSocketInfo();

private:
	stSOCKETINFO*	m_pSocketInfo;		// 소켓 정보
	SOCKET			m_listenSocket;		// 서버 리슨 소켓
	HANDLE			m_hIOCP;			// IOCP 객체 핸들
	bool			m_bAccept;			// 요청 동작 플래그
	bool			m_bWorkerThread;	// 작업 스레드 동작 플래그
	//HANDLE*			m_pWorkerHandle;	// 작업 스레드 핸들
	std::mutex		mMutex;
	std::vector<std::thread> mThreadVec;
};