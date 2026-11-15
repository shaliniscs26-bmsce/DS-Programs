/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Helper function to reverse a singly linked list
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {
    if (head == NULL) return NULL;

    // 1. Reverse the linked list
    head = reverse(head);

    // 2. Filter out nodes smaller than the running maximum
    struct ListNode* curr = head;
    int max_val = curr->val;

    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val < max_val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp); // Free memory of the removed node
        } else {
            curr = curr->next;
            max_val = curr->val;
        }
    }

    // 3. Reverse again to restore the original order
    return reverse(head);
}
