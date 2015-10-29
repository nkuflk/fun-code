#include <vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int len = nums.size();
		int ans = 0;
		int count = 0;
		for (int i=0; i<len; ++i) {
			if (not count) {
				ans = nums[i];
				count++;
			} else {
				if (nums[i] == ans) {
					count++;
				} else {
					count--;
				}
			}
		}
		return ans;
    }
};
