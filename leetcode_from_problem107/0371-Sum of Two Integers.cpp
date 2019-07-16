#include <stdio.h>
// 基于位运算，剑指offer
class Solution {
public:
	int getSum(int a, int b) {
		int sum, carry;
		do {
			sum = a ^ b;
			// 计算进位，也就是找都是1的地方，然后整体左移1位即可
			// The left shiftand right shift operators should not be used for negative numbers.
			// The result of is undefined behaviour if any of the operands is a negative number
			carry = (a & b) << 1;
			a = sum;
			b = carry;
		} while (carry != 0);
		return sum;
	}
};

// leetcode by luchu
class Solution2 {
public:
	int getSum(int a, int b) {
		return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
	}
};

void Test(int num1, int num2, int expected)
{
	int result = Solution().getSum(num1, num2);
	if (result == expected)
		printf("%d + %d is %d. Passed\n", num1, num2, result);
	else
		printf("%d + %d is %d. FAILED\n", num1, num2, result);
}

//int main(int argc, char* argv[])
//{
//	Test(1, 2, 3);
//	Test(111, 899, 1010);
//
//	Test(-1, 2, 1);
//	Test(1, -2, -1);
//
//	Test(3, 0, 3);
//	Test(0, -4, -4);
//
//	Test(-2, -8, -10);
//
//	Test(-1, 1, 0);
//	return 0;
//}