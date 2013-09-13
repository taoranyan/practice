
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void partitionHelper(string s_str, int start, vector<vector<bool> > P, vector<string> chosen, vector<vector<string> >& res )
{
    if (s_str.length() == 0)
    {
        res.push_back(chosen);
        return;
    }
    else
    {
        for (int k =0; k<s_str.length(); ++k)
        {
            string s_str_0 = s_str.substr(0, k+1);

            if (P.at(start)[start+k])
            {
                chosen.push_back(s_str_0);
                
                string s_str_1 = s_str.substr(k+1);
                
                partitionHelper(s_str_1, start+(k+1), P, chosen, res);
                
                chosen.pop_back();
            }
        }
    }
    //cout << "res.size()= "<< res.size() << endl;

    return;
    
}
vector<vector<string>> partition(string s)
{
        int n = (int)s.length();
    
        vector<vector<bool> > P; //True if str[i..j] is palindrome
        
        int i,j;
        
        for (i= 0; i<n ; ++i)
        {
            vector<bool> temp;
            
            for (j=0; j<n; ++j)
            {
                if (i ==j)
                {
                    temp.push_back(true);
                }
                else
                {
                    temp.push_back(false);
                }
            }
            P.push_back(temp);
        }
    
        for(i = n-2; i>=0; --i)
        {
            vector<bool> temp_i = P.at(i);
            
            temp_i[i+1] = (s.at(i) == s.at(i+1));
            
            for (j = i+2; j<n; ++j)
            {
                
                vector<bool> temp_i_plus_1 = P.at(i+1);
               
                temp_i[j] = (s.at(i) == s.at(j)) && temp_i_plus_1[j-1];
                
                P.at(i+1) = temp_i_plus_1;
            }
            P.at(i) = temp_i;
        }
        
        vector<string> chosen;
        vector<vector<string> > res;
        
        partitionHelper(s, 0, P, chosen, res);
    
        return res;
}

int main()
{
    vector<vector<string> > result;

    result = partition ("abaa");
    
    cout <<"Result size: "<< result.size() << endl;
    
    int i, j;
    
    for (i =0; i<result.size(); ++i)
    {
        for (j=0; j<result[i].size(); ++j)
        {
            cout<< result[i][j] << " ";
        }
        cout << endl;
        
    }
    
    
    return 0;
}
