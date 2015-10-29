#include <vector>

using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int len = nums.size();
		for (int i=0; i<len; ++i) {
			if (i == 0) {
				if (len > 1 and nums[0] > nums[1]) return 0;
				else if (len == 1) return 0;
			} else if (i == len-1) {
				if (len > 1 and nums[i] > nums[i-1]) return i;
			} else {
				if (nums[i] > nums[i-1] and nums[i] > nums[i+1]){
					return i;
				}
			}
		}
		return -1;
    }
};
