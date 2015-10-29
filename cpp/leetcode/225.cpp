#include <queue>

using std::queue;

class Stack {
	queue<int> q;
	queue<int> temp;
public:
    // Push element x onto stack.
    void push(int x) {
		q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
		while (q.size() > 1) {
			temp.push(q.front());
			q.pop();
		}
		while (not q.empty()) q.pop();
		while (not temp.empty()) {
			q.push(temp.front());
			temp.pop();
		}
    }

    // Get the top element.
    int top() {
		while (q.size() > 1) {
			temp.push(q.front());
			q.pop();
		}
		int ans;
		while (not q.empty()) {
			ans = q.front();
			temp.push(ans);
			q.pop();
		}
		while (not temp.empty()) {
			q.push(temp.front());
			temp.pop();
		}
		return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
		return q.empty();
    }
};
