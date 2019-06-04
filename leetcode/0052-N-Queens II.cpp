#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	//��0051���Ľ���ʱ��Ϳռ临�Ӷ��Խϸߣ�leetcode���в���Ӳ���뷽ʽ�����ģ�Ҳ��������쳲���������һ����ֱ�Ӹ��������飬��Ӧ��ѯ���
	int totalNQueens(int n) {
		vector<string> element(n, string(n, '.'));
		int methods = 0;
		backtracking(n, methods, element, 0);
		return methods;
	}
	void backtracking(int n, int& methods, vector<string> element, int tier) {
		if (tier == n) {
			methods++;
			return;
		}

		vector<string> tmp(element.begin(), element.end());

		for (int i = 0; i < n; ++i) {
			if (tmp[tier][i] == '*') {
				continue;
			}
			else {
				//����
				for (int j = tier + 1; j < n; ++j) {
					tmp[j][i] = '*';
				}
				//��б��
				for (int j = tier + 1, k = i - 1; j < n && k >= 0; ++j, --k) {
					tmp[j][k] = '*';
				}
				//��б��
				for (int j = tier + 1, k = i + 1; j < n && k < n; ++j, ++k) {
					tmp[j][k] = '*';
				}

				backtracking(n, methods, tmp, tier + 1);

				//���ص�ǰ��ʱ��Ҫ�ָ�tmp����
				tmp.assign(element.begin(), element.end());
			}
		}
	}
};