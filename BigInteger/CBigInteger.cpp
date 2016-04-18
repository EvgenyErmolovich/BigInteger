//
//  CBigInteger.cpp
//  BigInteger
//
//  Created by Evgeny on 13.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include <iostream>
#include "CBigInteger.hpp"

const int N = 256;

BigInteger :: BigInteger(char* b)
{
    char* str = FindOnlyNumbers(b);
    if (strlen(str) > N) size = 1;
    else size = strlen(str);
    a = new char [size];
    for (int i = 0; i < size; i++)
    {
        a[i] = str[i];
    }
}
BigInteger :: ~BigInteger()
{
    delete[] a;
}
BigInteger :: BigInteger (const BigInteger& bi2)
{
    size = bi2.size;
    a = new char [size];
    for (int i = 0; i < size; i++)
        a[i] = bi2.a[i];
}
BigInteger& BigInteger :: operator = (const BigInteger& bi2)
{
    if(this != &bi2)
    {
        size = bi2.size;
        delete[] a;
        a = new char [size];
        for (int i = 0; i < size; i++)
            a[i] = bi2.a[i];
    }
    return *this;
}
std:: istream& operator >> (std:: istream& in, BigInteger& bi)
{
    char* str = new char[N];
    in.getline(str,N);
    bi = BigInteger(str);
    return in;
}
std:: ostream& operator << (std:: ostream& out, const BigInteger& bi)
{
    for (int i = 0; i < bi.size; i++)
        out << bi.a[i];
    return out;
}
char* BigInteger :: FindOnlyNumbers(char* str)
{
    unsigned long n = strlen(str);
    char* b = new char [n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
        {
            b[j] = str[i];
            j++;
        }
    }
    size = j;
    return b;
}
BigInteger BigInteger :: operator + (const BigInteger& bi2) const
{
    unsigned long n = 0;
    unsigned long h = 0;
    if (size >= bi2.size) {n = size; h = size - bi2.size;}
    else {n = bi2.size; h = bi2.size - size;}
    char* sum = new char [n];
    for (int i = 0; i < n; i++)
    {
        sum[i] = '0';
    }
    char* b = new char [n];
    for (int i = 0; i < n; i++)
    {
        b[i] = '0';
    }
    if (size >= bi2.size)
    {
        for (int i = 0; i < n; i++)
            sum[i] = a[i];
        for (int i = 0; h < n; i++,h++)
            b[h] = bi2.a[i];
    }
    else
    {
        for (int i = 0; i < n; i++)
            sum[i] = bi2.a[i];
        for (int i = 0; h < n; i++,h++)
            b[h] = a[i];
    }
    for (int i = static_cast<int>(n) - 1; i >= 0; i--)
    {
        sum[i] = (sum[i]-'0') + (b[i]-'0') + '0';
        if (sum[0] > '9')
        {
            char* Sum = new char [n+1];
            for (int i = 0; i < n+1; i++)
            {
                Sum[i] = '0';
            }
            sum[0] = (sum[0]-'0')%10+'0';
            Sum[0] = Sum[0]-'0' + 1 + '0';
            for (int i = 0, j = 1; i < n; i++, j++)
            {
                Sum[j] = sum[i];
            }
            delete[] b;
            delete[] sum;
            return BigInteger(Sum);
        }
        if (sum[i] > '9')
        {
            sum[i] = (sum[i]-'0')%10+'0';
            sum[i-1] = ((sum[i-1]-'0')+1)+'0';
        }
    }
    delete[] b;
    return BigInteger(sum);
}