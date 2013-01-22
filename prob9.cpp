#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <cassert>

#define MAX 998

int main(int argc, char *argv[])
{
  for (int a = 1; a <= MAX; a++)
    for (int b = a; b <= MAX; b++)
    {
      int c = 1000 - b - a;
      if ((pow(a, 2) + pow(b, 2) == pow(c, 2)))
      {
        std::cout << a * b * c << std::endl;
        return 0;
      }
    }    
}
