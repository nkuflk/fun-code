#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		vector<int> ans;
		for (size_t i=0; i<nums.size(); ++i) {
			if (nums[i] != val) {
				ans.push_back(nums[i]);
			}
		}
		nums = ans;
		return nums.size();
    }
};
