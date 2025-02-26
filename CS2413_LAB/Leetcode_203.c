/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeElements(struct ListNode *head, int val)
{
    // Create a duplicate incase head needs to be removed
    struct ListNode *duplicate = (struct ListNode *)malloc(sizeof(struct ListNode));
    // Set next duplicate value equal to head
    duplicate->next = head;
    // set the current node to the empty duplicate node
    struct ListNode *current = duplicate;
    // checks everynode in the list
    while (current->next != NULL)
    {
        // checks if the value of the next node is equal to the assigned val
        if (current->next->val == val)
        {
            // creates a temp node to house current->next before deleting data
            struct ListNode *temp = current->next;
            // assigns the next value in list to remove assigned val
            current->next = current->next->next;
            // delete temp node to ensure no memory leak
            free(temp);
        }
        else
        {
            // moves on to next node
            current = current->next;
        }
    }
    // Head is reassigned with value of first real value in duplicate
    head = duplicate->next;
    // Free duplicate memory as to not cause memory leak
    free(duplicate);
    // return the new linked list
    return head;
}