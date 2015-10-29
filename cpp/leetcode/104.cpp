#include <cstdlib>
#include <algorithm>

using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int len = 0;

class Solution {
public:
	void dfs(TreeNode* root, int dep) {
		if (not root) {
			len = max(len, dep);
			return;
		}
		dfs(root->left, dep + 1);
		dfs(root->right, dep + 1);
	}

    int maxDepth(TreeNode* root) {
		len = 0;
		dfs(root, 0);
		return len;
    }
};
