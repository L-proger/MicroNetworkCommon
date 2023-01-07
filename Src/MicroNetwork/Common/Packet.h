#pragma once

#include <cstdint>
#include <LFramework/BitField.h>
#include <MicroNetwork.Common.h>
#include <array>
#include <cstring>

namespace MicroNetwork::Common {

struct PacketId {
    static constexpr std::uint8_t Bind = 0xff;
    static constexpr std::uint8_t Unbind = 0xfe;
    static constexpr std::uint8_t TaskStart = 0xfd;
    static constexpr std::uint8_t TaskStop = 0xfc;
    static constexpr std::uint8_t TaskDescription = 0xfb;
};

inline std::size_t packetFullSize(const PacketHeader& header) {
    return sizeof(PacketHeader) + header.size;
}

/*
struct PacketHeader {
    std::uint8_t id;
    std::uint8_t size;

    std::size_t fullSize() const {
    	return sizeof(PacketHeader) + size;
    }
};
*/
struct MaxPacket {
    PacketHeader header;
    std::array<std::uint8_t, 0xff> payload;

    template<typename T>
    bool setData(const T& data) {
        if constexpr (sizeof(T) > 0xff) {
            return false;
        } else {
            header.size = sizeof(data);
            memcpy(payload.data(), &data, sizeof(data));
            return true;
        }
    }

    template<typename T>
    bool getData(T& data) {
        if (sizeof(T) > header.size) {
            return false;
        } else {
            memcpy(&data, payload.data(), sizeof(data));
            return true;
        }
    }
};

}
