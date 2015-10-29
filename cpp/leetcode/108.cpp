#include <cstdlib>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* dfs(vector<int>& nums, int start, int end) {
		if (start > end) return NULL;
		else if (start == end) return new TreeNode(nums[start]);
		else {
			int mid = (start + end) >> 1;
			TreeNode* root = new TreeNode(nums[mid]);
			root->left = dfs(nums, start, mid-1);
			root->right = dfs(nums, mid+1, end);
			return root;
		}
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return dfs(nums, 0, nums.size()-1);
    }
};
