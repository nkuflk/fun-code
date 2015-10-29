#include <string>

using std::string;

int dp[10010];

class Solution {
public:
	int stringtoint(string s) {
		int ans = 0;
		for (size_t i=0; i<s.size(); ++i) {
			ans *= 10;
			ans += s[i]-'0';
		}
		return ans;
	}

    int numDecodings(string s) {
    	if (s.empty()) return 0;
    	dp[0] = 1;
		if (s[0]!='0') dp[1] = 1;
		else return 0;
    	for (size_t i=1; i<s.size(); ++i) {
    		if (s[i]!='0') dp[i+1] = dp[i];
			else dp[i+1] = 0;
			if (s[i-1]!='0') {
				int tmp = stringtoint(s.substr(i-1,2));
				if (tmp>0 and tmp<27) {
					dp[i+1] += dp[i-1];
				}
			}
    	}
    	return dp[s.size()];
    }
};
