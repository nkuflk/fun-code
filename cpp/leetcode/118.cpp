#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		for (int i= 0; i<numRows; ++i) {
			vector<int> temp;
			temp.push_back(1);
			if (i) {
				for (int j=1; j<=i/2; ++j) {
					temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
				}
				for (int j=(i-1)/2; j>=0; --j) {
					temp.push_back(temp[j]);
				}
			}
			ans.push_back(temp);
		}
		return ans;
    }
};
