#include <vector>
using namespace std;

class Solution {
public:
	//Runtime: 0 ms
	//Memory Usage: 8.7 MB
	vector<int> plusOne(vector<int>& digits) {
		int i = digits.size() - 1;
		bool carry = true;
		while (carry && i >= 0) {
			if (digits[i] == 9) {
				digits[i] = 0;
				i--;
			}
			else {
				digits[i]++;
				carry = false;
			}
		}
		if (carry) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}


	//leetcode by zezedi ��û���Ż�������ʱ�������ˣ�֮���Կռ�ռ�øߣ�����Ϊ��Ŀ����ֵ���͸ı���
	//Runtime: 4 ms, faster than 90.98% of C++ online submissions for Plus One.
	//Memory Usage : 8.7 MB, less than 17.95 % of C++ online submissions for Plus One.
	vector<int> plusOne1(vector<int>& digits)
	{
		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				//����ֱ������������
				return digits;
			}
		}
		//ѭ����������ʾ���λҲ��9����ĩβ�Ӹ�0�����λ��1����
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
};