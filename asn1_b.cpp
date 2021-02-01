#include "BigInt.h"

#include <iostream>
using namespace std;

class Fibonacci
{
    public:
        static long fibA(int n)
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

        static unsigned long long fibB(int n)
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
            return prevA;
        }
};

int main(int argc, char **argv)
{
    cout << "\nEntering main()";
    /*
    for(int i = 0; i <= 8; i++)
    {
        //cout << "F(" << i*5 << ")\t= " << Fibonacci::fibA(i*5) << "\n";
    }

    cout << "\n";

    for(int i = 0; i<100; i++)
    {
        //cout << "F(" << i << ")\t= " << Fibonacci::fibB(i) << "\n";
    }

    cout << "\n";

    for(int i = 0; i <= 25; i++)
    {
        //cout << "F(" << i*20 << ")\t= " << Fibonacci::fibB(i*20) << "\n";
    }*/
    
    cout << "\ncalling constructor...";
    BigInt bi1 = BigInt(34500);
    BigInt bi2 = BigInt(12345);
    cout << "\nPrinting Digits...\n";
    bi1.printDigits();
    bi2.printDigits();

    //BigInt bi3 = BigInt::add(bi1, bi2);
    //bi3.printDigits();

    cout << "\nProgram completed.\n\n";
}