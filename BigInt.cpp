#include "BigInt.h"
#include <iostream>
#include <string>
//#include <ostringstream>

BigInt::BigInt(int value)
{
    std::cout << "\nin constructor";
    intValue = value;

    for(int i = 0; i < digitCapacity; i++)
    {
        digits[i] = 0; //initialize all digits to 0
    }

    std::string digitString = std::to_string(intValue);
    int digit;
    int stringSize = digitString.size();

    std::cout << "\nString Size: " << stringSize;
    std::cout << "\ns[0]: " << digitString[0];
    std::cout << "\n";

    for (int i = stringSize - 1, j=digitCapacity-1 ; 0 <= i ; i--, j--)
    {
        digits[j] = digitString[i] - '0';
    }
}

BigInt BigInt::add(BigInt operand1, BigInt operand2)
{
    BigInt sum = BigInt(0);
    bool carry = false;
    int digit1, digit2, digitSum;
    for(int i = sum.getDigitCapacity() - 1; 0<=i; i--)
    {
        digit1 = operand1.digits[i];
        digit2 = operand2.digits[i];
        digitSum = digit1 + digit2;

        if(carry)
        {
            digitSum += 1;
        }
        if (digitSum >= 10)
        {
            carry = true;
            sum.digits[i] = digitSum % 10;
        }
        else
        {
            carry = false;
            sum.digits[i] = digitSum;
        }
    }
    return sum;
}

void BigInt::printDigits()
{
    for (int i = 0; i < digitCapacity; i++)
    {
        std::cout << digits[i]; //TODO add commas
        /*if(i%3 == 0)
        {
            std::cout << ",";
        }*/
    }
}

int BigInt::getDigitCapacity()
{
    return digitCapacity;
}