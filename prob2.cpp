#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

#define MAX_VALUE 4000000

class fibo_vector
{
    protected:
        std::vector<unsigned int> numbers;
        
    public:
        unsigned int tally;

        fibo_vector(unsigned int max)
        {
            numbers.push_back(1);
            numbers.push_back(2);

            unsigned int current = 0;

            while (current <= max)
            {
                if (current != 0)
                    numbers.push_back(current);
                    
                unsigned int last = (numbers.size() - 1);
                if (numbers[last] % 2 == 0)
                    this->tally += numbers[last];
                    
                current = numbers[last] + numbers[last - 1];
            }
            
        }
};
        
int main(int argc, char *argv[])
{    
    fibo_vector* vector = new fibo_vector(MAX_VALUE);

    std::cout << "Sum of even elts in fibonacci sequence of max "
    << MAX_VALUE << " is: " << vector->tally << std::endl;
    
    return 0;
}

