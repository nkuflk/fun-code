#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.empty()) return 0;
    	int pre = prices[0];
    	int ans = 0;
    	for (size_t i=1; i<prices.size(); ++i) {
    		if (prices[i] > pre) {
    			ans = max(ans, prices[i]-pre);
    		} else {
    			pre = prices[i];
    		}
    	}
    	return ans;
    }
};
