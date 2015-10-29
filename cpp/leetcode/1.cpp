#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> pos;
			vector<int> res;
			for (size_t i=0; i<nums.size(); ++i) {
				if (pos.find(target-nums[i]) != pos.end()) {
					res.push_back(pos[target-nums[i]]);
					res.push_back(i+1);
					break;
				}
				pos[nums[i]] = i+1;
			}
			return res;
		}
};
