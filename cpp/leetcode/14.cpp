#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::min;

class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			string str = "";
			int len = 0;
			for (size_t i=0; i<strs.size(); ++i) {
				if (not i) len = strs[0].size();
				len = min((int)strs[i].size(), len);
			}
			for (int i=0; i<len; ++i) {
				char ch = strs[0][i];
				for (size_t j=1; j<strs.size(); ++j) {
					if (ch != strs[j][i]) return str;
				}
				str += ch;
			}
			return str;
		}
};
