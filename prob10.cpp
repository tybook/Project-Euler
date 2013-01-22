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

typedef struct
{
  primes_list* list;
  int start;
  uint64_t* result;
} p_args;

int main(int argc, char *argv[])
{
  primes_list primes = primes_list(2000000);
  uint64_t sum1, sum2 = 0;
  int halfway = primes.size / 2;

  pthread_t tid;
  p_args args = { &primes, halfway, &sum2 };
  pthread_create(&tid, NULL, sum_thread, &args);
  
  for (int k = 0; k < halfway; k++)
      sum1 += primes.list[k];

  pthread_join(tid, NULL);

  std::cout << sum1 + sum2 << std::endl;
  return 0;
}

void *sum_thread(void *x)
{
  p_args args = *(p_args*)x;
  for (int k = args.start; k < args.list->size; k++)
      *args.result += args.list->list[k];
  return NULL;
}
