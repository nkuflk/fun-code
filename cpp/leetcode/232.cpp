#include <stack>

using std::stack;

class Queue {
	stack<int> s;
public:
    // Push element x to the back of queue.
    void push(int x) {
		stack<int> temp;
		while (not s.empty()) {
			temp.push(s.top());
			s.pop();
		}
		temp.push(x);
		while (not temp.empty()) {
			s.push(temp.top());
			temp.pop();
		}
    }

    // Removes the element from in front of queue.
    void pop(void) {
		s.pop();
    }

    // Get the front element.
    int peek(void) {
		return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
		return s.empty();
    }
};
