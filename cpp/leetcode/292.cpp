class Solution {
public:
    bool canWinNim(int n) {
		int res = n % 4;
		if (not res) return false;
		else return true;
    }
};
