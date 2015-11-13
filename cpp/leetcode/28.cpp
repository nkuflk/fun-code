#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
		int hl = haystack.size();
		int nl = needle.size();
		for (int i=0; i<hl; ++i) {
			bool f = true;
			for (int j=0; j<nl; ++j) {
				if (needle[j] != haystack[i]) {
					f = false;
					break;
				}
			}
			if (f) return i;
		}
		return -1;
    }
};
