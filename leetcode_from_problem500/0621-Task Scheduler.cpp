#include <vector>
#include <algorithm>
using namespace std;

// Approach #1 Using Sorting [Accepted]
// Runtime: 84 ms, faster than 38.15% of C++ online submissions for Task Scheduler.
// Memory Usage : 9.6 MB, less than 95.74 % of C++ online submissions for Task Scheduler.
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> map(26);
		for (char c : tasks) {
			++map[c - 'A'];
		}
		sort(map.begin(),map.end());
		int time = 0;
		while (map[25] > 0) {
			int i = 0;
			while (i <= n) {
				if (map[25] == 0) {
					break;
				}
				if (i < 26 && map[25 - i]>0) {
					--map[25 - i];
				}
				++time;
				++i;
			}
			sort(map.begin(), map.end());
		}
		return time;
	}
};

// Approach #2 Using Priority-Queue [Accepted]