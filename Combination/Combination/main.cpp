//
//  main.cpp
//  Combination
//
//  Created by Taoran on 9/12/13.
//  Copyright (c) 2013 Taoran. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void combineHelper(int n, int k, int start, vector<int> temp, vector<vector<int>>& res)
{
    if(temp.size() == k)
    {
        res.push_back(temp);
        return;
    }
    int i;
    for(i=start; i<=n; ++i)
    {
        temp.push_back(i);
        combineHelper(n, k, i+1, temp, res);
        temp.pop_back();
    }
    return;
}

vector<vector<int> > combine(int n, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> temp;
    vector<vector<int>> res;
    combineHelper(n, k, 1, temp, res);
    
    return res;
}

int main(int argc, const char * argv[])
{


    vector<vector<int>> res = combine(4,2);
    int i,j;
    for(i=0; i<res.size(); ++i)
    {
        for(j=0; j<res[i].size(); ++j)
        {
            cout << res[i].at(j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}

