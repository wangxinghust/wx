#include <cstdint>

// http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetParallel

// MIT Hackmem 169
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
// Memory Usage : 8 MB, less than 77.50 % of C++ online submissions for Number of 1 Bits.
class Solution {
public:
	int hammingWeight(uint32_t n) {
		// ‭033333333333 11011011011011011011011011011011‬
		// ‭011111111111 01001001001001001001001001001001‬
		// 4a + 2b + c –(2a + b) – a = a + b + c 以2为底的多项式，求1的位数，即是求系数和
		// 以3bit为1组
		unsigned int tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
		// 030707070707 ‭11000111000111000111000111000111‬
		// 以6bit为1组，即多项式以64为底，对63取余，得系数和，即1的个数
		return ((tmp + (tmp >> 3)) & 030707070707) % 63; // 63 111111
	}
};

//对任何自然数n的N次幂，用n - 1取模得数为1，证明如下：
//若 n ^ (k - 1) % (n - 1) = 1 成立
//则 n ^ k % (n - 1) = ((n - 1) * n ^ (k - 1) + n ^ (k - 1)) % (n - 1) = 0 + n ^ (k - 1) % (n - 1) = 1 也成立
//又有 n ^ (1 - 1) % (n - 1) = 1
//故对任意非负整数N, n ^ N % (n - 1) = 1


// Approach 1: Loop and Flip
// Runtime: 8 ms, faster than 13.68% of C++ online submissions for Number of 1 Bits.
// Memory Usage : 8.1 MB, less than 66.98 % of C++ online submissions for Number of 1 Bits.
class Solution2 {
public:
	int hammingWeight(uint32_t n) {
		int bits = 0;
		unsigned int mask = 1;
		for (int i = 0; i < 32; i++) {
			if ((n & mask) != 0) {
				bits++;
			}
			mask = mask << 1;
		}
		return bits;
	}
};

// Naïve Approach
// Runtime: 4 ms, faster than 79.94% of C++ online submissions for Number of 1 Bits.
// Memory Usage : 8.2 MB, less than 14.38 % of C++ online submissions for Number of 1 Bits.
class Solution4 {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n |= 0)
		{
			count += n & 1;
			n >>= 1;
		}
		return count;
	}
};

// Approach 2: Bit Manipulation Trick
// Runtime: 4 ms, faster than 79.94% of C++ online submissions for Number of 1 Bits.
// Memory Usage : 8.1 MB, less than 69.39 % of C++ online submissions for Number of 1 Bits.
class Solution3 {
public:
	int hammingWeight(uint32_t n) {
		int sum = 0;
		while (n != 0) {
			sum++;
			n &= (n - 1);
		}
		return sum;
	}
};

// Divide-­‐and-­‐conquer Approach
class Solution5 {
public:
	int hammingWeight(uint32_t n) {
		// ‭01010101010101010101010101010101‬ 统计每两位有多少个1
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		// ‭00110011001100110011001100110011‬ 统计每四位有多少个1
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		// ‭00001111000011110000111100001111‬ 统计每八位有多少个1
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		// 00000000‭111111110000000011111111‬ 统计每16位有多少个1
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		// ‭00000000000000001111111111111111‬ 统计这32位有多少个1
		n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
		//// 63
		//return (n & 0x0000003f);
		// 应该是直接返回n即可，无需对0b111111取余，原算法可能是为了避免位运算的异常，只取0b111111，防止结果大于32
		return n;
	}
};

// 静态表
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
// Memory Usage : 8.3 MB, less than 6.21 % of C++ online submissions for Number of 1 Bits.
class Solution6 {
public:
	int hammingWeight(uint32_t n) {
		unsigned int table[16] =
		{
			0, 1, 1, 2,
			1, 2, 2, 3,
			1, 2, 2, 3,
			2, 3, 3, 4
		};

		unsigned int count = 0;
		while (n)
		{
			count += table[n & 0xf];
			n >>= 4;
		}
		return count;
	}
};

int main(int argc, char* argv[]) {
	int bits = Solution5().hammingWeight(11);
	return 0;
}