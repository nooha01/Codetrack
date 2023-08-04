// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode* temp=head;
        
        int len=0;

        while(temp!=NULL){
            temp=temp->next;
            len++;
        }

        if(n>len){
            return NULL;
        }
        if(len-n==0){
            head=head->next;
            return head;
        }
        struct ListNode* pre=head;
        temp=head;

        for(int i=0;i<len-n;i++){
            pre=temp;
            temp=temp->next;
        }
        pre->next=temp->next;
        return head;
       
    }
};






/*
Approach
It starts by creating a temporary pointer temp and setting it to the head of the linked list.
It calculates the length of the linked list by traversing through the list using the temp pointer and keeping track of the number of nodes encountered (stored in the len variable).
If the value of n is greater than the length of the linked list (n > len), it means the nth node from the end doesn't exist, and the function returns NULL.
If len - n is zero, it means the first node needs to be removed. In this case, it updates the head of the linked list to the next node and returns the new head.
Otherwise, it sets up two more pointers, pre and temp, and initializes them to the head of the linked list.
It then advances the temp pointer len - n times so that it points to the nth node from the end of the list.
Once temp points to the nth node from the end, it changes the next pointer of the node before temp (pointed by pre) to skip temp and point directly to the node after temp.
Finally, it returns the head of the modified linked list.
Complexity
Time complexity:
O(n)

Space complexity:
O(1)
*/