#include <string>
#include <algorithm>
#include <unordered_map>

using std::string;
using std::max;
using std::unordered_map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) return 0;
		unordered_map<char, int> map;
		int dp[100010];
		dp[0] = 1;
		map[s[0]] = 0;
		int res = 1;
		for (int i=1; i<(int)s.size(); ++i) {
			if (map.find(s[i]) == map.end()) {
				dp[i] = dp[i-1] + 1;
			} else {
				if (map[s[i]] >= i-dp[i-1]) {
					dp[i] = i - map[s[i]];
				} else {
					dp[i] = dp[i-1] + 1;
				}
			}
			res = max(res, dp[i]);
			map[s[i]] = i;
		}
		return res;
    }
};
