#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	int lower_bound(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = left + ((right - left) >> 1);
			if (target > nums[mid]) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}

	int upper_bound(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = left + ((right - left) >> 1);
			if (target < nums[mid]) right = mid - 1;
			else left = mid + 1;
		}
		return right;
	}

    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans;
		int left = lower_bound(nums, target);
		int right = upper_bound(nums, target);
		if (target != nums[left]) {
			ans.push_back(-1);
			ans.push_back(-1);
		} else {
			ans.push_back(left);
			ans.push_back(right);
		}
		return ans;
    }
};
