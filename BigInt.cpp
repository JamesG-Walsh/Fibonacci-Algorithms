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

    for (int i = stringSize - 1, j=digitCapacity-1 ; 0 <= i ; i--, j--)
    {
        digits[j] = digitString[i] - '0';
    }
}

/*BigInt add(BigInt operand1, BigInt operand2)
{

}*/

void BigInt::printDigits()
{
    for (int i = 0; i < digitCapacity; i++)
    {
        std::cout << digits[i]; //TODO add commas
    }
}