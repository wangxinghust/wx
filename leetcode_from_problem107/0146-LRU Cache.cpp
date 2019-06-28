#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

// leetcode by afernandez90
// iterators are never invalidated by modifiers (unless erasing the element itself)
// ʹ��list����ɾ��ʹ��unordered_map������
class LRUCache {
public:
	LRUCache(int capacity) :_capacity(capacity) {

	}

	int get(int key) {
		// Get the value (will always be positive) of the key if the key exists in the cache, 
		auto it = cache.find(key);
		// otherwise return -1.
		if (it == cache.end()) return -1;
		// ����Cacheʹ�����
		touch(it);
		// ����Ҫ���ҵ�ֵ
		return it->second.first;
	}

	void put(int key, int value) {
		auto it = cache.find(key);

		// ������ڣ�����һ��Cacheʹ��
		if (it != cache.end()) touch(it);
		// Set or insert the value if the key is not already present
		else {
			// When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
			if (cache.size() == _capacity) {
				// ͬʱɾ��cache��usedĩβ��Ԫ��
				cache.erase(used.back());
				used.pop_back();
			}
			// ��used������µ�Ԫ�ص�keyֵ
			used.push_front(key);
		}
		// ��cache�����keyֵ��Ӧ��value�͵�������ֵ������ӵ�keyֵ�����Ӧ�ĵ�����Ϊused.begin()
		cache[key] = { value,used.begin() };
	}
private:
	typedef list<int> LI;
	// ��value�͵�����
	typedef pair<int, LI::iterator> PII;
	// ��key��PII
	typedef unordered_map<int, PII> HIPII;

	// ʹ�ù�������и��£�ɾ��ԭ�У����µ�����
	void touch(HIPII::iterator it) {
		// �ݴ�keyֵ
		int key = it->first;
		// ɾ��list�ж�Ӧ��Ԫ��
		used.erase(it->second.second);
		// ������list�д���key
		used.push_front(key);
		// ����keyֵ��Ӧ�ĵ�������unorder_map���key��valueδ�䶯����ֻ��list��ɾ����map����
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