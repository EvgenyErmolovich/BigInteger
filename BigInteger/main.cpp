//
//  main.cpp
//  BigInteger
//
//  Created by Evgeny on 13.04.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include <iostream>
#include "CBigInteger.hpp"

using namespace std;

int main()
{
    BigInteger bi;
    cout << "enter your number: " << endl;
    cin >> bi;
    cout << "your number: " << endl;
    cout << bi << endl;
    BigInteger bi2;
    cout << "enter your number: " << endl;
    cin >> bi2;
    cout << "your number: " << endl;
    cout << bi2 << endl;
    cout << "Sum: " << endl;
    cout << bi + bi2 << endl;
    return 0;
}
