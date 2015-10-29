#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int ans = 0;
		for (size_t i=0; i<nums.size(); ++i) {
			if (not i) ans++;
			else {
				if (nums[i] != nums[i-1]) {
					nums[ans] = nums[i];
					ans++;
				}
			}
		}
		return ans;
    }
};
