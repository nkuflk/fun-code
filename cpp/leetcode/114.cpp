#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
		if (not root) return;
		flatten(root->left);
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		if (left) {
			root->right = left;
			root->left = NULL;
			if (right) {
				while (left and left->right) {
					left = left->right;
				}
				left->right = right;
			}
		}
		flatten(root->right);
    }
};
