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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode(0);
        ListNode * work_p = result;
        ListNode * n1 = l1;
        ListNode * n2 = l2;
        int count = 0;
        while( n1 || n2 || count){
            if( n1 && n2 ){
                work_p->next = new ListNode((n1->val + n2->val + count) % 10);
                count = (n1->val + n2->val + count) / 10;
                n1 = n1->next;
                n2 = n2->next;
                work_p = work_p->next;
            }else if(n1 || n2){
                ListNode * temp = (n1 == NULL)?n2:n1;
                work_p->next = new ListNode((temp->val + count) % 10);
                count = (temp->val + count) / 10;
                n1 = temp->next;
                n2 = NULL;
                work_p = work_p->next;                
            }else{
                work_p->next = new ListNode(count);
                count = 0;
            }
        }
        return result->next;
    }
};