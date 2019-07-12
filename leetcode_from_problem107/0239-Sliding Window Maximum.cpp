#include <vector>
#include <set>
using namespace std;

// Runtime: 80 ms, faster than 21.21% of C++ online submissions for Sliding Window Maximum.
// Memory Usage : 18.2 MB, less than 5.20 % of C++ online submissions for Sliding Window Maximum.
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		multiset<int> window;
		int i = 0;
		while (i < k) {
			window.insert(nums[i++]);
		}
		vector<int> ret;
		if (window.empty()) return ret;
		ret.push_back(*window.rbegin());
		for (; i < nums.size(); ++i) {
			// erase ɾ����key��ͬ������Ԫ��
			//window.erase(nums[i - k]);

			// ͨ��������ɾ������֤ÿ��ֻɾ��һ��Ԫ��
			window.erase(window.find(nums[i - k]));
			window.insert(nums[i]);
			ret.push_back(*window.rbegin());
		}
		return ret;
	}
};

// leetcode by anmaithien
// Runtime: 52 ms, faster than 96.61% of C++ online submissions for Sliding Window Maximum.
// Memory Usage : 12.7 MB, less than 96.96 % of C++ online submissions for Sliding Window Maximum.

// ����ָ�룬ʼ��ά��maxIndex����fast����ֵ����maxIndex��ֵ������maxIndex����slow����maxIndexʱ��maxIndexʧЧ
// ���¼���maxIndex
class Solution2 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int length = nums.size();
		vector<int> window;

		if (length == 0) {
			return window;
		}
		int fast = k - 1;
		int maxIndex = 0;
		int slow = 0;

		// ��ʼ��
		for (int i = 0; i <= k - 1; i++) {
			if (nums[i] >= nums[maxIndex]) {
				maxIndex = i;
			}
		}

		while(fast<length) {
			// ����maxIndex
			if (nums[fast] >= nums[maxIndex]) {
				maxIndex = fast;
			}

			window.push_back(nums[maxIndex]);

			// �ƶ�����
			slow++;
			fast++;

			// �ж�maxIndex�Ƿ�ʧЧ
			if (slow > maxIndex) {
				// for loop to find next maxIndex
				maxIndex = slow;
				for (int j = slow; j <= fast; j++) {
					if (nums[j] >= nums[maxIndex]) {
						maxIndex = j;
					}
				}
			}
		}

		return window;
	}
};

//int main(int argc, char* argv) {
//	vector<int> nums = { -7,-8,7,5,7,1,6,0 };
//	vector<int> ret = Solution2().maxSlidingWindow(nums,4);
//	return 0;
//}