#pragma once

#include "Packet.h"

namespace MicroNetwork::Common {

	class IDataReceiver {
	public:
		virtual ~IDataReceiver() = default;
		virtual bool packet(PacketHeader header, const void* data) = 0;
	};

}
