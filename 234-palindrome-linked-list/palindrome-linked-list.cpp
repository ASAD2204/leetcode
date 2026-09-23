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
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        ListNode* temp=head;
        while(temp!=NULL){
            values.push_back(temp->val);
            temp=temp->next;
        }
        int size=values.size();
        int left=0;
        int right=size-1;
bool ispalindrome=true;
        while(left<=right){
            if(values[left]!=values[right]){
                ispalindrome=false;
                break;
            }
            left++;
            right--;
        }

return ispalindrome;
    }
};