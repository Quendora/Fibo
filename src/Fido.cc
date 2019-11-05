//
// Created by Karolina Zygmunt and Krystian Król on 04.11.19.
//

#include "Fido.h"

std::string Fido::ToString() const  {

  return "Here we should output string representing number\nP.S. Dont worry it's just sample output";
}

std::ostream &operator<<(std::ostream &os, Fido const &fido) {

  return os << fido.ToString(); //FIXME: This is temporary as it may be inefficient
}