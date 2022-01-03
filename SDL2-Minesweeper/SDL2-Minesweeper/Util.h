#pragma once
#include "Tile.h"

class Util {
public:
	static bool checkBitMaskEquality(Tile* tile, TileBitMask bitmask)
	{
		return (((*tile).getBitmaskValue() & bitmask) == bitmask);
	}
};