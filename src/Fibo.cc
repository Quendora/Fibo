//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#include <iostream>
#include <algorithm>
#include <cassert>
#include "Fibo.h"

const char ZERO_CHAR = '0';
const int ZERO = false;
const int ONE = true;

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

//TODO CZY TRZEBA SPRAWDZAC CZY STRING JEST POPRAWNY? -- TAK
Fibo::Fibo(const string &s)
{
	for (char fibit: s)
	{
		fibits_.push_back(fibit - ZERO_CHAR);
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

Fibo::Fibo(unsigned long long n)
{
	for (int i = 0; i < n; i++)
	{
		fibits_.push_back((i + 1) % 2);
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

Fibo::Fibo(Fibo &&comp) : fibits_(move(comp.fibits_)) {}

size_t Fibo::length() const
{
	return fibits_.size();
}

std::string Fibo::ToString() const
{
	string out;
	for (auto it : fibits_)
	{
		out += (ZERO_CHAR + it);
	}
	reverse(out.begin(), out.end());
	return out;
}

std::ostream &operator<<(std::ostream &os, Fibo const &fibo)
{
	return os << fibo.ToString(); //FIXME: This is temporary as it may be inefficient
}

//TODO CZY DA SIE ZROBIC OPERATOR = ZA POMOCA KONSTRUKTORA KOPIUJACEGO?
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

bool Fibo::operator!=(const Fibo &comp) const
{
	return !(*this == comp);
}

bool Fibo::operator==(const Fibo &comp) const
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

bool Fibo::operator>=(const Fibo &comp) const
{
	return (*this == comp) || !(*this < comp);
}

bool Fibo::operator<=(const Fibo &comp) const
{
	return (*this == comp) || (*this < comp);
}

bool Fibo::operator>(const Fibo &comp) const
{
	return !(*this == comp) && !(*this < comp);
}

bool operator<(const Fibo &comp1, const Fibo &comp2)
{
	return Fibo(comp1) < comp2;
}

bool Fibo::operator<(const Fibo &comp) const
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
		fibits_.push_back(ZERO);
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
		comp_ptr++;
		this_ptr++;

		if ((*this_ptr == ONE && *comp_ptr == ZERO) ||
		(*this_ptr == ZERO && *comp_ptr == ONE))
		{
			*this_ptr = ONE;
		}
		else
		{
			*this_ptr = ZERO;
		}
	}

	while (comp_ptr != comp.fibits_.end())
	{
		comp_ptr++;
		fibits_.push_back(*comp_ptr);
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
		comp_ptr++;
		this_ptr++;

		if (*this_ptr == ONE || *comp_ptr == ONE)
		{
			*this_ptr = ONE;
		}
	}

	while (comp_ptr != comp.fibits_.end())
	{
		comp_ptr++;
		fibits_.push_back(*comp_ptr);
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
		comp_ptr++;
		this_ptr++;

		if (*this_ptr == ONE && *comp_ptr == ONE)
		{
			*this_ptr = ONE;
		}
		else
		{
			*this_ptr = ZERO;
		}
	}

	while (this_ptr != fibits_.end())
	{
		this_ptr++;
		*this_ptr = ZERO;
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
		fibits_.push_back(false);
	}
	for (int i = 0; i < 4; i++)
	{
		fibits_.push_back(false);
	}

	std::cout << *this << "\n";
	size_t ptr = fibits_.size() - 1;
	int big = 0;
	int medium = 0;
	int small = 0;
	int move = 0;

	while (ptr >= 3)
	{
		move = 0;
		move += fibits_[ptr - 3];
		move += comp.get(ptr - 3);

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

		big = medium;
		medium = small;
		small = move;
		ptr--;
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

	if (medium == 2)
	{
		if (small == 0)
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
		else
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
	}

	if (small >= 2)
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
	std::cout << *this << "\n";
	Normalize();

	return *this;
}

void Fibo::Normalize()
{
	std::cout << *this << "\n";
	for (int i = 0; i < 3; i++)
	{
		fibits_.push_back(false);

	}
	std::cout << *this << "\n";
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
			third_val = false;
		}

		third_val = second_val;
		second_val = first_val;
		first_pointing++;
		first_val = fibits_[first_pointing];
	}

	std::cout << *this << "\n";

	first_pointing = fibits_.size() - 1;
	first_val = fibits_[first_pointing];
	second_val = fibits_[first_pointing - 1];
	third_val = fibits_[first_pointing - 2];

	while (first_pointing > 2)
	{
		if (third_val && second_val)
		{
			auto &&first_ptr = fibits_[first_pointing];
			auto &&second_ptr = fibits_[first_pointing - 1];
			auto &&third_ptr = fibits_[first_pointing - 2];
			first_ptr = true;
			first_val = true;
			second_ptr = false;
			second_val = false;
			third_ptr = false;
			third_val = false;
		}

		first_pointing--;
		first_val = fibits_[first_pointing];
		second_val = fibits_[first_pointing - 1];
		third_val = fibits_[first_pointing - 2];
	}
	std::cout << *this << "\n";
	first_pointing = fibits_.size() - 1;
	while (!fibits_.empty() && !fibits_[first_pointing])
	{
		fibits_.pop_back();
		first_pointing--;
	}
}

