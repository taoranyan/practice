//
//  main.cpp
//  inorder_traversal
//
//  Created by Taoran on 9/12/13.
//  Copyright (c) 2013 Taoran. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helperFunction(queue<TreeNode*> myQueue, vector<int> chosen, vector<vector<int>>& res)
{
    if(myQueue.empty()) return;
    queue<TreeNode*> nextQueue;
    int i=0;
    while(!myQueue.empty())
    {
        TreeNode *node = myQueue.front();
        myQueue.pop();
        chosen.push_back(node->val);
        i++;
        
        if(node->left !=NULL) nextQueue.push(node->left);
        if(node->right !=NULL) nextQueue.push(node->right);
    }
    res.push_back(chosen);
    while(i != 0)
    {
        chosen.pop_back();
        i--;
    }
    helperFunction(nextQueue, chosen, res);

    return;
}

vector<vector<int> > levelOrder(TreeNode *root)
{
    vector<int> chosen;
    vector<vector<int>> res;
    if(root==NULL) return res;
    queue<TreeNode* > myQueue;
    chosen.push_back(root->val);
    res.push_back(chosen);
    if(root->left !=NULL) myQueue.push(root->left);
    if(root->right !=NULL) myQueue.push(root->right);
    chosen.pop_back();
    helperFunction(myQueue, chosen, res);
    return res;
}
int main(int argc, const char * argv[])
{

    // insert code here...
    TreeNode *num_1 = new TreeNode(1);
    TreeNode *num_2 = new TreeNode(2);
    TreeNode *num_3 = new TreeNode(3);
    TreeNode *num_4 = new TreeNode(4);
    TreeNode *num_5 = new TreeNode(5);
    TreeNode *num_6 = new TreeNode(6);
    TreeNode *num_7 = new TreeNode(7);
    vector<vector<int>> res;

    
    num_1->left = num_2;
    num_1->right = num_3;
    num_2->left = num_4;
    num_2->right = num_5;
    num_3->left = num_6;
    num_3->right = num_7;
    
    res = levelOrder(num_1);
    int i, j;
    for(i=0; i<res.size(); ++i)
    {
        for(j=0; j<res[i].size(); ++j)
        {
            cout<< res[i].at(j)<< " ";
        }
        cout<< endl;
    }
    
    return 0;
}

