#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
		while (head and head->next) {
			if (head == head->next->next) return true;
			head->next = head->next->next;
			head = head->next;
		}
		return false;
    }
};
