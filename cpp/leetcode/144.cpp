#include <vector>
#include <cstdlib>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> ans;

class Solution {
public:
	void dfs(TreeNode* root) {
		if (not root) return;
		ans.push_back(root->val);
		dfs(root->left);
		dfs(root->right);
	}

    vector<int> preorderTraversal(TreeNode* root) {
		ans.clear();
		dfs(root);
		return ans;
    }
};
