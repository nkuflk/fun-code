#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

/*
 * 1 ^ 0 = 1
 * 0 ^ 1 = 1
 * 0 ^ 0 = 0
 * 1 ^ 1 = 0
 * if a and b have different sign bit, sign bit of (a ^ b) is 1, ((a ^ b) < 0) will be true
 */

int main()
{
	int a = 99;
	bitset<32> a_bin(a);
	cout << "a(99)(0b" << a_bin << ")" << endl;

	int b = -19;
	bitset<32> b_bin(b);
	cout << "b(-19)(0b" << b_bin << ")" << endl;

	int c = 46;
	bitset<32> c_bin(c);
	cout << "c(46)(0b" << c_bin << ")" << endl;

	cout << "a(" << a << ") and b(" << b << ") is " << ((a ^ b) < 0) << endl;

	cout << "a(" << a << ") and c(" << c << ") is " << ((a ^ c) < 0) << endl;

	cout << "c(" << c << ") and b(" << b << ") is " << ((c ^ b) < 0) << endl;

	return 0;
}
