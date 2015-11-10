#include <string>

using std::string;

class Solution {
public:
	string trim(string s) {
		s.erase(0,s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		return s;
	}

    bool isNumber(string s) {
		s = trim(s);
		if (s[0] == '-' or s[0] == '+') s.erase(0, 1);
		if (s.empty()) return false;
		string prev = "";
		string next = "";
		bool flag = true;
		for (size_t i=0; i<s.size(); ++i) {
			if (s[i] == 'e' or s[i] == '.') {
				if (not flag) return false;
				if (s[i] == 'e') {
					if (prev.empty()) return false;
					if (i == s.size()-1) return false;
				} else {
					if (prev.empty() and i == s.size()-1) return false;
				}
				flag = false;
			} else {
				if (s[i] >= '0' and s[i] <= '9') {
					if (flag) prev += s[i];
					else next += s[i];
				} else {
					return false;
				}
			}
		}
    	return true;
    }
};
