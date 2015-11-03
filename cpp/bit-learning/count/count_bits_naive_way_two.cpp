#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

/*
 * calculate count 1 in binary x
 * O(log(n))
 * n & (n-1) can change the most right 1 to 0
 */

int main()
{
	unsigned int num = 19234;

	bitset<32> num_bin(num);

	unsigned int res = 0;

	while (num) {
		res += 1;
		num &= (num -1);
	}

	cout << "count(19234)(0b" << num_bin << ") bits = " << res << endl;

	return 0;
}
