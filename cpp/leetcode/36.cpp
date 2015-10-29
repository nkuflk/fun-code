#include <vector>
#include <cstring>

using std::vector;

int dirx[3] = {-1, 0, 1};
int diry[3] = {-1, 0, 1};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		for (size_t i=0; i<board.size(); ++i) {
			bool used[10];
			memset(used, false, sizeof(used));
			for (size_t j=0; j<board[i].size(); ++j) {
				if (board[i][j] == '.') continue;
				if (used[board[i][j]-'0']) return false;
				used[board[i][j]-'0'] = true;
			}
		}
		for (size_t i=0; i<board.size(); ++i) {
			bool used[10];
			memset(used, false, sizeof(used));
			for (size_t j=0; j<board[i].size(); ++j) {
				if (board[j][i] == '.') continue;
				if (used[board[j][i]-'0']) return false;
				used[board[j][i]-'0'] = true;
			}
		}
		for (size_t i=1; i<board.size(); i+=3) {
			for (size_t j=1; j<board[i].size(); j+=3) {
				if (not block(board, i, j)) return false;
			}
		}
		return true;
    }

	bool block(vector<vector<char>>& board, int x, int y) {
		bool used[10];
		memset(used, false, sizeof(used));
		for (int i=0; i<3; ++i) {
			int nx = x + dirx[i];
			for (int j=0; j<3; ++j) {
				int ny = y + diry[j];
				if (board[nx][ny] == '.') continue;
				if (used[board[nx][ny]-'0']) return false;
				used[board[nx][ny]-'0'] = true;
			}
		}
		return true;
	}
};
