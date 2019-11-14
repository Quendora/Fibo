#include <iostream>
#include "Fibo.h"

int main()
{
  Fibo a(4);
  Fibo b("000000000000011");
  a = b;
  a = 1;
  a += b;
  std::cerr << a;
}