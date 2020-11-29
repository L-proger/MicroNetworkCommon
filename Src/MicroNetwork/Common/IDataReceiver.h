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
    static constexpr InterfaceID ID() { return { 0x7d055626, 0xdae1, 0x4cc7, { 0x81, 0xd0, 0xed, 0x81, 0x3d, 0x57, 0xbd, 0x73 } };
; }
    virtual Result packet(MicroNetwork::Common::PacketHeader header, const void* data) = 0;
};

template<class TImplementer>
struct InterfaceRemap<MicroNetwork::Common::IDataReceiver, TImplementer> : public InterfaceRemap<IUnknown, TImplementer> {
public:
    virtual Result packet(MicroNetwork::Common::PacketHeader header, const void* data) { return this->_implementer->packet(header, data); }
};
}
