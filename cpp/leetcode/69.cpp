class Solution {
public:
    int mySqrt(int x) {
		 long start = 0, end = 65536;
		 while (start <= end) {
			 long mid = (start + end) >> 1;
			 long temp = mid * mid;
			 if (temp > x) {
				 end = mid - 1;
			 } else if (temp < x) {
				 start = mid + 1;
			 } else {
				 return mid;
			 }
		 }
		 return start - 1;
    }
};
