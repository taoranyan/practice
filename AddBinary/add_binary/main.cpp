//
//  main.cpp
//  add_binary
//
//  Created by Taoran on 9/12/13.
//  Copyright (c) 2013 Taoran. All rights reserved.
//

#include <iostream>

using namespace std;

string addBinary(string a, string b) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(a.length() == 0) return b;
    if(b.length() == 0) return a;
    int la = (int)a.length()-1;
    int lb = (int)b.length()-1;
    int c=0;
    int value_1=0;
    int value_2=0;
    int q=0;
    string res="";
    
    while(la>=0 || lb>=0 || c>0)
    {
        //cout << "c= "<< c <<endl;
        if(la >=0)
        {
            value_1 = a.at(la);

        }
        else
        {
            value_1 = '0';
        }
        if(lb >=0)
        {
            value_2 = b.at(lb);

        }
        else
        {
            value_2 = '0';
        }
        q = (value_1 -'0' + value_2 -'0' + c)%2;
        c = (value_1 -'0' + value_2 -'0' + c)/2;


        res = string(1,'0'+q) + res;


        la--;
        lb--;
        
    }
    
    return res;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    string a = "1";
    string b = "1";
    string res = addBinary(a,b);
    cout << "res= "<<res<<endl;
    return 0;
}

