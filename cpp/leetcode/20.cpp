#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
		stack<char> order;
		for (size_t i=0; i<s.size(); ++i) {
			if (s[i]=='(' or s[i]=='[' or s[i]=='{') {
				order.push(s[i]);
			} else if (s[i]==')') {
				if (not order.size()) return false;
				char ch = order.top();
				if (ch != '(') return false;
				order.pop();
			} else if (s[i]==']') {
				if (not order.size()) return false;
				char ch = order.top();
				if (ch != '[') return false;
				order.pop();
			} else if (s[i]=='}') {
				if (not order.size()) return false;
				char ch = order.top();
				if (ch != '{') return false;
				order.pop();
			}
		}
		if (order.size()) return false;
		else return true;
    }
};
