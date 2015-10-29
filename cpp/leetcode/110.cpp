#include <cstdlib>
#include <algorithm>

using std::abs;
using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool flag;

class Solution {
public:
	int dfs(TreeNode* root, int dep) {
		if (not flag) {
			return 0;
		}
		if (not root) {
			return dep;
		}
		int left = dfs(root->left, dep+1);
		int right = dfs(root->right, dep+1);
		if (abs(left - right) > 1) {
			flag = false;
			return 0;
		}
		return max(left, right);
	}

    bool isBalanced(TreeNode* root) {
		flag = true;
		dfs(root, 0);
		return flag;
    }
};
