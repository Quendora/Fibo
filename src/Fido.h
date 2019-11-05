//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#ifndef FIDO_FIDO_H
#define FIDO_FIDO_H

#include <list>
#include <string>

class Fido {
private:
  std::list<short> number;

public:
  std::string ToString() const;
};

std::ostream &operator<<(std::ostream &os, Fido const &fido);

#endif //FIDO_FIDO_H
