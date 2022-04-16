#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Tile.h"

using namespace std;
class Util
{
public:

	static bool checkBitMaskEquality(Tile* tile, TileBitMask bitmask)
	{
		return (tile->getBitmaskValue() & bitmask) == bitmask;
	}

	//UTIL_TOOLKIT

	static void Parse(vector<string>& words, string input, string delim)
	{
		stringstream stringStream(input);
		string line;
		while (std::getline(stringStream, line))
		{
			std::size_t prev = 0, pos;
			while ((pos = line.find_first_of(delim, prev)) != std::string::npos)
			{
				if (pos > prev) {
					words.push_back(line.substr(prev, pos - prev));
				}
				prev = pos + 1;
			}
			if (prev < line.length()) {
				words.push_back(line.substr(prev, line.find_last_of('.') - prev));
			}
		}
	}
};