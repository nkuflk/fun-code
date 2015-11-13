#include <algorithm>

using std::min;
using std::max;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		long ans = (long(D) - long(B)) * (long(C) - long(A)) + (long(H) - long(F)) * (long(G) - long(E));
		long w = max(0l, min(long(C), long(G)) - max(long(A), long(E)));
		long h = max(0l, min(long(D), long(H)) - max(long(B), long(F)));
		ans -= w * h;
		return ans;
    }
};
