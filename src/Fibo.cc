//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#include "Fibo.h"

std::string Fibo::ToString() const
{
	return "Here we should output string representing number\nP.S. Dont worry it's just sample output";
}

std::ostream &operator<<(std::ostream &os, Fibo const &fibo)
{
	return os
			<< fibo.ToString(); //FIXME: This is temporary as it may be inefficient
}

size_t Fibo::length()
{
	return fibits.size();
}