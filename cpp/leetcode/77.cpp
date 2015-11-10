#include <vector>

using std::vector;

vector<vector<int>> ans;

class Solution {
public:
	void dfs(int index, int cur, int k, int n, vector<int> temp) {
		if (cur == k) {
			ans.push_back(temp);
			return;
		}
		for (int i=index; i<=n; ++i) {
			temp.push_back(i);
			dfs(i+1, cur+1, k, n, temp);
			temp.pop_back();
		}
	}

    vector<vector<int>> combine(int n, int k) {
		ans.clear();
		vector<int> temp;
		dfs(1, 0, k, n, temp);
		return ans;
    }
};
