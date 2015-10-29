#include <vector>
#include <cstring>
using std::vector;

int dp[10010];

class Solution {
public:
    int jump(vector<int>& nums) {
		memset(dp, 0, sizeof(dp));
		int len = nums.size();
		int pos = len - 1;
		for (int i=len-2; i>=0; --i) {
			if (i + nums[i] >= pos) {
			}
		}
		return dp[0];
    }
};
