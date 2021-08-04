#include <cstdint>
#include <string>

// leetcode by tworuler
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Bits.
// Memory Usage : 8.1 MB, less than 36.46 % of C++ online submissions for Reverse Bits.
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		n = (n >> 16) | (n << 16);
		// 0xff00ff00 ‭11111111000000001111111100000000‬
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		// ‭0xf0f0f0f0‬ ‭11110000111100001111000011110000‬
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		// 0xcccccccc ‭11001100110011001100110011001100‬
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		// ‭0xaaaaaaaa 10101010101010101010101010101010‬
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
};