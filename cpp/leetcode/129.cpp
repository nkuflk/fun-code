#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum;

class Solution {
public:
	void dfs(TreeNode* root, int num) {
		if (not root) return;
		if (not root->left and not root->right) {
			sum += (num * 10 + root->val);
			return;
		}
		if (root->left) dfs(root->left, num*10+root->val);
		if (root->right) dfs(root->right, num*10+root->val);
	}

    int sumNumbers(TreeNode* root) {
		sum = 0;
		dfs(root, 0);
		return sum;
    }
};
