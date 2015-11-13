#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
	public:
		void reverseWords(string &s) {
			const string whitespace = " ";
			auto i = s.find_first_not_of(whitespace), j = s.find_last_not_of(whitespace);
			if (i == string::npos) { s.replace(0, s.size(), ""); return; }
			s = s.substr(i, j - i + 1); 

			i = s.find_first_of(whitespace);
			while (i != string::npos) {
				j = s.find_first_not_of(whitespace, i);
				s.replace(i, j - i, " ");
				i = s.find_first_of(whitespace, i + 1);
			}

			i = 0, j = 0;
			while (i != string::npos and j != string::npos) {
				j = s.find_first_of(whitespace, i);
				j == string::npos ? reverse(next(s.begin(), i), s.end()) : reverse(next(s.begin(), i), next(s.begin(), j));
				i = s.find_first_not_of(whitespace, j);
			}

			reverse(s.begin(), s.end());
		}
};
