//
//  CBigInteger.hpp
//  BigInteger
//
//  Created by Evgeny on 13.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#ifndef CBigInteger_hpp
#define CBigInteger_hpp

#include <stdio.h>
#include <iostream>

class BigInteger
{
public:
    BigInteger(char* a = new char [0]);
    BigInteger (const BigInteger& );
    friend std:: ostream& operator << (std:: ostream& , const BigInteger& );
    friend std:: istream& operator >> (std:: istream& , BigInteger& );
    BigInteger& operator = (const BigInteger& );
    BigInteger operator + (const BigInteger& ) const;
    ~BigInteger();
private:
    char* a;
    unsigned long size;
    char* FindOnlyNumbers(char* );
};
std:: ostream& operator << (std:: ostream& , const BigInteger& );
std:: istream& operator >> (std:: istream& , BigInteger& );
#endif /* CBigInteger_hpp */
