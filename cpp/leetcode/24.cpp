#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		ListNode* ans = head;
		ListNode* res = head;
		bool first = true;
		while (head and head->next) {
			ListNode* temp = head->next->next;
			ListNode* tmp = head->next;
			head->next = temp;
			tmp->next = head;
			if (first) {
				ans = tmp;
				res = ans;
				first = false;
			} else {
				ans->next = tmp;
				ans = ans->next;
			}
			head = temp;
			ans = ans->next;
		}
		return res;
    }
};
