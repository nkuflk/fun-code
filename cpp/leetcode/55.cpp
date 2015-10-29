#include <vector>

using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int len = nums.size();
		if (len == 1) return true;
		int pos = len - 1;
		for (int i=len-2; i>=0; --i) {
			if (i + nums[i] >= pos) {
				pos = i;
			}
			if (not pos) return true;
		}
		return false;
    }
};
