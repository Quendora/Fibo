//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#ifndef FIBO_FIBO_H
#define FIBO_FIBO_H

#include <list>
#include <string>
using namespace std;

class Fibo {

private:
  std::list<short> fibits_;

  void Normalize();

  void RemoveNonBit();

public:
  Fibo(int ile); //FIXME: It's just for testing purpose

  std::string ToString() const;

  size_t length(); //tymczasowo size_t

  Fibo &operator+=(const Fibo &comp);

  Fibo &operator=(const Fibo &other);

  Fibo(Fibo &&to_move) noexcept;

  explicit Fibo(std::string str);
};

std::ostream &operator<<(std::ostream &os, Fibo const &fibo);

#endif //FIBO_FIBO_H
