#include<unordered_set>
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head == NULL)
            return;
        if(head->next == head)
            head->next = NULL;
            
        Node* temp = head;
        unordered_set<Node*> st;
        st.insert(temp);
        while(st.count(temp->next) == 0){
            st.insert(temp->next);
            temp = temp->next;
            if(temp == NULL)
                return;
        }
        if(st.count(temp->next) == 1)
            temp->next = NULL;
    }
};
