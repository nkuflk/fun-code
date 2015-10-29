#include <vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans;
		int temp = 1;
		int len = nums.size();
		ans.push_back(1);
		for (int i=1; i<len; ++i) {
			temp *= nums[i-1];
			ans.push_back(temp);
		}
		temp = 1;
		for (int i=len-2; i>=0; --i) {
			temp *= nums[i+1];
			ans[i] *= temp;
		}
		return ans;
    }
};
