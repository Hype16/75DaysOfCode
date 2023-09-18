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
    ListNode* reverseKGroup(ListNode* head, int k) {
      //Base Case
      if(head == NULL){
          return NULL;
      }  
      //Step 0-For LeetCode only(Check agar remaining node k se kam hai to       bina     reverse ke as it is lauta do.
      ListNode* check = head;
      int count = 0;
      while (check != NULL && count < k) {
            check = check->next;
            count++;
      }

        // If there are less than k nodes left, do not reverse
      if (count < k) {
            return head;
      }  
      //Step 1 - Reverse k nodes
      ListNode* prev =NULL;
      ListNode* curr =head;
      ListNode* next =NULL;
      count = 0;

      while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
      }

      //Step2 - Now aage ka reccursion ko de do
      if(next != NULL){
        head->next = reverseKGroup(next,k);
      }
      return prev;
    }
};