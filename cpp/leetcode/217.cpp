#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> m;
		for (size_t i=0; i<nums.size(); ++i) {
			if (m.find(nums[i]) == m.end()) {
				m[nums[i]] = 1;
			}
			else return true;
		}
		return false;
    }
};
