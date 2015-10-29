#include <cstdlib>
#include <vector>

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
		if (not root->left and not root->right) {
			ans.push_back(root->val);
			return;
		}
		if (root->left) dfs(root->left);
		if (root->right) dfs(root->right);
		ans.push_back(root->val);
	}

    vector<int> postorderTraversal(TreeNode* root) {
		ans.clear();
		dfs(root);
		return ans;
    }
};
