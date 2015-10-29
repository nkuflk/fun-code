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
	bool dfs(TreeNode *p, TreeNode *q) {
		if (not flag) return flag;
		if (not p) {
			if (not q) return true;
			else {
				flag = false;
				return flag;
			}
		} else {
			if (not q) {
				flag = false;
				return flag;
			} else {
				if (p->val != q->val) {
					flag = false;
					return flag;
				} else {
					dfs(p->left, q->left);
					dfs(p->right, q->right);
					return flag;
				}
			}
		}
	}

    bool isSameTree(TreeNode* p, TreeNode* q) {
		flag = true;
		return dfs(p, q);
    }
};
