#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (size_t i=1; i<nums.size(); ++i) {
			if (nums[i] == nums[i-1]) return nums[i];
		}
    }
};
