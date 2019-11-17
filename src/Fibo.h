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
  explicit Fibo(int ile); //FIXME: It's just for testing purpose
  Fibo(const Fibo &comp); //FIXME: explicit or implicit?

  std::string ToString() const;

  size_t length() const; //tymczasowo size_t

  Fibo &operator=(const Fibo &comp);
  Fibo &operator<<=(int n);
  Fibo &operator^=(const Fibo &comp);
  Fibo &operator|=(const Fibo &comp);
  Fibo &operator&=(const Fibo &comp);
  Fibo &operator+=(const Fibo &comp);

};

std::ostream &operator<<(std::ostream &os, Fibo const &fibo);

#endif //FIBO_FIBO_H
