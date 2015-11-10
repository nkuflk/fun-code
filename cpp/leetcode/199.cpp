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
    vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		TreeNode* prev = root;
		while(not q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			if (not cur) {
				if (not prev) break;
				q.push(NULL);
				ans.push_back(prev->val);
			} else {
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			prev = cur;
		}
		return ans;
    }
};
