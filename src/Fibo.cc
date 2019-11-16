//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#include <iostream>
#include "Fibo.h"

std::string Fibo::ToString() const
{
	string out;
	for (auto it : fibits_)
	{
		out += ('0' + it);
	}
	return out;
}

std::ostream &operator<<(std::ostream &os, Fibo const &fibo)
{
	return os
			<< fibo.ToString(); //FIXME: This is temporary as it may be inefficient
}

size_t Fibo::length() const
{
	return fibits_.size();
}

Fibo &Fibo::operator<<=(int n)
{
	if (n >= length())
	{
		fibits_.clear();

		return *this;
	}

	for (int i = 0; i < n; i++)
	{
		fibits_.pop_front();
		fibits_.push_back(0);
	}

	Normalize();

	return *this;
}

Fibo &Fibo::operator^=(const Fibo &comp)
{
	if (comp.fibits_.empty())
	{
		return *this;
	}

	auto comp_ptr = comp.fibits_.end();
	auto this_ptr = fibits_.end();

	while (comp_ptr != comp.fibits_.begin() && this_ptr != fibits_.begin())
	{
		comp_ptr--;
		this_ptr--;

		if ((*this_ptr == 1 && *comp_ptr == 0) ||
		(*this_ptr == 0 && *comp_ptr == 1))
		{
			*this_ptr = 1;
		}
		else
		{
			*this_ptr = 0;
		}
	}

	while (comp_ptr != comp.fibits_.begin())
	{
		comp_ptr--;
		fibits_.push_front(*comp_ptr);
	}

	Normalize();

	return *this;
}


Fibo &Fibo::operator|=(const Fibo &comp)
{
	if (comp.fibits_.empty())
	{
		return *this;
	}

	auto comp_ptr = comp.fibits_.end();
	auto this_ptr = fibits_.end();

	while (comp_ptr != comp.fibits_.begin() && this_ptr != fibits_.begin())
	{
		comp_ptr--;
		this_ptr--;

		if (*this_ptr == 1 || *comp_ptr == 1)
		{
			*this_ptr = 1;
		}
		else
		{
			*this_ptr = 0;
		}
	}

	while (comp_ptr != comp.fibits_.begin())
	{
		comp_ptr--;
		fibits_.push_front(*comp_ptr);
	}

	Normalize();

	return *this;
}

Fibo &Fibo::operator&=(const Fibo &comp)
{
	if (comp.fibits_.empty())
	{
		fibits_.clear();

		return *this;
	}

	auto comp_ptr = comp.fibits_.end();
	auto this_ptr = fibits_.end();
	int it = 0;
	int minSize = min(comp.length(), this->length());

	while (it < minSize)
	{
		comp_ptr--;
		this_ptr--;
		it++;

		if (*this_ptr == 1 && *comp_ptr == 1)
		{
			*this_ptr = 1;
		}
		else
		{
			*this_ptr = 0;
		}
	}

	while (this_ptr != fibits_.begin())
	{
		this_ptr--;
		*this_ptr = 0;
	}

	Normalize();

	return *this;
}

Fibo &Fibo::operator+=(const Fibo &comp)
{
	if (comp.fibits_.empty())
	{
		return *this;
	}

	auto comp_ptr = comp.fibits_.end();
	auto this_ptr = fibits_.end();
	int it = 0;

	while (comp_ptr != comp.fibits_.begin())
	{
		comp_ptr--;
		it++;

		if (it <= fibits_.size())
		{
			this_ptr--;
			*this_ptr += *comp_ptr;
		}
		else
		{
			fibits_.push_front(*comp_ptr);
		}
	}

	RemoveNonBit();

	Normalize();

	return *this;
}

void Fibo::Normalize()
{
	for (int i = 0; i < 3; i++)
	{
		fibits_.push_front(0);
	}

	auto third_ptr = fibits_.end();
	third_ptr--;
	auto second_ptr = third_ptr;
	second_ptr--;
	auto first_ptr = second_ptr;
	first_ptr--;

	while (first_ptr != fibits_.begin())
	{
		if (*third_ptr == 1 && *second_ptr == 1 && *first_ptr == 0)
		{
			*first_ptr = 1;
			*second_ptr = 0;
			*third_ptr = 0;
		}

		third_ptr--;
		second_ptr--;
		first_ptr--;
	}
	while (third_ptr != fibits_.end())
	{
		if (*third_ptr == 1 && *second_ptr == 1)
		{
			*first_ptr = 1;
			*second_ptr = 0;
			*third_ptr = 0;
		}

		third_ptr++;
		second_ptr++;
		first_ptr++;
	}

	first_ptr = fibits_.begin();
	while (!fibits_.empty() && *first_ptr == 0)
	{
		fibits_.pop_front();
		first_ptr = fibits_.begin();
	}
}

void Fibo::RemoveNonBit()
{
	for (int i = 0; i < 3; i++)
	{
		fibits_.push_front(0);
	}

	auto first_ptr = fibits_.begin();
	auto second_ptr = first_ptr;
	second_ptr++;
	auto third_ptr = second_ptr;
	third_ptr++;
	auto forth_ptr = third_ptr;
	forth_ptr++;

	while (forth_ptr != fibits_.end())
	{
		if (*second_ptr == 2 && *third_ptr == 0)
		{
			*first_ptr = 1;
			*second_ptr = 0;
			(*forth_ptr)++;
		}

		if (*second_ptr == 3 && *third_ptr == 0)
		{
			*first_ptr = 1;
			*second_ptr = 1;
			(*forth_ptr)++;
		}

		if (*second_ptr == 2 && *third_ptr == 1)
		{
			*first_ptr = 1;
			*second_ptr = 1;
			*third_ptr = 0;
		}

		if (*second_ptr == 1 && *third_ptr == 2)
		{
			*first_ptr = 1;
			*second_ptr = 0;
			*third_ptr = 1;
		}

		first_ptr++;
		second_ptr++;
		third_ptr++;
		forth_ptr++;
	}

	if (*second_ptr == 2)
	{
		if (*third_ptr == 0)
		{
			*first_ptr = 1;
			*second_ptr = 0;
			*third_ptr = 1;
		}
		else
		{
			*first_ptr = 1;
			*second_ptr = 1;
			*third_ptr = 0;
		}
	}

	if (*third_ptr >= 2)
	{
		*second_ptr = 1;

		if (*third_ptr == 2)
		{
			*third_ptr = 0;
		}
		else
		{
			*third_ptr = 1;
		}
	}
}

Fibo::Fibo(int ile)
{
	for (int i = 0; i < ile; i++)
	{
		fibits_.push_back((i + 1) % 2);
	}
}
