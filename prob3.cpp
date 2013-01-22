#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <cassert>

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
            {
                if (list[i] != 0)
                {
                    list[size] = list[i];
                    size++;
                }
            }
        }

        ~primes_list()
        {
            delete list;
        }
};
            
int main(int argc, char *argv[])
{    
    uint64_t input = atoll(argv[1]);
    uint64_t max;
    primes_list* primes = new primes_list(10000);
    
    for (int k = 0; k < primes->size; k++)
    {
        uint64_t current = primes->list[k];
        while (input % current == 0)
        {
            input /= current;
            max = current;
        }
    }

    assert(input == 1);

    std::cout << "Largest prime factor of number " << argv[1] << " is: " << max << std::endl;
    
    return 0;
}
    

