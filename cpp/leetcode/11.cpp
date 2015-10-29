#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int ans = -1;
		int i = 0, j = height.size() - 1;
		while (i < j) {
			int area = min(height[i], height[j]) * (j - i);
			ans = max(ans, area);
			if (height[i] > height[j]) j--;
			else i++;
		}
		return ans;
    }
};
