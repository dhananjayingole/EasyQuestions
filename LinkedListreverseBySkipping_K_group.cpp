#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
private:
    // Helper function to reverse 'k' nodes using a stack
    Node* reverseKGroupUsingStack(Node* head, int k) {
        stack<Node*> st;
        Node* current = head;

        // Push 'k' nodes onto the stack
        while (current != nullptr && st.size() < static_cast<size_t>(k)) {
            st.push(current);
            current = current->next;
        }

        // If we have fewer than k nodes, return head as-is (or reverse what's left if preferred)
        // Here, we reverse whatever is in the stack
        if (st.empty()) return nullptr;

        Node* newHead = st.top();
        st.pop();
        Node* prev = newHead;

        while (!st.empty()) {
            prev->next = st.top();
            st.pop();
            prev = prev->next;
        }

        // Connect the tail of the reversed group to the aremaining list
        prev->next = current;

        return newHead;
    }

public:
    Node* reverseAlternateKNodes(Node* head, int k) {
        if (!head || k <= 1) return head;

        // 1. Reverse the first k nodes using the stack
        Node* newHead = reverseKGroupUsingStack(head, k);

        // 'head' is now the tail of the newly reversed first block.
        // Navigate 'k' nodes forward from head to skip the unreversed block.
        Node* current = head;
        int count = 0;

        // 2. Skip the next k nodes
        while (current != nullptr && current->next != nullptr && count < k) {
            current = current->next;
            count++;
        }

        // 3. Recursively process the rest of the list
        if (current != nullptr && current->next != nullptr) {
            current->next = reverseAlternateKNodes(current->next, k);
        }

        return newHead;
    }
};

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << (temp->next ? "->" : "");
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to free allocated memory
void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Construct list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 8; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    int k = 2;

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.reverseAlternateKNodes(head, k);

    cout << "Modified List: ";
    printList(head);

    freeList(head);
    return 0;
}
