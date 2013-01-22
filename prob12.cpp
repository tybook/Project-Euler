#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <cassert>

#define TARGET 500

int main(int argc, char *argv[])
{               
  uint64_t current;
  int divisors;
  for(int j = 1; 1; j++)
  {
    current = (j * (j + 1)) / 2;
    divisors = 0;
    for (uint64_t k = 2; k <= sqrt(current); k++)
      if (current % k == 0)
        divisors += 2;
    if (divisors >= TARGET)
      break;
  }
  
  std::cout << current << std::endl;

  return 0;
}

    
    
    
