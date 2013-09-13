//
//  main.cpp
//  add_two_numbers
//
//  Created by Taoran on 9/12/13.
//  Copyright (c) 2013 Taoran. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *temp1, *temp2, *head, *head1, *first;
    ListNode *res = new ListNode(0);
    temp1 = l1;
    temp2 = l2;
    head = res;
    head1 = res;
    first = res;
    int c = 0;
    int q = 0;
    int value_1, value_2;
    if(temp1 == NULL) return temp2;
    if(temp2 == NULL) return temp1;
    do
    {
        ListNode *resNew = new ListNode(0);
        if(temp1 != NULL)
        {
            value_1 = temp1->val;
        }
        else
        {
            value_1 = 0;
        }
        if(temp2 !=NULL)
        {
            value_2 = temp2->val;
        }
        else
        {
            value_2 = 0;
        }
        q = (value_1 + value_2 + c)%10;
        c = (value_1 + value_2 + c)/10;
        resNew->val = q;
        if(temp1 !=NULL) temp1 = temp1->next;
        if(temp2 !=NULL) temp2 = temp2->next;
        head->next = resNew;
        head = resNew;


    }
    while(temp1 !=NULL || temp2 !=NULL || c>0);

    head1 = head1 ->next;
    first->next = NULL;
    return head1;
        
}


int main(int argc, const char * argv[])
{

    // insert code here...
    ListNode *num_1 = new ListNode(5);
    //ListNode *num_2 = new ListNode(4);
    //ListNode *num_3 = new ListNode(3);
    ListNode *num_4 = new ListNode(5);
    //ListNode *num_5 = new ListNode(6);
    //ListNode *num_6 = new ListNode(4);
    ListNode *res = new ListNode(0);

    //num_1->next = num_2;
    //num_2->next = num_3;
    //num_4->next = num_5;
    //num_5->next = num_6;
 
    res = addTwoNumbers(num_1, num_4);
    while(res!=NULL)
    {
        cout << res->val<<" "<<endl;
        res = res->next;
    }
    return 0;
}

