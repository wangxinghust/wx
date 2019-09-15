#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// ����˼·�����ź����αȽϣ�����������ʱ�临�Ӷ�Ҫ��

// ���ڻ������� �ԷǸ��������� ʱ�临�Ӷ� O(n)
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		int maxVal = *max_element(nums.begin(), nums.end());

		int exp = 1; // 1,10,100,1000...
		const int radix = 10; // base 10 system

		vector<int> aux(nums.size());

		// LSD Radix Sort
		while (maxVal / exp > 0) { // go through all digits from LSD to MSD
			vector<int> count(radix, 0);
			for (int i = 0; i < nums.size(); i++) // Counting sort
				count[(nums[i] / exp) % radix]++;

			//for (int i = 1; i < count.size(); i++) // you could also use partial_sum()
			//	count[i] += count[i - 1];
			partial_sum(count.begin(), count.end(), count.begin());

			for (int i = nums.size() - 1; i >= 0; i--)
				aux[--count[(nums[i] / exp) % radix]] = nums[i];

			/*for (int i = 0; i < nums.size(); i++)
				nums[i] = aux[i];*/
			nums = aux;

			exp *= radix;
		}

		int maxGap = 0;

		for (int i = 0; i < nums.size() - 1; i++)
			maxGap = max(nums[i + 1] - nums[i], maxGap);

		return maxGap;
	}
};

// ���ڸ볲���� �ռ�ռ�ø��� ����˵Ͱ���򣬵�����Ͱ������ֱ��ȡͰ�����ݵ����ֵ����Сֵ

class Solution2 {
	class Bucket {
	public:
		bool used = false;
		int minval = numeric_limits<int>::max(); // same as INT_MAX
		int maxval = numeric_limits<int>::min(); // same as INT_MIN
	};
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		int mini = *min_element(nums.begin(), nums.end()),
			maxi = *max_element(nums.begin(), nums.end());
		int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1)); // bucket size or capacity
		int bucketNum = (maxi - mini) / bucketSize + 1; // number of buckets
		vector<Bucket> buckets(bucketNum);

		for (auto&& num : nums) {
			int bucketIdx = (num - mini) / bucketSize; // locating correct bucket
			buckets[bucketIdx].used = true;
			buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval); // �������ӵ���Сֵ
			buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval); // �������ӵ����ֵ
		}
		// ͨ��pre����ʽ�����Ǽ���������������ܿ�����
		int prevBucketMax = mini, maxGap = 0;
		for (auto&& bucket : buckets) {
			if (!bucket.used)
				continue;

			maxGap = max(maxGap, bucket.minval - prevBucketMax);
			prevBucketMax = bucket.maxval;
		}

		return maxGap;
	}
};

//int main() {
//	vector<int> nums = { 3,6,9,1 };
//	int maxGap = Solution().maximumGap(nums);
//	return 0;
//}