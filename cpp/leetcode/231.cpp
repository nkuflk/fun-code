#include <cmath>

using std::log2;
using std::pow;

class Solution {
public:
    bool isPowerOfTwo(int n) {
		if (not n) return false;
		int a = log2(n);
		if (pow(2, a) == n) return true;
		else return false;
    }
};
