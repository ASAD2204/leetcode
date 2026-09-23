class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Advance current to the last node of the duplicate sequence
                while (current->next != nullptr && current->val == current->next->val) {
                    current = current->next;
                }
                // Skip all duplicates by linking prev to the node after the last duplicate
                prev->next = current->next;
                // Move current to the new candidate node
                current = prev->next;
            } else {
                // Current is distinct; advance both pointers
                prev = prev->next;
                current = current->next;
            }
        }

        return dummy.next;
    }
};