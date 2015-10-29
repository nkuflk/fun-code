#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
		if (not head) return NULL;
		if (not head->next) return new TreeNode(head->val);
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* prev = head;
		while (fast and fast->next) {
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}
		prev->next = NULL;
		TreeNode* root = new TreeNode(slow->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(slow->next);
		return root;
    }
};
