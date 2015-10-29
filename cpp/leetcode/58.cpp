#include <string>

using std::string;

class Solution {
public:
	string& trim(string &s)   
	{  
		if (s.empty())   
		{  
			return s;  
		}  
		s.erase(0,s.find_first_not_of(" "));  
		s.erase(s.find_last_not_of(" ") + 1);  
		return s;  
	}  

    int lengthOfLastWord(string s) {
		trim(s);
		if (s.empty()) return 0;
		int ans = 0;
		for (int i=s.size()-1; i>=0; --i) {
			if (s[i] != ' ') ans++;
			else break;
		}
		return ans;
    }
};
