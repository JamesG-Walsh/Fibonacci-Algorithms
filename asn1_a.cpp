//CS3340      Winter 2021 Assignment 1
//James Walsh jwalsh57    250481718

#include "BigInt.h"

#include <iostream>
using namespace std;

class Fibonacci
{
    public:
        static unsigned long long fibA(int n)
        {
            if(n>1)
            {
                return fibA(n-1) + fibA(n-2);
            }
            else if(n==0 || n==1)
            {
                return n;
            }
            return -1; //error
        }

        /*static unsigned long long fibB(int n)
        { 
            if(n==0 || n==1)
            {
                return n;
            }
            long sum = 1;
            long prevA = 1;
            long prevB = 0;
            //long tmp =1;
            //long tmpB;
            for (long i = 2; i<=n ; i++)
            {
                //cout << "Start: For i=" << i << "\t sum=" << sum<< "\t prevA=" << prevA << "\t prevB=" << prevB << "\t tmp=" << tmp;
                //tmp = sum;
                sum = prevA + prevB;
                prevB = prevA;
                prevA = sum;
            }
            return sum;
        }*/
};

int main(int argc, char **argv)
{
    cout << "\nEntering main()\n";
    
    for(int i = 0; i <= 10; i++)
    {
        cout << "F(" << i*5 << ")\t= " << Fibonacci::fibA(i*5) << "\n";
    }

    cout << "\nProgram completed.\n\n";
}