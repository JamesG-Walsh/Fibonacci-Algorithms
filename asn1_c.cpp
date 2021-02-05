//CS3340      Winter 2021 Assignment 1
//James Walsh jwalsh57    250481718

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

        static BigInt fibB(int n, int printMultiple)
        { 
            cout << "\nF(0)\t= " << 0;
            if(printMultiple == 1)
            {
                cout << "\nF(1)\t= " << 1;
            }
            if(n==0 || n==1)
            {
                return BigInt(n);
            }                   
            BigInt sum = BigInt(1);
            BigInt prev1 = BigInt(1);
            BigInt prev2 = BigInt(0);
            for (int i = 2; i<=n ; i++)
            {
                sum = BigInt::add(prev1, prev2);
                prev2 = prev1;
                prev1 = sum;

                if(i % printMultiple == 0)
                {
                    cout << "\nF(" << i << ")\t= ";
                    sum.printDigits();
                }
            }
            return sum;
        }
};

int main(int argc, char **argv)
{
    cout << "\nEntering main()\n";

    //Fibonacci::fibB(20, 1);

    //Fibonacci::fibB(500, 20);

    //Fibonacci::fibB(500000, 50000);

    BigInt a = BigInt(2531);
    BigInt b = BigInt(1467);

    BigInt c = BigInt(0);
    //c = BigInt::multiply(a, b, c);
    c = BigInt::karatsuba(a, b, 1020, 1023);
    cout<<"\n Result: ";
    c.printDigits();

    cout << "\n\nProgram completed.\n\n";
    return 0;
}