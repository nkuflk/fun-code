#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

#define SWAP(a, b) ( a ^= b, b ^= a, a ^= b)

/*
 * 1 ^ 0 = 1
 * 0 ^ 1 = 1
 * 0 ^ 0 = 0
 * 1 ^ 1 = 0
 * after three ^, per bit of a and b can be swap
 */

int main()
{
	int a = 23;
	bitset<32> a_bin(a);
	cout<< "a(23)(0b" << a_bin << ")" << endl;

	int b = 97;
	bitset<32> b_bin(b);
	cout<< "b(97)(0b" << b_bin << ")" << endl;

	SWAP(a, b);

	cout << "swap(23, 97), a = " << a << ", b = " << b << endl;

	return 0;
}
