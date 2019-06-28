#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

// leetcode by afernandez90
// iterators are never invalidated by modifiers (unless erasing the element itself)
// 使用list来增删，使用unordered_map来查找
class LRUCache {
public:
	LRUCache(int capacity) :_capacity(capacity) {

	}

	int get(int key) {
		// Get the value (will always be positive) of the key if the key exists in the cache, 
		auto it = cache.find(key);
		// otherwise return -1.
		if (it == cache.end()) return -1;
		// 更新Cache使用情况
		touch(it);
		// 返回要查找的值
		return it->second.first;
	}

	void put(int key, int value) {
		auto it = cache.find(key);

		// 如果存在，更新一下Cache使用
		if (it != cache.end()) touch(it);
		// Set or insert the value if the key is not already present
		else {
			// When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
			if (cache.size() == _capacity) {
				// 同时删除cache和used末尾的元素
				cache.erase(used.back());
				used.pop_back();
			}
			// 在used中添加新的元素的key值
			used.push_front(key);
		}
		// 在cache中添加key值对应的value和迭代器的值，刚添加的key值，其对应的迭代器为used.begin()
		cache[key] = { value,used.begin() };
	}
private:
	typedef list<int> LI;
	// 存value和迭代器
	typedef pair<int, LI::iterator> PII;
	// 存key和PII
	typedef unordered_map<int, PII> HIPII;

	// 使用过，则进行更新，删除原有，更新迭代器
	void touch(HIPII::iterator it) {
		// 暂存key值
		int key = it->first;
		// 删除list中对应的元素
		used.erase(it->second.second);
		// 重新往list中存入key
		used.push_front(key);
		// 更新key值对应的迭代器，unorder_map里的key和value未变动，即只对list增删，对map查找
		it->second.second = used.begin();
	}

	HIPII cache;
	LI used;
	int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//int main(int argc, char* argv[]) {
//	LRUCache* cache = new LRUCache(2);
//	cache->put(1, 1);
//	cache->put(2, 2);
//	cout << cache->get(1) << endl;
//	cache->put(3, 3);
//	cout << cache->get(2) << endl;
//	cache->put(4, 4);
//	cout << cache->get(1) << endl;
//	cout << cache->get(3) << endl;
//	cout << cache->get(4) << endl;
//	return 0;
//}