class Solution {
    spublic:
        ListNode* oddEvenList(ListNode* head) {
            
            if(!head || !head->next) return head;
            
            ListNode * first = head;
            ListNode * second = head->next;
            ListNode * aux = second;
            
            while(second){
                if(!second->next){
                    first->next = aux;
                    return head;
                }
                first->next = second->next;
                first = first->next;
                second->next = first->next;
                second = second->next;
            }
            first->next = aux;
            
            return head;
        }
};