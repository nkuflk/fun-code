#include <vector>
#include <cstring>
#include <algorithm>

using std::vector;
using std::sort;

vector<vector<int>> ans;
bool used[1010];

class Solution {
public:
	void dfs(vector<int>& nums, vector<int> temp, int index) {
		for (size_t i=index; i<nums.size(); ++i) {
			if (not used[i]) {
				used[i] = true;
				temp.push_back(nums[i]);
				ans.push_back(temp);
				dfs(nums, temp, i+1);
				temp.pop_back();
				used[i] = false;
			}
		}
	}

    vector<vector<int>> subsets(vector<int>& nums) {
		ans.clear();
		sort(nums.begin(), nums.end());
		memset(used, false, sizeof(used));
		vector<int> temp;
		ans.push_back(temp);
		dfs(nums, temp, 0);
		return ans;
    }
};
