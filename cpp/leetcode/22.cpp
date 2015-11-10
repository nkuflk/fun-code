#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> ans;

class Solution {
public:
	void dfs(string s, int left, int right, int n) {
		if (right > left) return;
		if (left > n) return;
		if (left==n and right==n) {
			ans.push_back(s);
			return;
		}
		dfs(s+"(", left+1, right, n);
		dfs(s+")", left, right+1, n);
	}

    vector<string> generateParenthesis(int n) {
		ans.clear();
		dfs("", 0, 0, n);
		return ans;
    }
};
