#include <iostream>
#include "Fibo.h"

int main()
{
  Fibo a(1);
  Fibo b(5);
  a+=b;
  std::cerr << a;
}