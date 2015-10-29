#include <vector>

using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
    	int low = 0;
    	int high = nums.size()-1;
    	int start = nums[0];
    	int end = nums[high];
    	if (start <= end) return start;
    	while (low < high) {
    		int mid = (low + high) >> 1;
    		if (nums[mid] >= start) low = mid + 1;
    		else if (nums[mid] <= end) high = mid;
    	}
    	return nums[low];
    }
};
