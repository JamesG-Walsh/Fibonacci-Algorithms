//CS3340      Winter 2021 Assignment 1
//James Walsh jwalsh57    250481718

#include "BigInt.h"

#include <string>
#include <iostream>
using namespace std;
//#include <ostringstream>

BigInt::BigInt()
{
    //std::std::cout << "\nin constructor";
    intValue = 0;

    for(int i = 0; i < digitCapacity; i++)
    {
        digits[i] = 0; //initialize all digits to 0
    }
}

BigInt::BigInt(int value)
{
    //std::std::cout << "\nin constructor";
    intValue = value;

    for(int i = 0; i < digitCapacity; i++)
    {
        digits[i] = 0; //initialize all digits to 0
    }

    std::string digitString = std::to_string(intValue);
    int digit;
    int stringSize = digitString.size();

    //std::std::cout << "\nString Size: " << stringSize;
    //std::std::cout << "\ns[0]: " << digitString[0];
    //std::std::cout << "\n";

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

//doesn't work...
//trying karatsuba
BigInt BigInt::multiply(BigInt factor1, BigInt factor2, BigInt product)//maybe pass product by reference
{
/*    //BigInt product = BigInt(0);
     unsigned short int carry = 0;
    unsigned short int digit1, digit2, digitProd;
    for(int i = product.getDigitCapacity() - 1; 0<=i ; i--)
    {
        digit1 = factor1.digits[i];
        digit2 = factor2.digits[i];
        
        digitProd = digit1*digit2;
        digitProd += carry;
        carry = 0;

        if(digitProd >= 10)
        {
            product.digits[i] = digitProd % 10;
            carry += digitProd / 10;
        }
        else
        {
            product.digits[i] = digitProd;
        }
    }
    return product; */


    return BigInt(420);
}

/*  Implements Anatoly Karatsuba's divide and conquer recursive algorithm for multiplication
    p is lowest index, r is max index of subproblem.  Not fully debugged,*/
BigInt BigInt::karatsuba(BigInt factor1, BigInt factor2, int p, int r)
{
    //BigInt b, c, e1, e2, e, f, g;
    std::cout << "\nEntering karatsuba";
    std::cout << "\trec f1: ";
    factor1.printDigits();
    std::cout << "\trec f2: ";
    factor2.printDigits();
    std::cout << "\tp: " << p << "\tr: " << r;

    if(r-p==1)
    {
        std::cout << "\tbase branch";
        int b = factor1.digits[p]*factor2.digits[p]; //multiply the tens
        //std::cout << "\nb: " << b;
        int c = factor1.digits[r]*factor2.digits[r]; //multiply the ones
        //std::cout << "\nc: " << c;

        int e1 = factor1.digits[p] + factor1.digits[r];
        //std::cout << "\ne1: " << e1;
        int e2 = factor2.digits[p] + factor2.digits[r];
        //std::cout << "\ne2: " << e2;

        int e = (e1) * (e2) ;//multiply the sums
        //std::cout << "\ne: " << e;

        int f = e-b-c;
        //std::cout << "\nf: " << f;

        int g = 100*b+10*f+c;
        std::cout << "\nBase g: " << g;

        return BigInt(100*b+10*f+c);
    }
    else if(r-p>1) //recursion
    {
        std::cout << "\trecursive branch";
        int q = (p+r)/2;
        std::cout << "\nq: " << q;

        int digCap = factor1.getDigitCapacity(); //TODO maybe remove and get maxIndex w/o storing digCap
        int maxIndex = digCap - 1;
        int range = (r-p);
        int maxLeft = range/2;
        int minRight = maxLeft + 1;

        /* code */
        BigInt b = karatsuba(factor1, factor2, p, q);
        std::cout << "\nrec b: ";
        b.printDigits();

        BigInt c = karatsuba(factor1, factor2, q+1, r);
        std::cout << "\nrec c: ";
        c.printDigits();

        BigInt factor1LeftHalf, factor2LeftHalf, factor1RightHalf, factor2RightHalf;
        for (int i = p, j=maxIndex-maxLeft; i <= p+maxLeft; i++, j++)
        {
            std::cout << "\ni: " << i << "\tj: " << j;
            factor1LeftHalf.setDigit(j, factor1.digits[i]);
            factor2LeftHalf.setDigit(j, factor2.digits[i]);
        }
        std::cout << "\nrec f1lh: ";
        factor1LeftHalf.printDigits();
        std::cout << "\nrec f2lh: ";
        factor2LeftHalf.printDigits();
        
        int dstI;
        std::cout << "\nminRight: " << minRight;
        std::cout << "\n q" << q;
        for(int srcI = q+1, dstI = q+1; srcI <= r ; srcI++, dstI++)
        {
            std::cout << "\nsrcI: " << srcI << "\tdstI: " << dstI;
            factor1RightHalf.setDigit(dstI , factor1.digits[srcI]);
            factor2RightHalf.setDigit(dstI , factor2.digits[srcI]);
        }
        std::cout << "\nrec f1rh: ";
        factor1RightHalf.printDigits();
        std::cout << "\nrec f2rh: ";
        factor2RightHalf.printDigits();

        BigInt d1 = BigInt::add(factor1LeftHalf, factor1RightHalf);
        std::cout << "\nrec d1: ";
        d1.printDigits();
        BigInt d2 = BigInt::add(factor2LeftHalf, factor2RightHalf);
        std::cout << "\nrec d2: ";
        d2.printDigits();

        BigInt e;
        if (d1.digits[p+maxLeft] == 0)
        {
            std::cout << "\nno overflow";
            e = BigInt::karatsuba(d1, d2, q+1, r);
        }
        else
        {
            std::cout << "\nyes overflow";
            e = BigInt::karatsuba(d1, d2, q, r);
        }
        
        BigInt ftmp = BigInt::add(b, c);
        BigInt f = BigInt::subtract(e,ftmp);
        std::cout << "\nrec f: ";
        f.printDigits();


        BigInt g;
        int gDig;
        gDig = c.digits[maxIndex];
        g.digits[maxIndex] = gDig;
        std::cout << "\ngDig: " << gDig;

        gDig = c.digits[maxIndex-1];
        g.digits[maxIndex-1] = gDig;
        std::cout << "\ngDig: " << gDig;

        bool carry = false;

        gDig = c.digits[maxIndex-2]+f.digits[maxIndex];
        if(gDig >= 10)
        {
            g.digits[maxIndex-2] = gDig%10;
            carry = true;
        }
        else
        {
            g.digits[maxIndex-2] = gDig%10;
            carry = false;
        }
        std::cout << "\ngDig: " << gDig;

        gDig = c.digits[maxIndex-3]+f.digits[maxIndex-1];
        if(carry)
        {
            gDig+=1;
        }
        if(gDig >= 10)
        {
            g.digits[maxIndex-3] = gDig%10;
            carry = true;
        }
        else
        {
            g.digits[maxIndex-3] = gDig%10;
            carry = false;
        }
        std::cout << "\ngDig: " << gDig;

        for(int i = (maxIndex-4); 0<=i ; i--)
        {
            gDig = c.digits[i]+f.digits[i+2]+b.digits[i+4];
            if(carry)
            {
                gDig += 1;
            }
            if (gDig >= 10)
            {
                g.digits[i] = gDig%10;
                carry = true;
            }
            else
            {
                g.digits[i] = gDig;
                carry = false;
            }
        }

        std::cout << "\nReturning g: ";
        g.printDigits();
        return g;
    }
    else if(r==p)
    {
        std::cout << "\n1 digit range";
        
        int retDig = factor1.digits[p] * factor2.digits[p];

        BigInt ret = BigInt(retDig);

        return ret;
    }
    else
    {
        cout << "\nERROR!  range < 0 ?";  //throw exception?
    }
}

/*subtracts op2 from op1*/
BigInt BigInt::subtract(BigInt op1, BigInt op2)
{
    BigInt diff;
    int dig1, dig2;
    bool carry = false;
    for (int i = (op1.getDigitCapacity()-1); 0<=i ; i--)
    {
        dig1 = op1.digits[i];
        dig2 = op2.digits[i];

        if(carry)
        {
            dig1-=1;
        }
        if(dig1 >= dig2)
        {
            diff.digits[i] = (dig1-dig2);
            carry = false;
        }
        else
        {
            diff.digits[i] = (dig1+10-dig2);
            carry = true;
        }
    }
    return diff;
}

void BigInt::printDigits()
{
    bool startPrinting = false;

    for (int i = 0; i < digitCapacity; i++)
    {
        if (digits[i] != 0)
        {
            startPrinting = true; //only start printing after iterating through leading 0s
        }
        if(startPrinting)
        {
            std::cout << digits[i];
            if((digitCapacity-1-i)%3 == 0 && i < digitCapacity-1)
            {
                std::cout << ",";
            }
        }
    }
}

int BigInt::getDigitCapacity()
{
    return digitCapacity;
}

void BigInt::setDigit(int index, int value)
{
    this->digits[index] = value;
}