#pragma once
#include <flatbuffers/flatbuffers.h>
class PacketManager
{
protected:
	flatbuffers::FlatBufferBuilder builder;

public:
	auto ReadBuffer();
};

