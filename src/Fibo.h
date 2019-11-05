//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#ifndef FIBO_FIBO_H
#define FIBO_FIBO_H

#include <list>
#include <string>
using namespace std;

class Fibo
{
	private: std::list<short> fibits;
	public: std::string ToString() const;
			size_t length(); //tymczasowo size_t
};

std::ostream &operator<<(std::ostream &os, Fibo const &fibo);

#endif //FIBO_FIBO_H
