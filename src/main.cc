#include <iostream>
#include <cassert>
#include <vector>
#include <zconf.h>
#include "Fibo.h"

void testingADD() {
	Fibo a(5);
	Fibo b(5);
	a += b;
	std::cerr << a;
}

void testingSTRING_CONSTRUCTOR() {
	Fibo a("10101");
	std::cerr << a << endl;
	Fibo b("001010001");
	std::cerr << b << endl;
}

void testingCOPY_CONSTRUCTOR() {
	Fibo a(7);
	std::cerr << a << endl;
	Fibo b(5);
	std::cerr << b << endl;

	Fibo c = a;
	std::cerr << c << endl;
	a = b;
	std::cerr << c << endl;
}

void testingASSIGNMENT() {
	Fibo a(7);
	std::cerr << a << endl;
	Fibo b(5);
	std::cerr << b << endl;
	Fibo c(8);
	std::cerr << c << endl;
	a = b;
	std::cerr << a << endl;
	b = c;
	std::cerr << a << endl;
}

void testingLSHIFT() {
	Fibo a(5);
	std::cerr << a << endl;
	a <<= 3;
	std::cerr << a << endl;

	Fibo b(7);
	std::cerr << b << endl;
	b <<= 4;
	std::cerr << b << endl;
}

void testingXOR()
{
	Fibo a(5);
	std::cerr << a << endl;
	Fibo b(7);
	std::cerr << b << endl;

	a ^= b;
	std::cerr << a << endl << endl;

	Fibo c(8);
	std::cerr << c << endl;
	Fibo d(5);
	std::cerr << d << endl;

	c ^= d;
	std::cerr << c;
}

void testingOR()
{
	Fibo a(5);
	std::cerr << a << endl;
	Fibo b(7);
	std::cerr << b << endl;

	a |= b;
	std::cerr << a << endl << endl;

	Fibo c(8);
	std::cerr << c << endl;
	Fibo d(5);
	std::cerr << d << endl;

	c |= d;
	std::cerr << c;
}

void testingAND() {
	Fibo a("11");
	std::cerr << "A " <<  a << endl;
	Fibo b("000000101001010011");
	std::cerr << "B " << b << endl;

	b &= a;
	std::cerr << "B " << b << endl << endl;
}

int main() {
	Fibo f;
	Fibo f0 = Zero();
	Fibo f1 = One();

	f0 = 0;
	f0 += 1;
	std::cout << f0 << " <- tyle\n";
	Fibo fibo = UINT64_MAX;

	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < 1000; j++) {
			bool tak;
			f0 = i;
			f0 += j;
			tak = (f0 == Fibo(i + j));
			if (!tak) {
				cout << f0 << " " << tak << " " << i << " " << j <<  "\n";
				break;
			}
		}
	}

	assert(f == Zero());
	assert(Fibo(f) == Zero());
	assert(Zero() < One());
	assert(Fibo("11") == Fibo("100"));
	assert((Fibo("1001") + Fibo("10")) == Fibo("1011"));
	assert((Fibo("1001") & Fibo("1100")) == Zero()); // 1100 == 10000
	assert((Fibo("1100") | Fibo("11")) == Fibo("10100")); // 1100 == 10000, 11 == 100
	assert((Fibo("1001") ^ Fibo("1010")) == Fibo("11"));
	assert((Fibo("101") << 3) == Fibo("101000"));

//	std::cout << f << "\n";
//	f += 1;
//	std::cout << f << "\n";
//	f += 1;
//	std::cout << f << "\n";
//	f += 1;
//	std::cout << f << "\n";
//	f += 1;
//	std::cout << f << "\n";
//	Zero() += Fibo("10"); // SHOULD NOT COMPILE
//	assert(f == Zero());
//	assert(Fibo(f) == Zero());
//	assert(Zero() < One());
//	assert(Fibo("11") == Fibo("100"));
//
//	f = One();
//	f <<= 3;
//	assert(f == Fibo("1000"));
//
//	assert(Fibo("11").length() == 3);
//
//	Fibo f1("101");
//	Fibo f2 = Fibo("101");
//	assert(f1 == f2);

//	testingADD();
//	testingAND();
//	testingOR();
//	testingXOR();
//	testingLSHIFT();
//	testingASSIGNMENT();
//	testingCOPY_CONSTRUCTOR();
//	testingSTRING_CONSTRUCTOR();
}
