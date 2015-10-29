#include <string>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
		if (a.size() < b.size()) {
			string t = b;
			b = a;
			a = t;
		}
		int d = a.size() - b.size();
		string ans(a.size()+1, ' ');
		int to = 0;
		for (int i=b.size()-1; i>=0; --i) {
			int num = (b[i]-'0') + (a[i+d]-'0') + to;
			to = num / 2;
			ans[i+d+1] = (num % 2) + '0';
		}
		for (int i=d-1; i>=0; --i) {
			int num = (a[i]-'0') + to;
			to = num / 2;
			ans[i+1] = (num % 2) + '0';
		}
		if (to) ans[0] = '1';
		else ans.erase(ans.begin());
		return ans;
    }
};
