/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        vector<int>allvalues;
        // iterate through each Linkedlist
        for(auto li: arr){
            while(li != NULL){
                allvalues.push_back(li->val);
                li = li->next;
            }
        }
        
        // trying to solve all  the collected values in vector allvalues
        sort(allvalues.begin(), allvalues.end());
        
        // create a dummy head for the final result List
        Node* dummy = new ListNode(0);
        Node* curr = dummy;
        
        for(int val: allvalues){
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
