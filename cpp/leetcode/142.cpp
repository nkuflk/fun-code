#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast and fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				while (slow != head) {
					slow = slow->next;
					head = head->next;
				}
				return head;
			}
		}
		return NULL;
    }
};
