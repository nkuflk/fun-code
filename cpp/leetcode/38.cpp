#include <string>

using std::string;

class Solution {
	public:
		string countAndSay(int n) {
			string ans = "1";
			for (int i=1; i<n; ++i) {
				string tmp = "";
				char ch = ans[0];
				int count = 1;
				for (size_t k=1; k<ans.size(); ++k) {
					if (ch == ans[k]) {
						count++;
					} else {
						tmp += (count + '0');
						tmp += ch;
						count = 1;
						ch = ans[k];
					}
				}
				if (count) {
					tmp += (count + '0');
					tmp += ch;
				}
				ans = tmp;
			}
			return ans;
		}
};
