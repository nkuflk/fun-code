#include <iostream>
#include <climits>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

/*
 * rm the last 1 from a
 * len of a is 31 in c++ unsigned int
 * loop until a is 0:
 *	   left shift b
 *	   add the bit from a's tail to b's tail
 *	   right shift a
 *	   len reduce by 1
 *	add len 0s to b's tail
 */

int main()
{
	unsigned int a = 61283;
	bitset<32> a_bin(a);
	cout << "before reverse: (" << a << ")(0b" << a_bin << ")" << endl;

	unsigned int b = a;

	int len = sizeof(a) * CHAR_BIT - 1;

	for (a >>= 1; a; a >>= 1) {
		b <<= 1;
		b |= a & 1;
		len--;
	}

	b <<= len;
	bitset<32> b_bin(b);

	cout << "after reverse: (" << b << ")(0b" << b_bin << ")" << endl;

	return 0;
}
