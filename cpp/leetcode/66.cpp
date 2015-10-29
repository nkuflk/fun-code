#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		vector<int> ans(digits.size() + 1);
		int to = 1;
		for (int i=digits.size()-1; i>=0; --i) {
			int num = to + digits[i];
			to = num / 10;
			ans[i+1] = num % 10;
		}
		if (to) {
			ans[0] = 1;
		} else {
			ans.erase(ans.begin());
		}
		return ans;
    }
};
