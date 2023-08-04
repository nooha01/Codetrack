// https://leetcode.com/problems/linked-list-cycle/description/

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
    bool hasCycle(ListNode *head) {
	
        if(head == NULL)
            return false;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        
            if(fast == slow)
                return true;
        }
        
        return false;
    }
};


/*
INITIAL LOGIC
Very high time complexity

class Solution {
public:
    bool hasCycle(ListNode *head) {
    
    ListNode *temp = head;
    ListNode *inode;
    int count =0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }

    
    inode=head;
    for(int i=0;i<count;i++)
    {
        if(i!=0)
            inode=inode->next;
        temp=inode->next;
        for(int j=i+1;j<count;j++)
        {
            if(temp->next==inode)
                return true;
            else
                temp = temp->next;
        }
    }
    return false;

    }
};

*/