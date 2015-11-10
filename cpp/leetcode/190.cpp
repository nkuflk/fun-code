#include <cstdint>
#include <climits>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t r = n;
		int s = sizeof(n) * CHAR_BIT - 1;
		for (n >>= 1; n; n >>= 1)
		{   
			r <<= 1;
			r |= n & 1;
			s--;
		}
		r <<= s;
		return r;
    }
};
