#pragma once

#include "Packet.h"

#include <LFramework/COM/ComObject.h>

namespace MicroNetwork::Common {
    class IDataReceiver;
}

namespace LFramework {
template<>
struct InterfaceAbi<MicroNetwork::Common::IDataReceiver> : public InterfaceAbi<IUnknown> {
    using Base = InterfaceAbi<IUnknown>;
    static constexpr InterfaceID ID() { return 1; }
    virtual Result packet(MicroNetwork::Common::PacketHeader header, const void* data) = 0;
};

template<class TImplementer>
struct InterfaceRemap<MicroNetwork::Common::IDataReceiver, TImplementer> : public InterfaceRemap<IUnknown, TImplementer> {
public:
    virtual Result packet(MicroNetwork::Common::PacketHeader header, const void* data) { return this->_implementer->packet(header, data); }
};
}
