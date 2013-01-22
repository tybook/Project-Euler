using namespace std;
#include <iostream>
#include <cmath>
#include <cstdlib>

#define LISTLENGTH 1000

class list
{
public:

    int *a;
    list()
    {
        a = new int[LISTLENGTH];
        for (int k = 0; k < LISTLENGTH; k++)
            a[k] = k;
    }

    ~list()
    {
        delete [] a;
    }
};
            
int main (int argc, char *argv[])
{    
    list numbers;
    int tally = 0;
    
    for (int j = 0; j < LISTLENGTH; j++)
        if ((numbers.a[j] % 3 == 0) || (numbers.a[j] % 5 == 0))
            tally += numbers.a[j];

    cout << "Sum of list items divisible by 3 and/or 5 in a list of size "
    << LISTLENGTH << " is: " << tally << endl;
    
    return 0;
}

