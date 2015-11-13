#include <vector>
#include <cstring>

using std::vector;

class NumArray {
public:
	int s[100010];
	int n;

    NumArray(vector<int> &nums) {
		memset(s, 0, sizeof(s));
		n = nums.size();
		for (int i=0; i<n; ++i) {
			update(i+1, nums[i]);
		}
    }

    int sumRange(int i, int j) {
		return sum(j+1) - sum(i);
    }

	int lowbit(int i) {
		return i & -i;
	}

	void update(int i, int x) {
		while (i <= n) {
			s[i] += x;
			i += lowbit(i);
		}
	}

	int sum(int i) {
		int ans = 0;
		while (i > 0) {
			ans += s[i];
			i -= lowbit(i);
		}
		return ans;
	}
};
