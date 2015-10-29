#include <vector>
#include <string>

using std::string;
using std::vector;

string dig[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> ans;

class Solution {
public:
	void dfs(string str, string digits) {
		if (digits == "") {
			ans.push_back(str);
			return;
		}
		int num = digits[0] - '2';
		for (size_t i=0; i<dig[num].size(); ++i) {
			dfs(str + dig[num][i], digits.substr(1));
		}
	}

    vector<string> letterCombinations(string digits) {
		ans.clear();
		if (digits == "") return ans;
		dfs("", digits);
		return ans;
    }
};
