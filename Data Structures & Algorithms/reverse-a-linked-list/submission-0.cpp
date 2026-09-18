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
    ListNode* reverseList(ListNode* head) {
           if(head == nullptr)
            {
                return nullptr;
            }

            if(head->next == nullptr)
            {
                return head;
            }
        
        ListNode* temp = new ListNode(0);
        ListNode* temp1=head->next;
        head->next=nullptr;
        temp->val=0;
        temp->next=head;

        while(temp1!=nullptr)
        {
           ListNode* temp2=temp1;
           temp1=temp1->next;
           temp2->next=temp->next;
           temp->next=temp2;
        }

        return temp->next;
    }
};
