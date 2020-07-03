/* 

Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/* use two pointers, keep d distance between the.
solve for corner cases where remove node is last and first.
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* node = head;
    ListNode* remove;

    while (n-- && node->next) {
        node = node->next;
    }
    remove = head;

    while (node->next) {
        node = node->next;
        remove = remove->next;
    }

    if (remove == head && n == 0) return head->next;
    
    remove->next = remove->next->next;
    return head;
}
