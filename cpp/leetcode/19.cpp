#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* h1 = head;
		ListNode* h2 = head;
		while (n-- > 0) h2 = h2->next;
		if (not h2) return head->next;
		h2 = h2->next;
		while (h2) {
			h1 = h1->next;
			h2 = h2->next;
		}
		h1->next = h1->next->next;
		return head;
	}
};
