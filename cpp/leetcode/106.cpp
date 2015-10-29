#include <vector>
#include <cstdlib>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int find(vector<int>& inorder, int start, int end, int val) {
		for (int i=start; i<=end; ++i) {
			if (inorder[i] == val) return i;
		}
		return -1;
	}

	TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
		if (ps > pe) return NULL;
		if (ps == pe) return new TreeNode(postorder[pe]);
		int index = find(inorder, is, ie, postorder[pe]);
		TreeNode* root = new TreeNode(postorder[pe]);
		root->left = build(inorder, is, index-1, postorder, ps, ps+index-is-1);
		root->right = build(inorder, index+1, ie, postorder, ps+index-is, pe-1);
		return root;
	}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
