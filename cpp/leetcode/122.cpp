#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int pro = 0;
		int buy = 0;
		for (size_t i=0; i<prices.size(); ++i) {
			if (not i) {
				buy = prices[i];
			}
			if (i == prices.size()-1) {
				pro = pro + prices[i] - buy;
				break;
			}
			if (prices[i] >= prices[i+1]) {
				pro = pro + prices[i] - buy;
				buy = prices[i+1];
			}
		}
		return pro;
    }
};
