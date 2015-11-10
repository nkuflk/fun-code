#include <cstdlib>

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		TreeLinkNode* cur = root;
		TreeLinkNode* left = NULL;
		TreeLinkNode* right = NULL;
		while (cur) {
			if (cur->left) {
				if (not right) {
					right = cur->left;
					left = right;
				} else {
					right->next = cur->left;
					right = right->next;
				}
			}
			if (cur->right) {
				if (not right) {
					right = cur->right;
					left = right;
				} else {
					right->next = cur->right;
					right = right->next;
				}
			}
			cur = cur->next;
			if (not cur) {
				cur = left;
				left = NULL;
				right = NULL;
			}
		}
    }
};
