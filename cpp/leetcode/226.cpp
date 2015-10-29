#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void dfs(TreeNode *root) {
		if (root == NULL) return;
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		dfs(root->left);
		dfs(root->right);
	}

    TreeNode* invertTree(TreeNode* root) {
		TreeNode* ans = root;
		dfs(root);
		return ans;
    }
};
