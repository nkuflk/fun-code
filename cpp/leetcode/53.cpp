#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int ans = nums[0];
		int tmp = nums[0] > 0 ? nums[0] : 0;
		for (size_t i=1; i<nums.size(); ++i) {
			tmp += nums[i];
			ans = max(tmp, ans);
			if (tmp < 0) tmp = 0;
		}
		return ans;
    }
};
