#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (size_t i=0; i<nums.size(); ++i) {
			if (m.find(nums[i])==m.end()) {
				m[nums[i]] = i;
			} else {
				int prev = m[nums[i]];
				if (int(i)-prev<=k) return true;
				else m[nums[i]] = i;
			}
		}
		return false;
    }
};
