#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

/*
 * calculate count 1 in binary x
 * need (& 1) per bit
 * if x & 1 equals 1, the most right bit in x is 1
 */

int main()
{
	unsigned int num = 19234;

	bitset<32> num_bin(num);

	unsigned int res = 0;

	for (; num; num >>= 1) {
		res += num & 1;
	}

	cout << "count(19234)(0b" << num_bin << ") bits = " << res << endl;

	return 0;
}
