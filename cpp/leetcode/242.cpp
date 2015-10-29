#include <string>
#include <cstring>

using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
		int lens = s.size();
		int lent = t.size();
		if (lens != lent) return false;
		int count[26];
		memset(count, 0, sizeof(count));
		for (int i=0; i<lens; ++i) {
			count[s[i]-'a']++;
			count[t[i]-'a']--;
		}
		for (int i=0; i<26; ++i) {
			if (count[i] != 0) return false;
		}
		return true;
    }
};
