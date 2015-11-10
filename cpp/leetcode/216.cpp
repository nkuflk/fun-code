#include <vector>

using std::vector;

vector<vector<int>> ans;

class Solution {
public:
	void dfs(vector<int> temp, int cur, int index, int k, int n, int sum) {
		if (cur==k) {
			if (sum==n) {
				ans.push_back(temp);
			}
			return;
		}
		for (int i=index; i<10; ++i) {
			temp.push_back(i);
			dfs(temp, cur+1, i+1, k, n, sum+i);
			temp.pop_back();
		}
	}

    vector<vector<int>> combinationSum3(int k, int n) {
		ans.clear();
		vector<int> temp;
		dfs(temp, 0, 1, k, n, 0);
		return ans;
    }
};
