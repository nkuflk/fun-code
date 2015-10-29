#include <vector>
#include <algorithm>

using std::max;
using std::vector;

int dp[10010][2];

class Solution {
public:
    int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		dp[0][0] = 0;
		dp[0][1] = nums[0];
		for (size_t i=1; i<nums.size(); ++i) {
			dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
			dp[i][1] = dp[i-1][0] + nums[i];
		}
		return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};
