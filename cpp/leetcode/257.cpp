#include <vector>
#include <sstream>
#include <string>

using std::stringstream;
using std::vector;
using std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> ans;

class Solution {
public:
	string intToStr(int num) {
		stringstream ss;
		ss << num;
		string ans;
		ss >> ans;
		return ans;
	}

	void dfs(TreeNode* root, string str, int dep) {
		if (not root->left and not root->right) {
			if (dep > 0) ans.push_back(str + "->" + intToStr(root->val));
			else ans.push_back(intToStr(root->val));
			return;
		}
		if (root->left) {
			if (dep > 0) dfs(root->left, str + "->" + intToStr(root->val), dep+1);
			else dfs(root->left, str + intToStr(root->val), dep+1);
		}
		if (root->right) {
			if (dep > 0) dfs(root->right, str + "->" + intToStr(root->val), dep+1);
			else dfs(root->right, str + intToStr(root->val), dep+1);
		}
	}

    vector<string> binaryTreePaths(TreeNode* root) {
		ans.clear();
		if (not root) return ans;
		dfs(root, "", 0);
		return ans;
    }
};
