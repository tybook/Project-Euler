#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstdint>
#include <cassert>

class number
{
    protected:
        int* num_array;
        int* rev_array;
        int length = 1;
            
    public:
        int is_palindrome = 1;
        
        number(int num)
        {
            // determines length of the number
            while (num >= pow(10, (double)length))
                length++;

            // init and zero arrays
            num_array = new int[length];
            rev_array = new int[length];
            for (int x = 0; x < length; x++)
            {
                num_array[x] = 0;
                rev_array[x] = 0;
            }

            // converts the number into an array of its component numbers
            int temp = num;
            for (int k = (length - 1); k >= 0; k--)
            {
                int current = (int)pow(10, (double)k);
                while (temp >= current)
                {
                    temp -= current;
                    num_array[(length - 1) - k] += 1;
                }
            }

            // creates a reversed version of that array
            for (int i = 0; i < length; i++)
                rev_array[i] = num_array[(length - 1) - i];

            // checks if the number is a palindrome by comparing arrays
            for (int j = 0; j < length; j++)
                if (num_array[j] != rev_array[j])
                    is_palindrome = 0;
        }

        ~number()
        {
            delete [] num_array;
            delete [] rev_array;
        }           
};
            
int main(int argc, char *argv[])
{    
    int largest = 0;
    
    for(int x = 100; x <= 999; x++)
        for(int y = 100; y <= 999; y++)
        {
            int prod = x * y;
            number input = number(prod);
            if(input.is_palindrome && (prod > largest))
                largest = prod;
        }
            
    std::cout << "The number " << largest << " is the largest palindrome found!" << std::endl;
    
    return 0;
}
    
