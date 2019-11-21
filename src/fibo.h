//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#ifndef FIBO_FIBO_H
#define FIBO_FIBO_H

#include <string>
#include <vector>

using namespace std;

class Fibo
{
private:

	std::vector<bool> fibits_;

	void Normalize();

	bool get(size_t pos) const;

    unsigned long long set(unsigned long long expected,
    		unsigned long long current = 1, unsigned long long prev = 1);

public:

	Fibo(long long n);
	Fibo(unsigned long long n);
	Fibo(int n) : Fibo((long long) n) {};
	Fibo(unsigned int n) : Fibo((unsigned long long) n) {};
	Fibo(short n) : Fibo((long long) n) {};
	Fibo(unsigned short n) : Fibo((unsigned long long) n) {};
	Fibo(int8_t n) : Fibo((long long) n) {};
	Fibo(uint8_t n) : Fibo((unsigned long long) n) {};
	Fibo(int64_t n) : Fibo((long long) n) {};
	Fibo(uint64_t n) : Fibo((unsigned long long) n) {};

	Fibo(const Fibo &comp);
	Fibo(Fibo &&comp);

	Fibo(const char a) = delete;
	Fibo(const bool b) = delete;

	explicit Fibo(const string &s);
	explicit Fibo(const char* s) : Fibo((string) s) {};

	Fibo();

	std::string ToString() const;

	size_t length() const;

	bool operator!=(const Fibo &comp);
	bool operator==(const Fibo &comp) ;
	bool operator>=(const Fibo &comp);
	bool operator>(const Fibo &comp);
	bool operator<=(const Fibo &comp);
	bool operator<(const Fibo &comp);

	template <class T>
	Fibo &operator<<=(T) = delete;

	Fibo &operator<<=(unsigned long long n);

	Fibo &operator<<=(long long n);
	Fibo &operator<<=(int n);
	Fibo &operator<<=(unsigned int n);
	Fibo &operator<<=(short n);
	Fibo &operator<<=(unsigned short n);
	Fibo &operator<<=(int8_t n);
	Fibo &operator<<=(uint8_t n);
	Fibo &operator<<=(int64_t n);
	Fibo &operator<<=(uint64_t n);

	Fibo &operator=(const Fibo &comp);
	Fibo &operator^=(const Fibo &comp);
	Fibo &operator|=(const Fibo &comp);
	Fibo &operator&=(const Fibo &comp);
	Fibo &operator+=(const Fibo &comp);
};

const Fibo Zero();

const Fibo One();

bool operator<(const Fibo &comp1, const Fibo &comp2);
bool operator>(const Fibo &comp1, const Fibo &comp2);
bool operator<=(const Fibo &comp1, const Fibo &comp2);
bool operator>=(const Fibo &comp1, const Fibo &comp2);

Fibo operator+(const Fibo &comp1, const Fibo &comp2);
Fibo operator&(const Fibo &comp1, const Fibo &comp2);
Fibo operator|(const Fibo &comp1, const Fibo &comp2);
Fibo operator^(const Fibo &comp1, const Fibo &comp2);

bool operator!=(const Fibo &comp1, const Fibo &comp2);
bool operator==(const Fibo &comp1, const Fibo &comp2);

template <class T>
Fibo operator<<(const Fibo &comp, T) = delete;

Fibo operator<<(const Fibo &comp, unsigned long long n);
Fibo operator<<(const Fibo &comp, long long n);
Fibo operator<<(const Fibo &comp, int n);
Fibo operator<<(const Fibo &comp, unsigned int n);
Fibo operator<<(const Fibo &comp, short n);
Fibo operator<<(const Fibo &comp, unsigned short n);
Fibo operator<<(const Fibo &comp, int8_t n);
Fibo operator<<(const Fibo &comp, uint8_t n);
Fibo operator<<(const Fibo &comp, int64_t n);
Fibo operator<<(const Fibo &comp, uint64_t n);

std::ostream &operator<<(std::ostream &os, Fibo const &fibo);

#endif //FIBO_FIBO_H
