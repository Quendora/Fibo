//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#include <iostream>
#include "Fibo.h"

std::string Fibo::ToString() const
{
	string out;
	if(fibits_.empty()) {
	  out = "0";
	}
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

	RemoveNonBit();

  Normalize();

  return *this;
}

void Fibo::Normalize() {

  for(int i = 0; i < 3; i++) {
	  fibits_.push_front(0);
	}
  auto third_ptr = fibits_.end();
  third_ptr--;
  auto second_ptr = third_ptr;
  second_ptr--;
  auto first_ptr = second_ptr;
  first_ptr--;

  while (first_ptr != fibits_.begin()) {
      if(*first_ptr == 0 && *second_ptr == 1 && *third_ptr == 1) {
        *first_ptr = 1;
        *second_ptr = 0;
        *third_ptr = 0;
      }
      third_ptr--;
      second_ptr--;
      first_ptr--;
    }
  while(third_ptr != fibits_.end()) {

      if(*second_ptr == 1 && *third_ptr == 1) {
        *first_ptr = 1;
        *second_ptr = 0;
        *third_ptr = 0;
      }

      third_ptr++;
      second_ptr++;
      first_ptr++;
    }

  first_ptr = fibits_.begin();
  while (!fibits_.empty() && *first_ptr == 0) {
      fibits_.pop_front();
      first_ptr = fibits_.begin();
    }
}

void Fibo::RemoveNonBit() {

  for(int i = 0; i < 3; i++) {
    fibits_.push_front(0);
  }

  auto first_ptr = fibits_.begin();
  auto second_ptr = first_ptr;
  second_ptr++;
  auto third_ptr = second_ptr;
  third_ptr++;
  auto forth_ptr = third_ptr;
  forth_ptr++;

  while(forth_ptr != fibits_.end()) {

	  if(*second_ptr == 2 && *third_ptr == 0) {
	    *first_ptr = 1;
	    *second_ptr = 0;
        (*forth_ptr)++;
	  }

	  if(*second_ptr == 3 && *third_ptr == 0) {
        *first_ptr = 1;
        *second_ptr = 1;
        (*forth_ptr)++;
      }

	  if(*second_ptr == 2 && *third_ptr == 1) {
        *first_ptr = 1;
        *second_ptr = 1;
        *third_ptr = 0;
      }

	  if(*second_ptr == 1 && *third_ptr == 2) {
        *first_ptr = 1;
        *second_ptr = 0;
        *third_ptr = 1;
      }

	  first_ptr++;
	  second_ptr++;
	  third_ptr++;
	  forth_ptr++;
	}

  if(*second_ptr == 2) {

      if(*third_ptr == 0) {

        *first_ptr = 1;
        *second_ptr = 0;
        *third_ptr = 1;
      }
      else {

        *first_ptr = 1;
        *second_ptr = 1;
        *third_ptr = 0;
      }
	}

  if(*third_ptr >= 2) {

	  *second_ptr = 1;

	  if(*third_ptr == 2) {
	    *third_ptr = 0;
	  }
	  else {
	    *third_ptr = 1;
	  }

	}
}

Fibo::Fibo(int ile) {

	for (int i = 0; i < ile; i++) {
		fibits_.push_back((i+1)%2);
	}
}

Fibo::Fibo(Fibo &&to_move) noexcept {
  this->fibits_ = to_move.fibits_;
  std::cout << "HERE\n";
}

Fibo &Fibo::operator=(const Fibo &other) {
  if(&other != this) {
    this->fibits_.assign(other.fibits_.begin(), other.fibits_.end());
  }

  return *this;
}

Fibo::Fibo(std::string str) { //TODO: Check if correct

  for(char c : str) {
    fibits_.push_back(c-'0');
  }
  Normalize();
}
