/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head -> next))
            return head;
        ListNode *p = head;
        ListNode *q = head -> next;
        
        while(q != NULL)
        {
            if (q -> val != p -> val)
            {
                p -> next = q;
                p = q;
                q = q -> next;
            }
            else
            {
                q = q -> next;
            }
            
        }
        p -> next = NULL;
        return head;
        
    }
};