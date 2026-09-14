/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* current=head;
        while(current!=NULL){
            if(current->child!=NULL){
//flatten the child nodes
Node* next=current->next;
current->next=flatten(current->child);
current->next->prev=current;
current->child=NULL;
//find the tail node
while(current->next!=NULL){
    current=current->next;
}
//attach tail with next pointer
if(next!=NULL){
    current->next=next;
    next->prev=current;
}
            }
            current=current->next;
        }
        return head;
    }
};