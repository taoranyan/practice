//
//  main.cpp
//  Anagrams
//
//  Created by Taoran on 9/13/13.
//  Copyright (c) 2013 Taoran. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> anagrams(vector<string> &strs) {
// Start typing your C/C++ solution below
// DO NOT write int main() function
map<string, int> mapApp;
map<string, string> pre;
vector<string> res;
int i;
for(i=0; i<strs.size(); ++i)
{
    string s=strs[i];
    sort(s.begin(), s.end());
    if(mapApp.find(s) == mapApp.end())
    {
        mapApp.insert(pair<string,int>(s,1));
        pre.insert(pair<string,string>(s,strs[i]));
    }
    else
    {
        mapApp[s]++;
        if(mapApp[s]==2) res.push_back(pre[s]);
            res.push_back(strs[i]);
            }
    }
    return res;
}


int main(int argc, const char * argv[])
{

    // insert code here...
    vector<string> s = {"a","acb","abc","ba","ab"};
    vector<string> res = anagrams(s);
    for(int i=0; i<res.size();++i)
    {
        cout << res[i]<<" "<<endl;
    }
    return 0;
}

