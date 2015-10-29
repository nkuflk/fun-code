#include <vector>

using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		bool row = false;
		bool col = false;
		for (int i=0; i<n; ++i) {
			if (not matrix[i][0]) {
				row = true;
				break;
			}
		}
		for (int j=0; j<m; ++j) {
			if (not matrix[0][j]) {
				col = true;
				break;
			}
		}
		for (int i=1; i<n; ++i)
			for (int j=1; j<m; ++j)
				if (not matrix[i][j])
					matrix[i][0] = matrix[0][j] = 0;
		for (int i=1; i<n; ++i)
			if (not matrix[i][0])
				for (int j=0; j<m; ++j)
					matrix[i][j] = 0;
		for (int j=1; j<m; ++j)
			if (not matrix[0][j])
				for (int i=0; i<n; ++i)
					matrix[i][j] = 0;
		if (row)
			for (int i=0; i<n; ++i)
				matrix[i][0] = 0;
		if (col)
			for (int j=0; j<m; ++j)
				matrix[0][j] = 0;
    }
};
