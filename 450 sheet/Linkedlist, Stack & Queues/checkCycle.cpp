// check if linkedlist has cycle or not
//  Floyd’s Cycle-Finding Algorithm
// https://leetcode.com/problems/linked-list-cycle/submissions/
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
//     bool hasCycle(ListNode *head) {
//         if(head==NULL || head->next==NULL)
//             return 0;
//         ListNode  *slow=head,*fast=head;
//       
//         while(slow->next != fast->next->next)
//         {
              
                
//                 slow=slow->next;
//                 if(fast->next==NULL)
//                     return 0;
//                 fast=fast->next->next;
//                 if(fast==NULL || fast->next==NULL)
//                     return 0;
           
            
//         }
        
//         return 1;            
//     }
    
    
    // easy solution
     bool hasCycle(ListNode *head) {
        
        ListNode  *slow=head,*fast=head;
    
        while(fast!=NULL && fast->next!=NULL)
        {   
                slow=slow->next;
            
                fast=fast->next->next;
                if(slow==fast)
                    return 1;
        
        }
        
        return 0;            
    }
};