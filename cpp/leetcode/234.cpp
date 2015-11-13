#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if (not head or not head->next) return true;
		ListNode* slow = head;
		ListNode* fast = head;
		head = NULL;
		while (fast and fast->next) {
			ListNode* temp = slow;
			slow = slow->next;
			fast = fast->next->next;
			temp->next = head;
			head = temp;
		}
		if (fast) slow = slow->next;
		while (slow) {
			if (head->val != slow->val) {
				return false;
			}
			slow = slow->next;
			head = head->next;
		}
		return true;
    }
};
