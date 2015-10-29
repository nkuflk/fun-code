#include <cstring>

bool used[1010];

class Solution {
public:
    bool isHappy(int n) {
		memset(used, false, sizeof(used));
		while (n != 1) {
			int res = 0;
			int temp = n;
			while (temp) {
				res += (temp%10) * (temp%10);
				temp /= 10;
			}
			if (used[res]) return false;
			else {
				used[res] = true;
			}
			n = res;
		}
		return true;
    }
};
