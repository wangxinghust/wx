#include <math.h>
class Solution {
public:

	//���ֲ��� �����һ��С�ڵ���������ҵĶ���
	//Runtime: 4 ms, faster than 93.46% of C++ online submissions for Sqrt(x).
	//Memory Usage : 8.4 MB, less than 49.49 % of C++ online submissions for Sqrt(x).
	int mySqrt(int x) {
		//����x�ǷǸ��ģ�Ҳ�����ֶ�����x�Ǹ����жϣ��������ڴ���0,1������������0����
		if (x <= 1) return x;

		int left = 0;
		int right = x;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			//��mid*mid<=x��Ϊmid<=x/mid���������
			if (mid <= x / mid) {
				left = mid + 1;
			}
			else if (mid > x / mid) {
				right = mid - 1;
			}
		}
		return left - 1;
	}
};

int main(int argc, char* argv[]) {
	Solution s;
	int ans = s.mySqrt(0);
	return 0;
}