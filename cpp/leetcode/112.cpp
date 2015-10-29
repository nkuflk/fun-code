#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool flag;

class Solution {
public:
	void dfs(TreeNode* root, int sum, int tmp) {
		if (flag) return;
		if (not root->left and not root->right) {
			if (sum == tmp) {
				flag = true;
				return;
			} else {
				return;
			}
		}
		if (root->left) dfs(root->left, sum, tmp + root->left->val);
		if (root->right) dfs(root->right, sum, tmp + root->right->val);
	}

    bool hasPathSum(TreeNode* root, int sum) {
		if (not root) return false;
		flag = false;
		dfs(root, sum, root->val);
		return flag;
    }
};
