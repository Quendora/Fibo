//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#ifndef FIBO_FIBO_H
#define FIBO_FIBO_H

#include <list>
#include <string>
#include <vector>

using namespace std;

class Fibo
{
private:
	std::vector<bool> fibits_;

	void Normalize();

	bool get(size_t pos) const;

public:

	Fibo(long long n);
	Fibo(unsigned long long n); //FIXME: It's just for testing purpose
	Fibo(int n) : Fibo((long long) n) {};
	Fibo(unsigned int n) : Fibo((unsigned long long) n) {};
	Fibo(short n) : Fibo((long long) n) {};
	Fibo(unsigned short n) : Fibo((unsigned long long) n) {};
	Fibo(int8_t n) : Fibo((long long) n) {};
	Fibo(uint8_t n) : Fibo((unsigned long long) n) {};

	Fibo(const Fibo &comp); //FIXME: explicit or implicit?
	Fibo(Fibo &&comp);

	Fibo(const char a) = delete;
	Fibo(const bool b) = delete;

	explicit Fibo(const string &s);
	explicit Fibo(const char* s) : Fibo((string) s) {};

	Fibo();

	std::string ToString() const;

	size_t length() const; //tymczasowo size_t

	Fibo &operator=(const Fibo &comp);

	bool operator!=(const Fibo &comp) const;

	bool operator==(const Fibo &comp) const;

	bool operator>=(const Fibo &comp) const;

	bool operator>(const Fibo &comp) const;

	bool operator<=(const Fibo &comp) const;

	bool operator<(const Fibo &comp) const;

	Fibo &operator<<=(int n);

	Fibo &operator^=(const Fibo &comp);

	Fibo &operator|=(const Fibo &comp);

	Fibo &operator&=(const Fibo &comp);

	Fibo &operator+=(const Fibo &comp);

};

const Fibo Zero();

const Fibo One();

bool operator<(const Fibo &comp1, const Fibo &comp2);

bool operator>(const Fibo &comp1, const Fibo &comp2);

Fibo operator+(const Fibo &comp1, const Fibo &comp2);

Fibo operator&(const Fibo &comp1, const Fibo &comp2);

Fibo operator|(const Fibo &comp1, const Fibo &comp2);

Fibo operator^(const Fibo &comp1, const Fibo &comp2);

Fibo operator<<(const Fibo &comp, int n);

std::ostream &operator<<(std::ostream &os, Fibo const &fibo);

#endif //FIBO_FIBO_H
