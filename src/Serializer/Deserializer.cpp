#include <Serializer/Deserializer.hpp>
#include <algorithm>
#include <cstdint>

/**
 * It takes a vector of unsigned chars and returns a GamePacket
 *
 * @param data The data to deserialize
 *
 * @return A GamePacket object.
 */
GamePacket Deserializer::deserialize(std::vector<unsigned char, std::allocator<unsigned char>>& data)
{
    GamePacket packet;
    packet.x         = data[PacketName::X1] | (data[PacketName::X2] << 8);
    packet.y         = data[PacketName::Y1] | (data[PacketName::Y2] << 8);
    packet.x         = data[PacketName::XPOSITIVE] ? packet.x : -packet.x;
    packet.y         = data[PacketName::YPOSITIVE] ? packet.y : -packet.y;
    packet.idSprite  = data[PacketName::ID_SPRITE];
    packet.width     = data[PacketName::WIDTH];
    packet.height    = data[PacketName::HEIGHT];
    packet.scaleX    = data[PacketName::SCALE_X] / 10;
    packet.scaleY    = data[PacketName::SCALE_Y] / 10;
    packet.offsetX   = data[PacketName::OFFSET_X];
    packet.offsetY   = data[PacketName::OFFSET_Y];
    packet.id        = data[PacketName::ID1] | (data[PacketName::ID2] << 8);
    packet.destroyed = data[PacketName::DESTROYED];

    return packet;
}

/**
 * It returns the first element of the vector.
 *
 * @param data The data to deserialize.
 *
 * @return The first element of the vector.
 */
int Deserializer::deserializeSingleValue(std::vector<unsigned char, std::allocator<unsigned char>>& data)
{
    return data[0];
}
