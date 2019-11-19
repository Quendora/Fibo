#include <iostream>
#include <cassert>
#include "Fibo.h"

void testingADD()
{
	Fibo a(5);
	Fibo b(5);
	a += b;
	std::cerr << a;
}

void testingSTRING_CONSTRUCTOR()
{
	Fibo a("10101");
	std::cerr << a << endl;
	Fibo b("001010001");
	std::cerr << b << endl;
}

void testingCOPY_CONSTRUCTOR()
{
	Fibo a(7);
	std::cerr << a << endl;
	Fibo b(5);
	std::cerr << b << endl;

	Fibo c = a;
	std::cerr << c << endl;
	a = b;
	std::cerr << c << endl;
}

void testingASSIGNMENT()
{
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

void testingLSHIFT()
{
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

void testingAND()
{
	Fibo a(5);
	std::cerr << a << endl;
	Fibo b(7);
	std::cerr << b << endl;

	a &= b;
	std::cerr << a << endl << endl;

	Fibo c(7);
	std::cerr << c << endl;
	Fibo d(5);
	std::cerr << d << endl;

	c &= d;
	std::cerr << c;
}

int main()
{
	Fibo f;

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
