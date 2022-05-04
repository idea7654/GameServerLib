#pragma once
#include "IOCP.h"
#include <string>

class IOCP_Child : public IOCompletionPort
{
	virtual void Receive(std::string str) override;
	virtual void SendMsg(const char* sendMsg) override;

};