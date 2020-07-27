/* 
    Remove all elements from a linked list of integers that have value val.

    Example:
    Input:  1->2->6->3->4->5->6, val = 6
    Output: 1->2->3->4->5
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *node = new ListNode();
        ListNode *res = node;

        while (head) {
            if (head->val != val) {
                node->next = head;
                node = node->next;
            }
            head = head->next;
        }
        node->next = nullptr; // if last node is val, second last node will contain reference to it.

        return res->next;
    }
};
