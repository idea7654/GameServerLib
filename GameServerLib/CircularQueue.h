#pragma once

#include <iostream>
#include <mutex>
#include <Windows.h>
#include <string>

const int MAX_BUFFER_LENGTH = 1024;
const int MAX_QUEUE_LENGTH = 256;
using BYTE = unsigned char;

struct QUEUE_DATA
{
	BYTE			Data[MAX_BUFFER_LENGTH];
	DWORD			DataLength;
	char			RemoteAddress[32];
	unsigned short	RemotePort;
	DWORD			Protocol;
};

class CircularQueue
{
public:
	bool Push(BYTE *pData, int pDataLength, std::string pRemoteAddress, unsigned short pRemotePort, int pProtocol);
	bool Pop(BYTE *pData, int &pDataLength, std::string &pRemoteAddress, unsigned short &pRemotePort, int &pProtocol);

private:
	std::mutex	mLock;
	QUEUE_DATA	mQueue[MAX_QUEUE_LENGTH];
	DWORD		mQueueHead;
	DWORD		mQueueTail;
};

