#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

// Runtime: 24 ms, faster than 42.63% of C++ online submissions for Top K Frequent Elements.
// Memory Usage : 11.6 MB, less than 22.92 % of C++ online submissions for Top K Frequent Elements.
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> frequency;
		// 或者用priority_queue
		multimap<int,int, greater<int>> index;
		for (int i : nums) {
			++frequency[i];
		}
		for (auto f : frequency) {
			index.insert(make_pair(f.second, f.first));
		}
		vector<int> ret;
		int j = 0;
		for (auto i : index) {
			ret.push_back(i.second);
			++j;
			if (j == k) break;
		}
		return ret;
	}
};

// leetcode by sxycwzwzq
// Runtime: 24 ms, faster than 42.63% of C++ online submissions for Top K Frequent Elements.
// Memory Usage : 11.2 MB, less than 96.67 % of C++ online submissions for Top K Frequent Elements.
class Solution2 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		for (int num : nums) {
			map[num]++;
		}

		vector<int> res;
		// pair<first, second>: first is frequency,  second is number
		priority_queue<pair<int, int>> pq;
		for (auto it = map.begin(); it != map.end(); it++) {
			pq.push(make_pair(it->second, it->first));
			if (pq.size() > (int)map.size() - k) {
				res.push_back(pq.top().second);
				pq.pop();
			}
		}
		return res;
	}
};