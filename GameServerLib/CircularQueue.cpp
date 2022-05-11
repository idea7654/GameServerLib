#include "CircularQueue.h"

bool CircularQueue::Push(BYTE * pData, int pDataLength, std::string pRemoteAddress, unsigned short pRemotePort, int pProtocol)
{
	mLock.lock();

	DWORD TempTail = (mQueueTail + 1) % MAX_QUEUE_LENGTH;
	if (TempTail == mQueueHead)
		return false;

	mQueue[TempTail].DataLength = pDataLength;
	mQueue[TempTail].RemotePort = pRemotePort;
	mQueue[TempTail].Protocol = pProtocol;

	memset(mQueue[TempTail].Data, 0, sizeof(mQueue[TempTail].Data));
	memcpy(mQueue[TempTail].Data, pData, pDataLength);

	memset(mQueue[TempTail].RemoteAddress, 0, sizeof(mQueue[TempTail].RemoteAddress));
	memcpy(mQueue[TempTail].RemoteAddress, pRemoteAddress.c_str(), sizeof(mQueue[TempTail].RemoteAddress));

	mQueueTail = TempTail;
	mLock.unlock();
	return true;
}

bool CircularQueue::Pop(BYTE * pData, int & pDataLength, std::string &pRemoteAddress, unsigned short & pRemotePort, int & pProtocol)
{
	mLock.lock();

	DWORD TempHead = (mQueueHead + 1) % MAX_QUEUE_LENGTH;
	if (TempHead == mQueueTail)
		return false;

	pDataLength = mQueue[TempHead].DataLength;
	pRemotePort = mQueue[TempHead].RemotePort;
	pProtocol = mQueue[TempHead].Protocol;

	memset(pData, 0, sizeof(pData));
	memcpy(pData, mQueue[TempHead].Data, pDataLength);

	//memset(pRemoteAddress.c_str(), 0, sizeof(pRemoteAddress));
	//memcpy(pRemoteAddress, mQueue[TempHead].RemoteAddress, sizeof(mQueue[TempHead].RemoteAddress));
	pRemoteAddress = mQueue[TempHead].RemoteAddress;

	mQueueHead = TempHead;
	mLock.unlock();
	return true;
}
