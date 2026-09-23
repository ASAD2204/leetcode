class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0, head);
        ListNode* beforeLeft = &dummy;

        // 1. Reach the node just before 'left'
        for (int i = 0; i < left - 1; ++i) {
            beforeLeft = beforeLeft->next;
        }

        // 2. Standard Reverse Linked List I loop
        ListNode* sublistTail = beforeLeft->next; // Node 2
        ListNode* curr = sublistTail;
        ListNode* prev = nullptr;

        for (int i = 0; i <= right - left; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // 3. Reconnect the reversed sublist to the outside list
        beforeLeft->next = prev;      // 1 connects to 4
        sublistTail->next = curr;     // 2 connects to 5

        return dummy.next;
    }
};