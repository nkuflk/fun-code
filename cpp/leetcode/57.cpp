#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::max;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval &a, Interval &b) {
	if (a.start == b.start) return a.end < b.end;
	else return a.start < b.start;
}

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval> ans;
		Interval tmp;
		for (size_t i=0; i<intervals.size(); ++i) {
			if (not i) {
				tmp.start = intervals[i].start;
				tmp.end = intervals[i].end;
			} else {
				if (intervals[i].start <= tmp.end) {
					tmp.end = max(intervals[i].end, tmp.end);
				} else {
					ans.push_back(tmp);
					tmp.start = intervals[i].start;
					tmp.end = intervals[i].end;
				}
			}
			if (i == intervals.size()-1)
				ans.push_back(tmp);
		}
		return ans;
    }
};

