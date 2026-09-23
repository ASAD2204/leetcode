/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute length
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        k = k % length;
        if (k == 0) return head;

        // Step 2: Advance fast pointer by k steps
        ListNode* fast = head;
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }

        // Step 3: Move fast and slow together until fast is at the tail
        ListNode* slow = head;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 4: Reconnect and cut
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};