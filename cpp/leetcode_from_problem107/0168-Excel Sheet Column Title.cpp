#include <string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		if (n <= 0) return "";
		string result = "";
		while (n) {
			result = (char)('A' + (--n) % 26) + result;
			//cout<<n%26<<endl;
			//if(n%26==0) n-=26;
			n /= 26;
		}
		return result;
	}
};