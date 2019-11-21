//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#include <algorithm>
#include <cassert>
#include "Fibo.h"

const char ZERO_ASCII = 48;
const char ONE_ASCII = 49;
const bool ZERO_BIT = false;
const bool ONE_BIT = true;
const int ZERO_NUMBER = 0;
const int ONE_NUMBER = 1;

const Fibo Zero()
{
	static const Fibo zero = Fibo();

	return zero;
}

const Fibo One()
{
	static const Fibo one = Fibo("1");

	return one;
}

Fibo::Fibo() = default;

Fibo::Fibo(const string &s)
{
	assert(s[0] == ONE_ASCII);

	for (char fibit: s)
	{
		auto boolFibit = fibit - ZERO_ASCII;
		assert(boolFibit == ZERO_NUMBER || boolFibit == ONE_NUMBER);

		fibits_.push_back(fibit - ZERO_ASCII);
	}

	reverse(fibits_.begin(), fibits_.end());

	Normalize();
}

Fibo::Fibo(long long n)
{
	if (n >= 0)
	{
		*this = Fibo((unsigned long long) n);
	}
	else
	{
		assert(n >= 0);
	}
}

unsigned long long Fibo::set(unsigned long long expected,
		unsigned long long current /*= 1 */, unsigned long long prev /*= 1*/)
{

	size_t position = fibits_.size();
	fibits_.push_back(false);

	if (expected - current >= prev)
	{
		expected = set(expected, current + prev, current);
	}

	if (expected >= current)
	{
		auto &&bit = fibits_[position];
		bit = true;
		expected -= current;
	}
	return expected;
}

Fibo::Fibo(unsigned long long n)
{
	if (n > 0)
	{
		set(n);
	}
}

Fibo::Fibo(const Fibo &comp)
{
	if (this != &comp)
	{
		fibits_.clear();

		for (auto fibit: comp.fibits_)
		{
			fibits_.push_back(fibit);
		}
	}
}

Fibo::Fibo(Fibo &&comp) : fibits_(move(comp.fibits_))
{
}

size_t Fibo::length() const
{
	return fibits_.size();
}

std::string Fibo::ToString() const
{
	string out;
	for (auto it : fibits_)
	{
		out += (ZERO_ASCII + it);
	}
	if (fibits_.empty())
	{
		out = "0";
	}
	reverse(out.begin(), out.end());
	return out;
}

std::ostream &operator<<(std::ostream &os, Fibo const &fibo)
{
	return os
			<< fibo.ToString();
}

Fibo &Fibo::operator=(const Fibo &comp)
{
	if (this != &comp)
	{
		fibits_.clear();

		for (auto fibit: comp.fibits_)
		{
			fibits_.push_back(fibit);
		}
	}

	return *this;
}

bool Fibo::operator!=(const Fibo &comp)
{
	return !(*this == comp);
}

bool Fibo::operator==(const Fibo &comp)
{
	if (length() != comp.length())
	{
		return false;
	}

	auto comp_ptr = comp.fibits_.end();
	auto this_ptr = fibits_.end();

	while (this_ptr != fibits_.begin())
	{
		comp_ptr--;
		this_ptr--;

		if (*this_ptr != *comp_ptr)
		{
			return false;
		}
	}

	return true;
}

bool Fibo::operator>=(const Fibo &comp)
{
	return (*this == comp) || !(*this < comp);
}

bool Fibo::operator<=(const Fibo &comp)
{
	return (*this == comp) || (*this < comp);
}

bool Fibo::operator>(const Fibo &comp)
{
	return !(*this == comp) && !(*this < comp);
}

bool operator<(const Fibo &comp1, const Fibo &comp2)
{
	return Fibo(comp1) < comp2;
}

bool operator>(const Fibo &comp1, const Fibo &comp2)
{
	return Fibo(comp1) > comp2;
}

bool operator<=(const Fibo &comp1, const Fibo &comp2)
{
	return Fibo(comp1) <= comp2;
}

bool operator>=(const Fibo &comp1, const Fibo &comp2)
{
	return Fibo(comp1) >= comp2;
}

bool Fibo::operator<(const Fibo &comp)
{
	if (length() < comp.length())
	{
		return true;
	}
	else if (length() > comp.length())
	{
		return false;
	}
	else
	{
		auto comp_ptr = comp.fibits_.end();
		auto this_ptr = fibits_.end();

		while (this_ptr != fibits_.begin())
		{
			comp_ptr--;
			this_ptr--;

			if (*this_ptr < *comp_ptr)
			{
				return true;
			}
			else if (*this_ptr > *comp_ptr)
			{
				return false;
			}
		}

		return false;
	}
}

Fibo operator<<(const Fibo &comp, int n)
{
	return Fibo(comp) <<= n;
}

Fibo &Fibo::operator<<=(int n)
{
	reverse(fibits_.begin(), fibits_.end());

	for (int i = 0; i < n; i++)
	{
		fibits_.push_back(ZERO_BIT);
	}

	reverse(fibits_.begin(), fibits_.end());

	Normalize();

	return *this;
}

Fibo operator^(const Fibo &comp1, const Fibo &comp2)
{
	return Fibo(comp1) ^= Fibo(comp2);
}

Fibo &Fibo::operator^=(const Fibo &comp)
{
	if (comp.fibits_.empty())
	{
		return *this;
	}

	auto comp_ptr = comp.fibits_.begin();
	auto this_ptr = fibits_.begin();

	while (comp_ptr != comp.fibits_.end() && this_ptr != fibits_.end())
	{
      *this_ptr = (*this_ptr == ONE_BIT && *comp_ptr == ZERO_BIT) ||
          (*this_ptr == ZERO_BIT && *comp_ptr == ONE_BIT);

		comp_ptr++;
		this_ptr++;
	}

	while (comp_ptr != comp.fibits_.end())
	{
		fibits_.push_back(*comp_ptr);
		comp_ptr++;
	}

	Normalize();

	return *this;
}

Fibo operator|(const Fibo &comp1, const Fibo &comp2)
{
	return Fibo(comp1) |= Fibo(comp2);
}


Fibo &Fibo::operator|=(const Fibo &comp)
{
	if (comp.fibits_.empty())
	{
		return *this;
	}

	auto comp_ptr = comp.fibits_.begin();
	auto this_ptr = fibits_.begin();

	while (comp_ptr != comp.fibits_.end() && this_ptr != fibits_.end())
	{
		if (*this_ptr == ONE_BIT || *comp_ptr == ONE_BIT)
		{
			*this_ptr = ONE_BIT;
		}

		comp_ptr++;
		this_ptr++;
	}

	while (comp_ptr != comp.fibits_.end())
	{
		fibits_.push_back(*comp_ptr);
		comp_ptr++;
	}

	Normalize();

	return *this;
}

Fibo operator&(const Fibo &comp1, const Fibo &comp2)
{
	return Fibo(comp1) &= Fibo(comp2);
}

Fibo &Fibo::operator&=(const Fibo &comp)
{
	if (comp.fibits_.empty())
	{
		fibits_.clear();

		return *this;
	}

	auto comp_ptr = comp.fibits_.begin();
	auto this_ptr = fibits_.begin();

	while (comp_ptr != comp.fibits_.end() && this_ptr != fibits_.end())
	{
      *this_ptr = *this_ptr == ONE_BIT && *comp_ptr == ONE_BIT;

		comp_ptr++;
		this_ptr++;
	}

	while (this_ptr != fibits_.end())
	{
		*this_ptr = ZERO_BIT;
		this_ptr++;
	}

	Normalize();

	return *this;
}

bool Fibo::get(size_t pos) const
{
	if (pos < fibits_.size())
	{
		return fibits_[pos];
	}

	return false;
}

Fibo operator+(const Fibo &comp1, const Fibo &comp2)
{
	return Fibo(comp1) += Fibo(comp2);
}

Fibo &Fibo::operator+=(const Fibo &comp)
{
	if (comp.fibits_.empty())
	{
		return *this;
	}

	while (fibits_.size() < comp.fibits_.size())
	{
		fibits_.push_back(ZERO_BIT);
	}
	for (int i = 0; i < 4; i++)
	{
		fibits_.push_back(ZERO_BIT);
	}

	size_t ptr = fibits_.size() - 1;
	int big = 0;
	int medium = 0;
	int small = 0;
	int move = 0;

	while (ptr >= 2)
	{
		move = 0;
		if (ptr >= 3)
		{
			move += fibits_[ptr - 3];
			move += comp.get(ptr - 3);
		}

		if (big >= 1)
		{
			auto &&temp1 = fibits_[ptr];
			temp1 = true;
		}

		if (medium >= 1)
		{
			auto &&temp2 = fibits_[ptr - 1];
			temp2 = true;
		}

		if (small >= 1)
		{
			auto &&temp3 = fibits_[ptr - 2];
			temp3 = true;
		}

		if (medium == 2 && small == 0)
		{
			auto &&temp1 = fibits_[ptr];
			temp1 = true;
			auto &&temp2 = fibits_[ptr - 1];
			temp2 = false;
			medium = 0;
			move++;
		}

		if (medium == 3 && small == 0)
		{
			auto &&temp1 = fibits_[ptr];
			temp1 = true;
			auto &&temp2 = fibits_[ptr - 1];
			temp2 = true;
			move++;
		}

		if (medium == 2 && small == 1)
		{
			auto &&temp1 = fibits_[ptr];
			temp1 = true;
			auto &&temp2 = fibits_[ptr - 1];
			temp2 = true;
			medium = 1;

			auto &&temp3 = fibits_[ptr - 2];
			temp3 = false;
			small = 0;
		}

		if (medium == 1 && small == 2)
		{
			auto &&temp1 = fibits_[ptr];
			temp1 = true;
			auto &&temp2 = fibits_[ptr - 1];
			temp2 = false;
			medium = 0;
			auto &&temp3 = fibits_[ptr - 2];
			temp3 = true;
			small = 1;
		}

		if (ptr >= 3)
		{
			big = medium;
			medium = small;
			small = move;
		}

		ptr--;
	}

	small += move;
	ptr = 2;

	if (small >= 1)
	{
		auto &&temp3 = fibits_[ptr - 2];
		temp3 = true;
	}

	if (small >= 2 && medium == 0)
	{
		auto &&temp2 = fibits_[ptr - 1];
		temp2 = true;
		medium = 1;
		if (small == 2)
		{
			auto &&temp3 = fibits_[ptr - 2];
			temp3 = false;
			small = 0;
		}
		else
		{
			auto &&temp3 = fibits_[ptr - 2];
			temp3 = true;
			small = 1;
		}
	}

	if (medium == 1 && small == 2)
	{
		auto &&temp1 = fibits_[ptr];
		temp1 = true;
		auto &&temp2 = fibits_[ptr - 1];
		temp2 = false;
		auto &&temp3 = fibits_[ptr - 2];
		temp3 = true;
	}

	Normalize();

	return *this;
}

void Fibo::Normalize()
{
	for (int i = 0; i < 3; i++)
	{
		fibits_.push_back(false);
	}

	size_t first_pointing = 2;
	bool first_val = fibits_[first_pointing];
	bool second_val = fibits_[first_pointing - 1];
	bool third_val = fibits_[first_pointing - 2];
	while (first_pointing < fibits_.size())
	{
		if (third_val && second_val && !first_val)
		{
			auto &&first_ptr = fibits_[first_pointing];
			auto &&second_ptr = fibits_[first_pointing - 1];
			auto &&third_ptr = fibits_[first_pointing - 2];
			first_ptr = true;
			first_val = true;
			second_ptr = false;
			second_val = false;
			third_ptr = false;
		}

		third_val = second_val;
		second_val = first_val;
		first_pointing++;
		first_val = fibits_[first_pointing];
	}

	first_pointing = fibits_.size();

	while (first_pointing > 2)
	{
		first_pointing--;
		second_val = fibits_[first_pointing - 1];
		third_val = fibits_[first_pointing - 2];
		if (third_val && second_val)
		{
			auto &&first_ptr = fibits_[first_pointing];
			auto &&second_ptr = fibits_[first_pointing - 1];
			auto &&third_ptr = fibits_[first_pointing - 2];
			first_ptr = true;
			second_ptr = false;
			third_ptr = false;
		}
	}

	first_pointing = fibits_.size() - 1;
	while (!fibits_.empty() && !fibits_[first_pointing])
	{
		fibits_.pop_back();
		first_pointing--;
	}
}

