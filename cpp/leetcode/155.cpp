#include <stack>

using std::stack;

class MinStack {
public:
	stack<int> s;
	stack<int> t;

    void push(int x) {
		s.push(x);
		if (t.empty() or x <= getMin()) t.push(x);
    }

    void pop() {
		if (s.top() == getMin()) t.pop();
		s.pop();
    }

    int top() {
		return s.top();
    }

    int getMin() {
		return t.top();
    }
};
