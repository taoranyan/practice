//
//  main.cpp
//  PlusOne
//
//  Created by Taoran on 9/13/13.
//  Copyright (c) 2013 Taoran. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int>:: iterator it = digits.begin();
    vector<int>:: reverse_iterator rit=digits.rbegin();
    if(it == digits.end()) return digits;
    int carry = 0;
    int q = (*rit + 1+ carry) %10;
    carry = (*rit + 1 + carry) /10;
    *rit = q;
    if(it+1 == digits.end())
    {  
       if(carry ==1)
       {
           digits.insert(it,carry);
           return digits;
       }
    }
    for (rit= digits.rbegin()+1; rit != digits.rend(); ++rit)
    {
        q = (*rit + carry) %10;
        carry = (*rit + carry) /10;
        *rit = q;
    }
    if(carry ==1)
    {
        digits.insert(it,carry);
    }
    return digits;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    vector<int> digits = {9};
    vector<int> res = plusOne(digits);
    for (int i=0; i<res.size(); ++i)
    {
        cout<<res.at(i)<<" ";
    }
    return 0;
}

