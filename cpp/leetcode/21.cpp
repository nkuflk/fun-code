#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (not l1) return l2;
			if (not l2) return l1;
			ListNode* head;
			if (l1->val < l2->val) {
				head = l1;
				l1 = l1->next;
			} else {
				head = l2;
				l2 = l2->next;
			}
			ListNode* ans = head;
			while (l1 and l2) {
				if (l1->val < l2->val) {
					head->next = l1;
					l1 = l1->next;
				} else {
					head->next = l2;
					l2 = l2->next;
				}
				head = head->next;
			}
			if (l1) head->next = l1;
			if (l2) head->next = l2;
			return ans;
		}
};
