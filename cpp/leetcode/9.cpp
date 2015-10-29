class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;
		long temp = 0;
		long ori = x;
		while (x) {
			temp *= 10;
			temp += x%10;
			x /= 10;
		}
		if (ori == temp) return true;
		else return false;
    }
};
