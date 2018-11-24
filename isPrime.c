#include <stdio.h>
#include <stdbool.h>
#include <math.h>


//Returns "Segmentation fault: 11" with negative numbers
int isPrime(unsigned long long int number)
{
    if(number == 0 || number == 1 || number == 4)
        return 0;
    else if(number == 2 || number == 3 || number == 5)
        return 1;
    else if((number & (int)1) == (int)0) //Quick way to find if number is even or not by checking if the last bit is 0 or 1
        return 0;
    
    int size = sqrt(number / 2) + 1;
    unsigned long long int primes[size]; primes[0] = 2; primes[1] = 3;

    bool bPrime;
    int index = 1;
    for(int i = 6; i <= sqrt(number) + 1; i += 6)
    {
        //6x + 1
        bPrime = true;
        int numTemp = i + 1;
        for(int temp = 1; primes[temp] <= sqrt(numTemp); ++temp)
        {
            if(number % primes[temp] == 0)
            {
                bPrime = false;
                break;
            }
        }
        if(bPrime)
        {
            ++index;
            primes[index] = numTemp;
        }
        //6x - 1
        numTemp -= 2;
        bPrime = true;
        for(int temp = 1; primes[temp] <= sqrt(numTemp); ++temp)
        {
            if(number % primes[temp] == 0)
            {
                bPrime = false;
                break;
            }
        }
        if(bPrime)
        {
            ++index;
            primes[index] = numTemp;
        }

    }
    for(int i = 0; i <= index; ++i)
    {
        if(number % primes[i] == 0)
            return 0;
    }
    return 1;
}
