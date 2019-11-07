//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#include "Fibo.h"

std::string Fibo::ToString() const
{
	string out;
	for(auto it : fibits_) {
		out += ('0'+it);
	}
	return out;
}

std::ostream &operator<<(std::ostream &os, Fibo const &fibo)
{
	return os
			<< fibo.ToString(); //FIXME: This is temporary as it may be inefficient
}

size_t Fibo::length()
{
	return fibits_.size();
}
Fibo &Fibo::operator+=(const Fibo &comp) {

	if(comp.fibits_.empty()) {
		return *this;
	}

	auto comp_ptr = comp.fibits_.end();
	auto this_ptr = fibits_.end();
	int it = 0;

	while(comp_ptr != comp.fibits_.begin()) {

		comp_ptr--;
		it++;

		if(it <= fibits_.size()) {
			this_ptr--;
			*this_ptr += *comp_ptr;
		}
		else {
			fibits_.push_front(*comp_ptr);
		}
	}

}
Fibo::Fibo(int ile) {

	for (int i = 0; i < ile; i++) {
		fibits_.push_back(1);
	}
}
