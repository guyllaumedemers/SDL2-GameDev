#pragma once

enum class TileBitMask {
	None = 0,
	Empty = 1,
	Flag = 2,
	Bomb = 4,
	Covered = 8,
	Uncovered = 16,
	Numbered = 32
};

inline TileBitMask operator|(const TileBitMask& lhs, const TileBitMask& rhs) {
	return (TileBitMask)((int)lhs | (int)rhs);
}

inline TileBitMask operator&(const TileBitMask& lhs, const TileBitMask& rhs) {
	return (TileBitMask)((int)lhs & (int)rhs);
}

inline TileBitMask operator~(TileBitMask rhs) {
	return (TileBitMask)(~(int)rhs);
}

inline TileBitMask& operator&=(TileBitMask& lhs, const TileBitMask& rhs) {
	return (TileBitMask&)((int&)lhs &= (int)rhs);
}

inline TileBitMask& operator|=(TileBitMask& lhs, const TileBitMask& rhs) {
	return (TileBitMask&)((int&)lhs |= (int)rhs);
}
