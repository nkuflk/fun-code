#include <string>

using std::string;

class Solution {
public:
    string convertToTitle(int n) {
		string ans = "";
		while (n) {
			n -= 1;
			int tmp = n % 26;
			char ch = 'A' + tmp;
			ans = ch + ans;
			n /= 26;
		}
		return ans;
    }
};
