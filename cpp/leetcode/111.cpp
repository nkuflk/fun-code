#include <cstdlib>
#include <algorithm>

using std::min;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define Inf 0x7FFFFFFF

int ans;

class Solution {
public:
	void dfs(TreeNode* root, int dep) {
		if (not root) return;
		if (not root->left and not root->right) {
			ans = min(ans, dep);
			return;
		}
		dfs(root->left, dep+1);
		dfs(root->right, dep+1);
	}

    int minDepth(TreeNode* root) {
		if (not root) return 0;
		ans = Inf;
		dfs(root, 1);
		return ans;
    }
};
