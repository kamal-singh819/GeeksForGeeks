//take first node as new head, and traverse remaiming list, onwards 2nd node if negative value, add it in front of head otherwise leave it as it is.
class Solution{    
public:
    Node* sortList(Node* head)
    {
        Node* curr = head->next;
        Node* prev = head;
        
        while(curr){
            if(curr->data < 0){
                prev->next = curr->next;
                curr->next = head;
                head = curr;
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;

    }
};
