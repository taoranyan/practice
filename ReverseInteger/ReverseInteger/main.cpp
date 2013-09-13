//
//  main.cpp
//  ReverseInteger
//
//  Created by Taoran on 9/13/13.
//  Copyright (c) 2013 Taoran. All rights reserved.
//

#include <iostream>
using namespace std;


int reverse(int x) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    bool ifpos = true;
    if (x<0)
    {
        ifpos =false;
        x= -x;
        
    }
    int res=0;
    while (x/10!=0){
        res = res + x%10;
        res =res*10;
        x /= 10;
    }
    res = res+x;
    if (ifpos==false)
    {
        return -res;
        
    }
    else
    {
        return res;
        
    }
}

int main(int argc, const char * argv[])
{

    int a = -123;
    int b = reverse(a);
    cout<< "b= "<<b<<endl;
    return 0;
}

