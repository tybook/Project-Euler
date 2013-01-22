#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <cassert>

class primes_list
{
    protected:
        int* list;
        int size = 0;
        int upper = 10;

    public:
        int nth_prime;

        primes_list(int n)
        {
            while (1)
            {
                upper *= 10;

                list = new int[upper + 1];

                for (int k = 0; k <= upper; k++)
                {
                    if (k == 1)
                        list[k] = 0;
                    else
                        list[k] = k;
                }

                for (int p = 2; p <= upper; p++)
                    for (int j = p + p; j <= upper; j += p)
                        list[j] = 0;
                    
                for (int i = 0; i <= upper; i++)
                    if (list[i] != 0)
                    {
                        list[size] = list[i];
                        size++;
                    }

                if (size < n)
                {
                    size = 0;
                    delete list;
                }
                else
                    break;
            }
            nth_prime = list[n - 1];
        }

        ~primes_list()
        {
            delete list;
        }
};        

int main(int argc, char *argv[])
{               
    primes_list foo = primes_list(10001);
    std::cout << foo.nth_prime << std::endl;
    return 0;
}
