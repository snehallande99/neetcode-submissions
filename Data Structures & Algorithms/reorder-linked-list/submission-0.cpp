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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp1=head;
        ListNode* temp2=head;
       
        while(temp->next!=nullptr && temp->next->next!=nullptr)
        {
           while(temp1->next!=nullptr)
           {
            temp2=temp1;
            temp1=temp1->next;
           }

        temp1->next=temp->next;
        temp->next=temp1;
        temp2->next=nullptr;
        temp=temp->next->next;
        }
    }
};
