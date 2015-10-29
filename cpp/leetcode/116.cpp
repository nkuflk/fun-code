#include <cstdlib>
#include <queue>

using std::queue;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		queue<TreeLinkNode*> q;
		q.push(root);
		q.push(NULL);
		TreeLinkNode* prev = NULL;
		while (not q.empty()) {
			TreeLinkNode* cur = q.front();
			q.pop();
			if (not prev and not cur) break;
			if (prev) {
				prev->next = cur;
			}
			if (not cur) {
				q.push(NULL);
			}
			if (cur and cur->left) q.push(cur->left);
			if (cur and cur->right) q.push(cur->right);
			prev = cur;
		}
    }
};
