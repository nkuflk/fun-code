#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int count = 0;
		for (vector<int>::iterator it=nums.begin(); it!=nums.end();) {
			if (*it == 0) {
				count++;
				nums.erase(it);
			} else {
				it++;
			}
		}
		for (int i=0; i<count; ++i) nums.push_back(0);
    }
};
