#include <vector>
#include <cstring>

using std::vector;

vector<vector<int>> ans;
bool used[110];
int len;

class Solution {
public:
	void dfs(vector<int> &nums, vector<int> tmp) {
		if ((int)tmp.size() == len) {
			ans.push_back(tmp);
			return;
		}
		for (int i=0; i<len; ++i) {
			if (not used[i]) {
				used[i] = true;
				tmp.push_back(nums[i]);
				dfs(nums, tmp);
				tmp.pop_back();
				used[i] = false;
			}
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
		ans.clear();
		memset(used, false, sizeof(used));
		len = nums.size();
		vector<int> tmp;
		for (int i=0; i<len; ++i) {
			tmp.push_back(nums[i]);
			used[i] = true;
			dfs(nums, tmp);
			used[i] = false;
			tmp.pop_back();
		}
		return ans;
    }
};
