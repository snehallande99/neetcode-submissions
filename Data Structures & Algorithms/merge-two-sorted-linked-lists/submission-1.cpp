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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;

        if(list2 == nullptr)
            return list1;
            
        ListNode* list3=new ListNode(0);
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp3=list3;
        while(temp1!=nullptr && temp2!=nullptr)
        {
            if(temp1->val <= temp2->val)
            {
                temp3->val=temp1->val;
                temp1=temp1->next;
            }
            else
            {
                temp3->val=temp2->val;
                temp2=temp2->next;
            }
            if(temp1!=nullptr || temp2!=nullptr)
            {
                temp3->next = new ListNode(0);
                temp3 = temp3->next;
            }
        }
        while(temp1!=nullptr)
        {
            temp3->val=temp1->val;
            temp1=temp1->next;
            if(temp1!=nullptr)
            {
                temp3->next = new ListNode(0);
                temp3 = temp3->next;
            }
        }
        while(temp2!=nullptr)
        {
            temp3->val=temp2->val;
            temp2=temp2->next;
             if(temp2!=nullptr)
            {
                temp3->next = new ListNode(0);
                temp3 = temp3->next;
            }
        }

        return list3;
    }
};
