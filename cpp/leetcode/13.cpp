#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

unordered_map<char, int> alph;

class Solution {
public:
	void init() {
		alph['I'] = 1;
		alph['V'] = 5;
		alph['X'] = 10;
		alph['L'] = 50;
		alph['C'] = 100;
		alph['D'] = 500;
		alph['M'] = 1000;
	}

    int romanToInt(string s) {
        init();
		int ans = alph[s[0]];
		for (size_t i=0; i<s.size()-1; ++i) {
			if (alph[s[i]] < alph[s[i+1]]) {
				ans -= alph[s[i]] * 2;
			}
			ans += alph[s[i+1]];
		}
		return ans;
    }
};
