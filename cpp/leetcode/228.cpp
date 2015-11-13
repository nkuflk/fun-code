#include <vector>
#include <sstream>
#include <string>

using std::stringstream;
using std::vector;
using std::string;

class Solution {
public:
	string intToStr(int n) {
		stringstream ss;
		ss << n;
		string ans;
		ss >> ans;
		return ans;
	}

    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		if (nums.empty()) {
			return ans;
		}
		int start = nums[0];
		int pos = 0;
		int len = nums.size();
		string str = intToStr(start);
		for (int i=1; i<len; ++i) {
			if (nums[i]-1 == start) {
				start++;
			} else {
				if (i-1 == pos) {
					ans.push_back(str);
				} else {
					ans.push_back(str + "->" + intToStr(nums[i-1]));
				}
				start = nums[i];
				str = intToStr(start);
				pos = i;
			}
		}
		if (pos == len-1) ans.push_back(str);
		else ans.push_back(str + "->" + intToStr(nums[len-1]));
		return ans;
    }
};
