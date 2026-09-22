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
        if(start == end)
            return lists[start];

        int mid = start + (end - start) / 2;

        ListNode* r1 = divide(start, mid, lists);
        ListNode* r2 = divide(mid + 1, end, lists);

        return mergetwo(r1, r2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int n = lists.size();

        if(n == 0)
            return nullptr;

        return divide(0, n - 1, lists);
    }
};