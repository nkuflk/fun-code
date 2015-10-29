#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		int len = triangle.size();
		for (int i=len-2; i>=0; --i) {
			for (size_t j=0; j<triangle[i].size(); ++j) {
				triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
			}
		}
		return triangle[0][0];
    }
};
