#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> ans;
		int prev = nums[0];
		ans.push_back(prev);
		int prec = 1;
		for (size_t i=1; i<nums.size(); ++i) {
			if (nums[i] == prev) {
				if (prec >= 2) continue;
				prec++;
			} else {
				prev = nums[i];
				prec = 1;
			}
			ans.push_back(nums[i]);
		}
		nums = ans;
		return ans.size();
    }
};
