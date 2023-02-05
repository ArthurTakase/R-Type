#include "Deserializer.hpp"

#include "BitSize.hpp"
#include "IDeserializer.hpp"

EntityInfo Deserializer::Deserialize(std::bitset<ENTITYSIZE> data) const
{
    std::bitset<ENTITYSIZE> bigbit(
        "0000000000000000000000000000000000000000000000000000000000000000000000011111111111111111");
    std::bitset<ENTITYSIZE> smallbit(
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000011111111");

    EntityInfo entityInfo;
    int        index = 0;
    entityInfo.x     = ((data >> (ENTITYSIZE - (index + XSIZE))) & bigbit).to_ulong();
    index += XSIZE;
    entityInfo.y = ((data >> (ENTITYSIZE - (index + YSIZE))) & bigbit).to_ulong();
    index += YSIZE;
    entityInfo.idSprite = ((data >> (ENTITYSIZE - (index + IDSPRITESIZE)) & smallbit)).to_ulong();
    index += IDSPRITESIZE;
    entityInfo.width = ((data >> (ENTITYSIZE - (index + WIDTHSIZE)) & smallbit)).to_ulong();
    index += WIDTHSIZE;
    entityInfo.heigth = ((data >> (ENTITYSIZE - (index + HEIGHTSIZE)) & smallbit)).to_ulong();
    index += HEIGHTSIZE;
    entityInfo.scaleX = ((data >> (ENTITYSIZE - (index + SCALEXSIZE)) & smallbit)).to_ulong();
    index += SCALEXSIZE;
    entityInfo.scaleY = ((data >> (ENTITYSIZE - (index + SCALEYSIZE)) & smallbit)).to_ulong();
    index += SCALEYSIZE;
    entityInfo.offsetX = ((data >> (ENTITYSIZE - (index + OFFSETXSIZE)) & smallbit)).to_ulong();
    index += OFFSETXSIZE;
    entityInfo.offsetY = ((data >> (ENTITYSIZE - (index + OFFSETYSIZE)) & smallbit)).to_ulong();
    index += OFFSETYSIZE;
    entityInfo.id = ((data >> (ENTITYSIZE - (index + IDSIZE)) & smallbit)).to_ulong();

    return entityInfo;
}

int Deserializer::Deserialize(std::bitset<INPUTSIZE> input) const
{
    return input.to_ulong();
}
