class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow= head;
        Node* fast= head;
        int len=0;
        
        while(fast && fast->next){
            slow= slow->next;
            fast= fast->next->next;
            
            //when slow becomes equal to fast loop exists
            if(slow == fast){
                len=1; //set length as one and start counting from next node
                Node* temp= slow->next;
                
                while(temp!=slow){
                    len++;
                    temp= temp->next;
                }
                return len;
            }
        }
        //no loop detected
        return 0;
    }
};
