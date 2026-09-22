/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int findl(ListNode* head)
    {
        int n=0;
        while(head!=nullptr)
        {
          n++;
          head=head->next;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int l=findl(head);
        int x=l-n+1;
       
        // if(n==1 && l==1)
        // {
        //     return nullptr;
        // }
        l=1;
        if(x==1)
        {
            return head->next;
        }
        while(l<x)
        {
          cout<<temp->val<<" ";
          if(x-l>1)
          {temp=temp->next;}

          l++;
        }
        ListNode* temp1=temp;
        temp=temp->next;
        temp1->next=temp->next;
        temp->next=nullptr;
        return head;
    }
};
