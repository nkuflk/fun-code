#include <string>

using std::string;

class Solution {
public:
	bool judge(char ch) {
		if (ch>='a' and ch<='z') return true;
		if (ch>='A' and ch<='Z') return true;
		if (ch>='0' and ch<='9') return true;
		return false;
	}

    bool isPalindrome(string s) {
		for (size_t i=0; i<s.size(); ++i) {
			if (not judge(s[i])) {
				s.erase(i, 1);
				--i;
			}
			if (s[i]>='A' and s[i]<='Z') {
				s[i] = s[i] - 'A' + 'a';
			}
		}
		int start = 0;
		int end = s.size() - 1;
		while (start <= end) {
			if (s[start] != s[end]) {
				return false;
			}
			start++;
			end--;
		}
		return true;
    }
};
