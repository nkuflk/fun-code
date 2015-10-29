#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (size_t i=0; i<nums.size();) {
			if (nums[i] > 0) break;
			int start = i + 1;
			int end = nums.size() - 1;
			while (start < end) {
				int temp = nums[i] + nums[start] + nums[end];
				if (temp == 0) {
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[start]);
					v.push_back(nums[end]);
					ans.push_back(v);
					start++;
					end--;
					while (start<end and nums[start]==nums[start-1]) start++;
					while (start<end and nums[end]==nums[end+1]) end--;
				} else if (temp > 0) {
					end--;
					while (start<end and nums[end]==nums[end+1]) end--;
				} else if (temp < 0) {
					start++;
					while (start<end and nums[start]==nums[start-1]) start++;
				}
			}
			++i;
			while (i<nums.size() and nums[i]==nums[i-1]) ++i;
		}
		return ans;
    }
};
