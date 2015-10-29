#include <cmath>
#include <string>

using std::string;

string trim(const string& str)
{
	string::size_type pos = str.find_first_not_of(' ');
	if (pos == string::npos)
	{
		return str;
	}
	string::size_type pos2 = str.find_last_not_of(' ');
	if (pos2 != string::npos)
	{
		return str.substr(pos, pos2 - pos + 1);
	}
	return str.substr(pos);
}

int returnAns(bool flag, long ans) {
	ans = flag? ans : -ans;
	if (ans > 0x7FFFFFFF) return 0x7FFFFFFF;
	if (-ans > 0x80000000) return -0x80000000;
	return (int)ans;
}

class Solution {
public:
    int myAtoi(string str) {
		if (not str.compare("")) return 0;
		str = trim(str);
		bool sign = false;
		if (str[0]=='-' or str[0]=='+') sign = true;
		bool flag = str[0]!='-';
		long ans = 0;
		if (sign) str = str.substr(1);
		int len = str.size();
		int pos = -1;
		for (int i=0; i<len; ++i) {
			if (str[i]<'0' or str[i]>'9') {
				pos = i;
				break;
			}
		}
		if (pos != -1) str = str.substr(0, pos);
		len = str.size();
		if (len > 11) {
			long res = 999999999999;
			return returnAns(flag, res);
		}
		for (int i=0; i<len; ++i) {
			ans += (str[i]-'0') * pow(10, len-1-i);
		}
		return returnAns(flag, ans);
    }
};
