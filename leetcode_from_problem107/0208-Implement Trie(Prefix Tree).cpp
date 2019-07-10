#include <string>
#include <unordered_set>
using namespace std;

// Runtime: 156 ms, faster than 8.12% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage : 112.5 MB, less than 5.11 % of C++ online submissions for Implement Trie(Prefix Tree).
class Trie2 {
public:
	unordered_set<string> words;
	unordered_set<string> starts;
	/** Initialize your data structure here. */
	Trie2() {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		words.insert(word);
		for (int i = 1; i <= word.length(); i++) {
			starts.insert(word.substr(0, i));
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		return words.find(word) != words.end();
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return starts.find(prefix) != starts.end();
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Runtime: 88 ms, faster than 47.83% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage : 30.5 MB, less than 93.71 % of C++ online submissions for Implement Trie(Prefix Tree).
class TrieNode {
public:
	char content;   // the character included
	bool isend;     // if the node is the end of a word
	int shared;     // the number of the node shared ,convenient to implement delete(string key), not necessary in this problem
	vector<TrieNode*> children; // the children of the node �����26���ӽڵ㣬��ΪСд��ĸֻ��26��
	// Initialize your data structure here.
	TrieNode() :content(' '), isend(false), shared(0) {}
	TrieNode(char ch) :content(ch), isend(false), shared(0) {}
	// �ڸýڵ��children����ûƥ���ch��û�з���nullptr
	TrieNode* subNode(char ch) {
		if (!children.empty()) {
			for (auto child : children) {
				if (child->content == ch)
					return child;
			}
		}
		return nullptr;
	}
	~TrieNode() {
		for (auto child : children)
			delete child;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s) {
		// �����������ٴβ���
		if (search(s)) return;
		TrieNode* curr = root;
		// ���ַ�ƥ��
		for (auto ch : s) {
			// �ڸýڵ���ӽڵ���������ƶ�curr����Ӧ��λ��
			TrieNode* child = curr->subNode(ch);
			if (child != nullptr) {
				curr = child;
			}
			// �������ӽڵ��������½���㲢���
			else {
				TrieNode* newNode = new TrieNode(ch);
				curr->children.push_back(newNode);
				curr = newNode;
			}
			// shared����
			++curr->shared;
		}
		// ���ַ���ĩβ�ַ���isend����Ϊtrue����ʾ�õ����ַ����Ľ�β
		curr->isend = true;
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		TrieNode* curr = root;
		// ���ַ�ƥ��
		for (auto ch : key) {
			curr = curr->subNode(ch);
			// ����ӽڵ�������û�и��ַ���˵��������
			if (curr == nullptr)
				return false;
		}
		// �жϽ�β�ַ���isend�Ƿ���true
		return curr->isend == true;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	// ��searchһ�£���ͬ���ǣ���β�ַ������ж�isend�Ƿ�Ϊtrue
	bool startsWith(string prefix) {
		TrieNode* curr = root;
		for (auto ch : prefix) {
			curr = curr->subNode(ch);
			if (curr == nullptr)
				return false;
		}
		return true;
	}
	~Trie() {
		// ����root������������ʱ�����Զ������ӽڵ����������
		delete root;
	}
private:
	TrieNode* root;
};

//int main(int argc,char* argv[]){
//	Trie* obj = new Trie();
//	obj->insert("apple");
//	bool param_2 = obj->search("apple");
//	bool param_3 = obj->search("app");
//	bool param_4 = obj->startsWith("app");
//	obj->insert("app");
//	bool param_5 = obj->search("app");
//	return 0;
//}