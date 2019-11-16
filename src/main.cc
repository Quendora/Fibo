#include <iostream>
#include "Fibo.h"

void testingADD()
{
	Fibo a(5);
	Fibo b(5);
	a += b;
	std::cerr << a;
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
//	testingADD();
//	testingAND();
//	testingOR();
//	testingXOR();
	testingLSHIFT();
}
