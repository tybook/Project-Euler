#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <cassert>

class sequence
{
    public:
        int sum_of_squares = 0;
        int square_of_sum = 0;
        int difference;
        
        sequence(int max)
        {
            for (int k = 1; k <= max; k++)
                sum_of_squares += pow((double)k, 2);
            for (int k = 1; k <= max; k++)
                square_of_sum += k;
            square_of_sum = pow((double)square_of_sum, 2);
            difference = square_of_sum - sum_of_squares;
        }
};        

int main(int argc, char *argv[])
{               
    sequence input = sequence(100);
    std::cout << input.difference << std::endl;
    return 0;
}
