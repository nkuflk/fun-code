class Solution {
public:
    bool isUgly(int num) {
		if (not num) return false;
		while (num%2 == 0) num /= 2;
		while (num%3 == 0) num /= 3;
		while (num%5 == 0) num /= 5;
		if (num == 1) return true;
		else return false;
    }
};
