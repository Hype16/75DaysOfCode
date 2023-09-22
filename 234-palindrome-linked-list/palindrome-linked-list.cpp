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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = slow -> next;

        while(fast != NULL && fast->next !=NULL){
            fast = fast ->next;
            if(fast->next != NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseHalf(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next; // Move this line inside the loop
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head->next == NULL){
            return true;
        }

        ListNode* mid = getMid(head);
        ListNode* temp = mid->next;
        mid->next =  reverseHalf(temp);

        ListNode* head1 = head;
        ListNode* head2 = mid->next;

        while(head2!=NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};