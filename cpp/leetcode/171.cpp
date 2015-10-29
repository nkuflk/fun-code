#include <string>
#include <cmath>

using std::pow;
using std::string;

class Solution {
public:
    int titleToNumber(string s) {
		int len = s.size();
		int ans = 0;
		for (int i=0; i<len; ++i) {
			ans += pow(26, len-i-1) * (s[i] - 'A' + 1);
		}
		return ans;
    }
};
