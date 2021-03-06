/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*

Program to sort the Linked List in grps of k
A good example of LOOPED RECURSION ( loop + recursion )

1->2->3->4->5, k = 3

1->2->1->4->5

Think about this in reversing the list of first k elements and then recursively call on the rest of the LL

*/

class Solution {
public:
    
    
    ListNode* reverse(ListNode* curr, ListNode* pre) {
        if ( curr == NULL ) return pre;
        ListNode* tmp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = tmp;
        return reverse(curr, pre);
        // ok good for reversing the whole list revursively
    }
    
    ListNode* rev(ListNode* head) {
        ListNode* curr = head;
        ListNode* pre = NULL;
        while ( curr != NULL ) {
            
            ListNode* tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
            
        }
        head = pre;
        return head;
        // ok good for reversing a linked list iteratively
    }
    
    int len(ListNode* head, int k) {
        int l = 0;
        while(head != NULL ) {
            head = head->next;
            l++;
        }
        return l < k;
        // utility fn to check whether list can be reversed or not, if less than k then leave it!
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // main code
        if ( len( head , k ) ) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* pre = NULL;
        int tmpk = k;
        while ( tmpk ) {
            tmpk--;
            ListNode* tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        head->next = reverseKGroup(curr, k);
        head = pre;
        return head;
        
        
    }
};