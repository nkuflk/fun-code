#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* temp = new ListNode(0);
		temp->next = head;
		ListNode* ans = temp;
		int pos = 1;
		ListNode* prev = temp;
		while (head and head->next) {
			if (pos < m) {
				pos++;
				prev = head;
				head = head->next;
			} else {
				if (pos < n) {
					ListNode* tmp = head->next;
					head->next = head->next->next;
					tmp->next = prev->next;
					prev->next = tmp;
					pos++;
				} else {
					head = head->next;
				}
			}
		}
		return ans->next;
    }
};
