#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <cassert>

int main(int argc, char *argv[])
{               
    uint64_t x = 0;
    int k = 1;

    while (1)
    {
        x++;
        
        while ((x % k == 0) && !(k > 20))
            k++;

        if (k > 20)
        {
            std::cout << "The number " << x << " is the smallest number divisible by 1-20!" << std::endl;
            return 0;
        }
        else
            k = 1;
    }
        
    return 0;
}
