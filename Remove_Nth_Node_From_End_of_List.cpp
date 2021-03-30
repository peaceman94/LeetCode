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
    int getLength(ListNode* head)
    {
        if(head == nullptr) return 0;
        return getLength(head->next) +1;
    }
    
    void helper(int target, int curr_depth, ListNode* &PrevNode, ListNode* &CurrNode)
    {
        if(CurrNode == nullptr) return;
        if(curr_depth == target )
        {
            PrevNode->next = CurrNode->next;
            return;
        };
        
        helper( target, curr_depth + 1, CurrNode, CurrNode->next);
        return;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        
        if(len - n + 1 == 1) return head->next;
        helper( len-n+1, 2, head, head->next);
        return head;
    }
};
