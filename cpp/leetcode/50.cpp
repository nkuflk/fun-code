class Solution {
public:
    double myPow(double x, int n) {
		double ans = 1.0;
		int m = n;
		if (n < 0) n = -n;
		while (n > 0) {
			if (n & 1)
				ans *= x;
			x *= x;
			n >>= 1;
		}
		if (m < 0) return 1.0 / ans;
		return ans;
    }
};
