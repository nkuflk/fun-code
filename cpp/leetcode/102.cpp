#include <vector>
#include <cstdlib>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (not root) return ans;
		queue<TreeNode*> que;
		que.push(root);
		que.push(NULL);
		vector<int> tmp;
		bool pre = false;
		while (not que.empty()) {
			TreeNode* pointer = que.front();
			que.pop();
			if (not pointer) {
				if (pre) break;
				else {
					ans.push_back(tmp);
					tmp.clear();
					que.push(NULL);
					pre = true;
				}
			} else {
				pre = false;
				tmp.push_back(pointer->val);
				if (pointer->left) que.push(pointer->left);
				if (pointer->right) que.push(pointer->right);
			}
		}
		return ans;
    }
};
