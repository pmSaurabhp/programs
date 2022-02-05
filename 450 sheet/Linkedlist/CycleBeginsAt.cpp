// finds  node where the cycle begins

// https://leetcode.com/problems/linked-list-cycle-ii/submissions/
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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode  *slow=head,*fast=head,*point=head;
        int f=0;
        while(fast!=NULL && fast->next!=NULL)  // detects cycle
        {   
                slow=slow->next;
            
                fast=fast->next->next;
                if(slow==fast)
                { f=1;
                 break;
                }
        
        }
        if(f==0)
            return NULL;
        else{
            while(slow!=point)    // finds  node where the cycle begins
            {
                slow=slow->next;
                point=point->next;
            }
        }
        return point;
                   
    }
    
};