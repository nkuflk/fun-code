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
	int find(vector<int> inorder, int start, int end, int val) {
		for (int i=start; i<=end; ++i) {
			if (inorder[i] == val) return i;
		}
		return -1;
	}

	TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
		if (ps > pe) return NULL;
		if (ps == pe) return new TreeNode(preorder[ps]);
		int index = find(inorder, is, ie, preorder[ps]);
		TreeNode* root = new TreeNode(preorder[ps]);
		root->left = build(preorder, ps+1, ps+index-is, inorder, is, index-1);
		root->right = build(preorder, ps+index-is+1, pe, inorder, index+1, ie);
		return root;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
