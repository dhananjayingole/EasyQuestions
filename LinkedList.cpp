#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <algorithm>

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
    return newNode;
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

ListNode* DeleteAthead(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* curr = head;
    head = head->next;
    delete curr;

    return head;
}

ListNode* DeleteAttail(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    ListNode* curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;

    return head;
}

int SearchNodeIdx(ListNode* head, int key) {
    ListNode* curr = head;
    int cnt = 0;

    while (curr != nullptr) {
        if (curr->data == key) {
            return cnt;
        }
        curr = curr->next;
        cnt++;
    }
    return -1;
}

ListNode* DeleteByVal(ListNode* head, int key) {
    if (head == nullptr) return nullptr;

    if (head->data == key) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* curr = head;
    while (curr->next != nullptr && curr->next->data != key) {
        curr = curr->next;
    }

    if (curr->next != nullptr) {
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    return head;
}

int lengthofLinkedlist(ListNode* head) {
    ListNode* curr = head;
    int len = 0;

    while (curr != nullptr) {
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
    stack<int> st;

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

bool DetectLoop(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            isCycle = true;
            break;
        }
    }
    if (!isCycle) {
        return NULL;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

bool isPalindrome(ListNode* head) {
    vector<int> vec;
    ListNode* curr = head;

    while (curr != nullptr) {
        vec.push_back(curr->data);
        curr = curr->next;
    }

    int left = 0;
    int high = vec.size() - 1;

    while (left < high) {
        if (vec[left] != vec[high]) {
            return false;
        }
        left++;
        high--;
    }
    return true;
}

ListNode* SortLL(ListNode* head) {
    vector<int> vec;
    ListNode* curr = head;
    while (curr != nullptr) {
        vec.push_back(curr->data);
        curr = curr->next;
    }

    sort(vec.begin(), vec.end());

    curr = head;
    int idx = 0;
    while (curr != nullptr) {
        curr->data = vec[idx++];
        curr = curr->next;
    }
    return head;
}

ListNode* getIntersection(ListNode* headA, ListNode* headB) {
    unordered_set<ListNode*> st;

    ListNode* currA = headA;
    while (currA != nullptr) {
        st.insert(currA);
        currA = currA->next;
    }

    ListNode* currB = headB;
    while (currB != nullptr) {
        if (st.find(currB) != st.end()) {
            return currB;
        }
        currB = currB->next;
    }
    return nullptr;
}

ListNode* AddtwoLinkedList(ListNode* head1, ListNode* head2) {
    ListNode* DummyNode = new ListNode(-1);
    ListNode* curr = DummyNode;
    int carry = 0;

    ListNode* l1 = head1;
    ListNode* l2 = head2;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    return DummyNode->next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(4);

    cout << "Sum of Two LinkedList is: ";
    ListNode* Sum = AddtwoLinkedList(head, head2);
    printList(Sum);

    ListNode* mid = middleofLL(head);
    if (mid != nullptr) {
        cout << "Middle Value: " << mid->data << endl;
    }
    
    head = InsertAtHead(head, 0);   
    head = InsertAtTail(head, 4);   

    cout << "List after insertions: ";
    printList(head);

    int ans = SearchNodeIdx(head, 2);
    cout << "Element Key Found at Index: " << ans << endl;

    head = DeleteAthead(head);
    head = DeleteAttail(head);

    cout << "List after head & tail deletion: ";
    printList(head);

    head = DeleteByVal(head, 2);
    cout << "List after deleting value 2: ";
    printList(head);

    int length = lengthofLinkedlist(head);
    cout << "Length: " << length << endl;

    cout << "Reversed Linked List is: ";
    head = reverseLL(head);
    printList(head);

    cout << "Detect cycle: " << (DetectLoop(head) ? "Yes" : "No") << endl;

    cout << "Is Palindrome: " << (isPalindrome(head) ? "Yes" : "No") << endl;

    cout << "Sorted LinkedList: ";
    head = SortLL(head);
    printList(head);

    return 0;
}
