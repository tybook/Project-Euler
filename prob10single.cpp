#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <pthread.h>

#define MAX 998

void *sum_thread(void *p_args);

class primes_list
{
  public:
    uint64_t* list;
    int size;

    primes_list(uint64_t upper = 100)
    {
      list = new uint64_t[upper + 1];
      
      for (uint64_t k = 0; k <= upper; k++)
      {
        if (k == 1)
            list[k] = 0;
        else
            list[k] = k;
      }

      for (uint64_t p = 2; p <= upper; p++)
        for (uint64_t j = p + p; j <= upper; j += p)
          list[j] = 0;
          
      for (uint64_t i = 0; i <= upper; i++)
        if (list[i] != 0)
        {
          list[size] = list[i];
          size++;
        }
    }

    ~primes_list()
    {
      delete list;
    }
};

int main(int argc, char *argv[])
{
  primes_list primes = primes_list(2000000);
  uint64_t sum = 0;

  for (int k = 0; k < primes.size; k++)
      sum += primes.list[k];

  std::cout << sum << std::endl;
  return 0;
}
