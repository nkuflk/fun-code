#include <vector>
#include <cstring>

using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		vector<int> v(nums.size());
		int a[3];
		memset(a, 0, sizeof(a));
		for (size_t i=0; i<nums.size(); ++i) {
			a[nums[i]]++;
		}
		int b[3];
		b[0] = 0;
		b[1] = a[0];
		b[2] = a[0] + a[1];
		for (size_t i=0; i<nums.size(); ++i) {
			v[b[nums[i]]++] = nums[i];
		}
		nums = v;
    }
};
