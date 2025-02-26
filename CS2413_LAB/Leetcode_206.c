/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    // Previous node set initially NULL
    struct ListNode* prev = NULL;      
    // Current node (starts at head)
    struct ListNode* current = head;   
    // Temporary storage for next node set initially NULL
    struct ListNode* next = NULL;      
    //Continues until end of list
    while (current != NULL) {  
        // Save the next node
        next = current->next;   
        // Reverse current node's pointer from next to prev
        current->next = prev;  
         // Move prev forward down the linked list
        prev = current;         
        // Move current forward down the linked list
        current = next;         
    }

    return prev;  // New head of the reversed list 
}
