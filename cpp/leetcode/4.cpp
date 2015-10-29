#include <iostream>
#include <vector>
#include <climits>

using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::min;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int N1 = nums1.size();
		int N2 = nums2.size();
		if (N1 < N2) return findMedianSortedArrays(nums2, nums1);
		if (not N2) return ((double)nums1[(N1 - 1) >> 1] + (double)nums1[N1 >> 1]) / 2;
		int low = 0, high = N2 << 1;
		while (low <= high) {
			int mid2 = (low + high) >> 1;
			int mid1 = N1 + N2 - mid2;
			int L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) >> 1];
			int L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) >> 1];
			int R1 = (mid1 == N1 << 1) ? INT_MAX : nums1[mid1 >> 1];
			int R2 = (mid2 == N2 << 1) ? INT_MAX : nums2[mid2 >> 1];
			if (L1 > R2) low = mid2 + 1;
			else if (L2 > R1) high = mid2 - 1;
			else return (double)(max(L1, L2) + min(R1, R2)) / 2;
		}
		return -1;
    }
};
