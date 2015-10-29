#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool flag;
int key;
int res;

class Solution {
public:
	void dfs(TreeNode* root, int k) {
		if (flag) return;
		if (not root) return;
		if (not root->left and not root->right) {
			res++;
			if (res == k) {
				key = root->val;
				flag = true;
			}
			return;
		}
		if (root->left) dfs(root->left, k);
		res++;
		if (res == k) {
			key = root->val;
			flag = true;
			return;
		}
		if (root->right) dfs(root->right, k);
	}

    int kthSmallest(TreeNode* root, int k) {
		flag = false;
		res = 0;
		dfs(root, k);
		return key;
    }
};
