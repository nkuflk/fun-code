#include <vector>
#include <cstdlib>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> ans;

class Solution {
public:
	void dfs(TreeNode* root, int sum, int num, vector<int> temp) {
		if (not root) return;
		if (not root->left and not root->right) {
			if (sum == num + root->val) {
				temp.push_back(root->val);
				ans.push_back(temp);
				return;
			}
		}
		temp.push_back(root->val);
		if (root->left) dfs(root->left, sum, num+root->val, temp);
		if (root->right) dfs(root->right, sum, num+root->val, temp);
		temp.pop_back();
	}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		ans.clear();
		vector<int> temp;
		dfs(root, sum, 0, temp);
		return ans;
    }
};
