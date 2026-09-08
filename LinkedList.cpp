#include <iostream>
#include<stack>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* InsertAtHead(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
    return head;
}

ListNode* InsertAtTail(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        return newNode;
    }

    ListNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;

    return head;
}

ListNode* DeleteAthead(ListNode* head){
    ListNode* curr = head;
    head = head->next;
    delete curr;

    return head;
}

ListNode* DeleteAttail(ListNode* head){
    ListNode* curr = head;

    while(curr->next->next != nullptr){
        curr = curr->next;
    }

    curr->next = nullptr;

    return head;
}

int SearchNodeIdx(ListNode* head, int key){
    ListNode* curr = head;
    int cnt = 0;

    while(curr != nullptr){
        curr = curr->next;
        cnt++;

        if(curr->data == key){
            return cnt;
        }
    }
    return -1;
}

ListNode* DeleteByVal(ListNode* head, int key) {
    // 1. If list is empty
    if (head == nullptr) {
        return nullptr;
    }

    // 2. If the head node itself holds the key
    if (head->data == key) {
        ListNode* temp = head;
        head = head->next; // Move head to the next node
        delete temp;       // Free memory
        return head;
    }

    // 3. Search for the key to delete, keeping track of previous node
    ListNode* curr = head;
    while (curr->next != nullptr && curr->next->data != key) {
        curr = curr->next;
    }

    // 4. Key was found (curr->next is the node to delete)
    if (curr->next != nullptr) {
        ListNode* temp = curr->next;
        curr->next = curr->next->next; // Unlink the node from list
        delete temp;                   // Free memory
    }

    return head;
}

int lengthofLinkedlist(ListNode* head){
    ListNode* curr = head;
    int len=0;

    while(curr != nullptr){
        curr = curr->next;
        len++;
    }
    return len;
}

ListNode* middleofLL(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseLL(ListNode* head) {
    stack<int> st; // Store integer values instead of pointers

    ListNode* curr = head;
    while (curr != nullptr) {
        st.push(curr->data);
        curr = curr->next;
    }

    curr = head;
    while (!st.empty()) {
        curr->data = st.top();
        st.pop();
        curr = curr->next;
    }
    return head;
}

bool DetectLoop(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                isCycle = true;
                break;
            }
        }
        if(!isCycle){
            return NULL;
        }

        //  to find the starting point of the cycle 
        // hum slow ko fir se reinitilise karenge from head 
        // and iss baar slow and fast dono ko ek se hi update karte jayenge.
         slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        //jaha par slow and fast mil gaye matlab slow == fast ho gaya usko return karenge as slow.
        // jab tak nahi milta tab tak slow and fast ko +1 se update karenge.
        return slow;
}

bool isPalindrome(ListNode* head){
    vector<int>vec;

    ListNode* curr = head;

    while(curr != nullptr){
        vec.push_back(curr->data);
        curr = curr->next;
    }

    int left =0;
    int high = vec.size()-1;

    while(left < high){
        if(vec[left] != vec[high]){
            return false;
        }
        left++;
        high--;
    }
    return true;
}

ListNode* SortLL(ListNode* head){
        vector<int>vec;
        ListNode* curr = head;
        while(curr != nullptr){
            vec.push_back(curr->data);
            curr = curr->next;
        }

        sort(vec.begin(), vec.end());

        curr = head;
        int idx = 0;
        while(curr != nullptr){
            curr->data = vec[idx++];
            curr = curr->next;
        }
        return head;
}


int main() {
    // Correct node initialization using heap allocation
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // Get and print middle value
    ListNode* mid = middleofLL(head);
    if (mid != nullptr) {
        cout << "Middle Value: " << mid->data << endl; // Output: 2
    }
    
    // Demonstration of helper functions
    head = InsertAtHead(head, 0);   // List: 0 1 2 3
    head = InsertAtTail(head, 4);   // List: 0 1 2 3 4

    // Correct function call syntax
    printList(head);

    int ans = SearchNodeIdx(head, 2);
    cout<<"Element Key FOund at Index:"<<ans<<endl;

    head = DeleteAthead(head);
    head = DeleteAttail(head);

    printList(head);

    head = DeleteByVal(head, 2);
    printList(head);

    int length = lengthofLinkedlist(head);
    cout<<length<<endl;

    cout<<"Reversed Linked List is:";
    head = reverseLL(head);
    printList(head);

    cout<<detectCycle(head)<<endl;

    cout<<"is Palindrome aahe ka:";
    cout<<isPalindrome(head)<<endl;

    cout<<"SOrted LinkedList:";
    head = SortLL(head);
    printList(head);

    return 0;
}
