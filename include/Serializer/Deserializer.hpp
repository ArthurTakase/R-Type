#pragma once

/**
 * @brief Object used to deserialize objects for network
 */

#include <NetworkLib/ISocket.hpp>
#include <Serializer/BitSize.hpp>
#include <bitset>
#include <memory>

class Deserializer
{
  public:
    Deserializer() noexcept                          = delete;
    Deserializer(const Deserializer& other) noexcept = delete;
    Deserializer(Deserializer&& other) noexcept      = delete;
    ~Deserializer() noexcept                         = delete;

    Deserializer& operator=(const Deserializer& rhs) noexcept = delete;
    Deserializer& operator=(Deserializer&& rhs) noexcept      = delete;

    static GamePacket deserialize(std::vector<unsigned char, std::allocator<unsigned char>>& data);
    static int        deserializeSingleValue(std::vector<unsigned char, std::allocator<unsigned char>>& data);

  protected:
  private:
};
