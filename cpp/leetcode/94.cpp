#include <cstdlib>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		while (root) {
			if (root->left) {
				TreeNode* temp = root->left;
				while (temp->right) temp = temp->right;
				temp->right = root;
				temp = root->left;
				root->left = NULL;
				root = temp;
			} else {
				ans.push_back(root->val);
				root = root->right;
			}
		}
		return ans;
    }
};
