#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode* ans = head;
		while (head and head->next) {
			if (head->val == head->next->val) {
				head->next = head->next->next;
			} else {
				head = head->next;
			}
		}
		return ans;
    }
};
