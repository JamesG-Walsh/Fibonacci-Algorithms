#ifndef BIGINT_H
#define BIGINT_H

class BigInt
{
    protected:
        int intValue;
        int digitCapacity = 110; //big enough for Fibonacci(500), can easily be adjusted higher
        int digits[120];
        
        void populateDigits();

    public:
        //BigInt();
        BigInt(int value);
        //BigInt(BigInt v1, BigInt v2)

        BigInt add (BigInt operand1, BigInt operand2);
        void printDigits();
};

#endif