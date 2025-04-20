class Solution {
  public:
    struct compare{
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        //suppose arr has n list, then in first iteration head of 1 list is accessed
        for(Node* list: arr){
            //for that 1 list if head exists that is inserted
            if(list) pq.push(list); 
            //same repeated for second set of list
            //here list is head
        }
        
        Node* dummy= new Node(-1);
        Node* tail= dummy;
        
        while(!pq.empty()){
            Node* smallest= pq.top();
            pq.pop();
            
            tail->next= smallest;
            tail= tail->next;
            
            if(smallest->next) pq.push(smallest->next);
        }
        return dummy->next;
    }
};
