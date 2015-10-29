#include <cstdlib>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		if (not root) return ans;
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		vector<int> temp;
		TreeNode* pre = root;
		while (not q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			if (cur) {
				temp.push_back(cur->val);
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			} else {
				if (not pre) {
					break;
				} else {
					ans.push_back(temp);
					temp.clear();
					q.push(NULL);
				}
			}
			pre = cur;
		}
		vector<vector<int>> res;
		for (int i=ans.size()-1; i>=0; --i) {
			res.push_back(ans[i]);
		}
		return res;
    }
};
