#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n, vector<int>(n, 0));
		int x = 0, y = 0;
		int cur = 1;
		int len = n * n;
		int dir = 0;
		while (cur <= len) {
			ans[x][y] = cur++;
			if (dir == 0) {
				if (y+1<n and ans[x][y+1]==0) y++;
				else {
					dir = 1;
					x++;
				}
			} else if (dir == 1) {
				if (x+1<n and ans[x+1][y]==0) x++;
				else {
					dir = 2;
					y--;
				}
			} else if (dir == 2) {
				if (y-1>=0 and ans[x][y-1]==0) y--;
				else {
					dir = 3;
					x--;
				}
			} else if (dir == 3) {
				if (x-1>=0 and ans[x-1][y]==0) x--;
				else {
					dir = 0;
					y++;
				}
			}
		}
		return ans;
    }
};
