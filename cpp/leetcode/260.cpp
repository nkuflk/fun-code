#include <cstdlib>
#include <vector>

using std::size_t;
using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		int res = 0;
		for (size_t i=0; i<nums.size(); ++i) res ^= nums[i];
		int pos = 1;
		while ((pos & res) != pos) pos <<= 1;
		int x = 0;
		for (size_t i=0; i<nums.size(); ++i)
			if (pos & nums[i]) x ^= nums[i];
		int y = x ^ res;
		vector<int> ans;
		ans.push_back(x);
		ans.push_back(y);
		return ans;
    }
};
