/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergetwo(ListNode* a, ListNode* b)
{
    if(a == nullptr)
        return b;

    if(b == nullptr)
        return a;

    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    while(a != nullptr && b != nullptr)
    {
        if(a->val < b->val)
        {
            temp->next = a;
            a = a->next;
        }
        else
        {
            temp->next = b;
            b = b->next;
        }

        temp = temp->next;
    }

    if(a != nullptr)
        temp->next = a;

    if(b != nullptr)
        temp->next = b;

    return dummy->next;
}
ListNode* divide(int start, int end, vector<ListNode*>& lists)
        {
            ListNode* r1=nullptr;
            ListNode* r2=nullptr;
            ListNode* result=nullptr;
            if(end==start)
            {
                return lists[start];
            }
            if(end-start==1)
            {
                result=mergetwo(lists[start],lists[end]);
                return result;
            }
            else{
            int mid = start + (end - start) / 2;
            r1=divide(start,mid,lists);
            r2=divide(mid+1,end,lists);
            result=mergetwo(r1,r2);
            return result;
            }
            
        }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode* result=new ListNode(0,nullptr);
        ListNode* r1=nullptr;
        ListNode* r2=nullptr;
        if(n==0)
        {
            return nullptr;
        }
       
        return divide(0, n-1, lists);
    }
};
