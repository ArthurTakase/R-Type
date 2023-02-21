#pragma once
#include <cstdint>

#define ESCAPE 120
#define WINDOW_CLOSE 36
#define CONNECT 12

typedef enum PacketName {
    X1        = 0,
    X2        = 1,
    Y1        = 2,
    Y2        = 3,
    XPOSITIVE = 4,
    YPOSITIVE = 5,
    ID_SPRITE = 6,
    WIDTH     = 7,
    HEIGHT    = 8,
    SCALE_X   = 9,
    SCALE_Y   = 10,
    OFFSET_X  = 11,
    OFFSET_Y  = 12,
    ID        = 13,
    DESTROYED = 14,
} PacketName;

/**
 * @brief This struct is used to process the data received from the server.
 */
struct GamePacket {
    int          x;
    int          y;
    std::uint8_t idSprite;
    std::uint8_t width;
    std::uint8_t height;
    float        scaleX;
    float        scaleY;
    std::uint8_t offsetX;
    std::uint8_t offsetY;
    std::uint8_t id;
    std::uint8_t destroyed;
};

typedef enum Input { LeftArrow = 71, RightArrow = 72, UpArrow = 73, DownArrow = 74, Space = 57, Shift = 38 } Input;
