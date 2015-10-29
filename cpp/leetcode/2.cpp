#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

inline int cal(ListNode* &res, ListNode* &ans, int val) {
	ListNode *temp = new ListNode(val % 10);
	temp->next = NULL;
	if (not res) {
		res = temp;
		ans = res;
	}
	else {
		res->next = temp;
		res = res->next;
	}
	return val / 10;
}

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *res = NULL;
			ListNode *ans = NULL;
			int add = 0;
			while (l1 and l2) {
				int val = l1->val + l2->val + add;
				add = cal(res, ans, val);
				l1 = l1->next;
				l2 = l2->next;
			}
			while (l1) {
				int val = l1->val + add;
				add = cal(res, ans, val);
				l1 = l1->next;
			}
			while (l2) {
				int val = l2->val + add;
				add = cal(res, ans, val);
				l2 = l2->next;
			}
			if (add) {
				ListNode *temp = new ListNode(add);
				temp->next = NULL;
				res->next = temp;
			}
			return ans;
		}
};
