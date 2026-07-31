#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
     int val;
     ListNode* next;
     
     // Constructor
     ListNode(int val) {
         this->val = val;
         this->next = nullptr;
     }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

ListNode* middleOfLinkedList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Fixed condition: use && instead of ||
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next; 
    }
    return slow;
}

ListNode* ReverseLL(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    stack<int> st;
    ListNode* curr = head;
    
    while (curr != NULL) {
        st.push(curr->val);
        curr = curr->next;
    }
    
    curr = head;
    while (!st.empty()) {
        curr->val = st.top();
        st.pop();
        curr = curr->next;
    }
    return head;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "List is Empty" << endl;
        return 0;
    }
    
    int val;
    cout << "Enter " << n << " values: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* curr = head;
    
    // Read remaining nodes
    for (int i = 1; i < n; i++) {
        cin >> val;
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    
    cout << "Original LL: ";
    printList(head);
    
    // Print the middle element value
    ListNode* mid = middleOfLinkedList(head);
    cout << "Mid Ele is : " << mid->val << endl;
    
    head = ReverseLL(head);
    
    cout << "Reversed LL: ";
    printList(head);
    
    return 0;
}
