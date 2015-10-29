#include <vector>

using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int len = nums.size();
		int ans = (len + 1) * len / 2;
		for (int i=0; i<len; ++i) ans -= nums[i];
		return ans;
    }
};
