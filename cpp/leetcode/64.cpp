#include <vector>
#include <algorithm>

using std::min;
using std::vector;

int dp[1010][1010];

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		dp[0][0] = grid[0][0];
		for (size_t i=1; i<grid.size(); ++i) {
			dp[i][0] = dp[i-1][0] + grid[i][0];
		}
		for (size_t i=1; i<grid[0].size(); ++i) {
			dp[0][i] = dp[0][i-1] + grid[0][i];
		}
		for (size_t i=1; i<grid.size(); ++i) {
			for (size_t j=1; j<grid[0].size(); ++j) {
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
			}
		}
		return dp[grid.size()-1][grid[0].size()-1];
    }
};