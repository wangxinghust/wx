#include <string>
using namespace std;
class Solution {
public:
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Binary.
	//Memory Usage : 8.7 MB, less than 48.47 % of C++ online submissions for Add Binary.
	string addBinary(string a, string b) {
		if (a.length() >= b.length()) {
			int carry = 0;
			int i = a.length() - 1;
			int j = b.length() - 1;
			while (i >= 0) {
				if (j >= 0) {
					switch (a[i] - '0' + b[j] - '0' + carry) {
					case 0:
						a[i] = '0';
						carry = 0;
						break;
					case 1:
						a[i] = '1';
						carry = 0;
						break;
					case 2:
						a[i] = '0';
						carry = 1;
						break;
					case 3:
						a[i] = '1';
						carry = 1;
					}
				}
				else {
					switch (a[i] - '0' + carry) {
					case 0:
						a[i] = '0';
						carry = 0;
						break;
					case 1:
						a[i] = '1';
						carry = 0;
						break;
					case 2:
						a[i] = '0';
						carry = 1;
					}
				}
				--i;
				--j;
			}
			if (carry) {
				a = '1' + a;
			}
			return a;
		}
		else {
			int carry = 0;
			int i = b.length() - 1;
			int j = a.length() - 1;
			while (i >= 0) {
				if (j >= 0) {
					switch (b[i] - '0' + a[j] - '0' + carry) {
					case 0:
						b[i] = '0';
						carry = 0;
						break;
					case 1:
						b[i] = '1';
						carry = 0;
						break;
					case 2:
						b[i] = '0';
						carry = 1;
						break;
					case 3:
						b[i] = '1';
						carry = 1;
					}
				}
				else {
					switch (b[i] - '0' + carry) {
					case 0:
						b[i] = '0';
						carry = 0;
						break;
					case 1:
						b[i] = '1';
						carry = 0;
						break;
					case 2:
						b[i] = '0';
						carry = 1;
					}
				}
				--i;
				--j;
			}
			if (carry) {
				b = '1' + b;
			}
			return b;
		}
	}
};