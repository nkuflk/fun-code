const long ma = 2147483647;
const long mi = -2147483648;

class Solution {
	public:
		int reverse(int x) {
			long ans = 0;
			long bak = x;
			while (bak) {
				ans *= 10;
				ans += bak % 10;
				bak /= 10;
			}
			if (ans > ma or ans < mi) return 0;
			else return ans;
		}
};
