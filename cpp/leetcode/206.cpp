#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode* ans;
		ListNode* prev = NULL;
		while (head) {
			ans = new ListNode(head->val);
			ans->next = prev;
			prev = ans;
			head = head->next;
		}
		return prev;
    }
};
