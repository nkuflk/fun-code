#include <algorithm>
#include <vector>
#include <cstring>

using std::max;
using std::vector;

int dp[10010];

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		return solve_nlogn(nums);
    }

	// run 92ms
	int solve_n2(vector<int>& nums) {
		int n = nums.size();
		for (int i=0; i<n; ++i) {
			dp[i] = 1;
		}
		for (int i=0; i<n; ++i) {
			for (int j=0; j<i; ++j) {
				if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		int ans = 0;
		for (int i=0; i<n; ++i) {
			ans = max(ans, dp[i]);
		}
		return ans;
	}

	// run 4ms
	int solve_nlogn(vector<int> & nums) {
		int n = nums.size();
		int ans = 0;
		for (int i=0; i<n; ++i) {
			if (not ans or nums[i] > dp[ans-1]) {
				dp[ans++] = nums[i];
			}
			if (nums[i] < dp[ans-1]) {
				int start = 0, end = ans-1;
				while (start <= end) {
					int mid = start + ((end - start) >> 1);
					if (dp[mid] >= nums[i]) {
						end = mid - 1;
					} else {
						start = mid + 1;
					}
				}
				dp[start] = nums[i];
			}
		}
		return ans;
	}
};
