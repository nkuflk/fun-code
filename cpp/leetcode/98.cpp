#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool dfs(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
		if (not root) return true;
		if ((minNode and root->val<=minNode->val) or (maxNode and root->val>=maxNode->val)) return false;
		return dfs(root->left, minNode, root) and dfs(root->right, root, maxNode);
	}

    bool isValidBST(TreeNode* root) {
		return dfs(root, NULL, NULL);
    }
};
