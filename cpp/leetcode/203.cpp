#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode* res = head;
		while (res) {
			if (res->val == val) {
				res = res->next;
			} else {
				break;
			}
		}
		head = res;
		while (res and res->next) {
			if (res->next->val == val) {
				res->next = res->next->next; 
			} else {
				res = res->next;
			}
		}
		return head;
    }
};
