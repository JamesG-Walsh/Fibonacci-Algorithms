//CS3340      Winter 2021 Assignment 1
//James Walsh jwalsh57    250481718

#ifndef BIGINT_H
#define BIGINT_H

class BigInt
{
    protected:
        int intValue;
        int digitCapacity = 21000; //big enough for Fibonacci(500), can easily be adjusted higher.  Should keep as power of 2 for simplicity of karasuba
        int digits[21000]; //std::vector<int> might be better as it would dynamically scale to the needed size.  Or abandon decimal entirely and just use binary...would need to be able to translate back to decimal...

        void populateDigits();

    public:
        //BigInt();
        BigInt();
        BigInt(int value);
        //BigInt(BigInt v1, BigInt v2)

        int getDigitCapacity();
        void setDigit(int index, int value);

        BigInt static add(BigInt operand1, BigInt operand2);
        BigInt static multiply(BigInt factor1, BigInt factor2, BigInt product);
        BigInt static karatsuba(BigInt factor1, BigInt factor2, int p, int r);
        BigInt static subtract(BigInt op1, BigInt op2);
        void printDigits();

};

#endif
