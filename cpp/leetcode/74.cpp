#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();
		int start = 0, end = n * m - 1;
		while (start <= end) {
			int mid = (start + end) >> 1;
			int x = mid / m;
			int y = mid % m;
			if (matrix[x][y] > target) {
				end = mid - 1;
			} else if (matrix[x][y] < target) {
				start = mid + 1;
			} else {
				return true;
			}
		}
		return false;
    }
};
