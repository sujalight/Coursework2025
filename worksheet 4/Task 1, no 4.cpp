#include <iostream>
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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position\n";
            return;
        }
        if (position == 1) {
            insertAtStart(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeLoop() {
        Node* slow = head;
        Node* fast = head;
        bool hasLoop = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasLoop = true;
                break;
            }
        }
        if (!hasLoop) {
            cout << "No loop detected\n";
            return;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        Node* loopNode = fast;
        while (loopNode->next != fast) {
            loopNode = loopNode->next;
        }
        loopNode->next = nullptr;
        cout << "Loop removed\n";
    }

    void findNthFromEnd(int n) {
        Node* first = head;
        Node* second = head;
        for (int i = 0; i < n; i++) {
            if (second == nullptr) {
                cout << "The list is shorter than " << n << " elements.\n";
                return;
            }
            second = second->next;
        }
        while (second != nullptr) {
            first = first->next;
            second = second->next;
        }
        if (first != nullptr) {
            cout << "The " << n << "th node from the end is: " << first->data << endl;
        }
    }

    void reverseInGroups(int k) {
        head = reverseInGroupsUtil(head, k);
    }

    Node* reverseInGroupsUtil(Node* head, int k) {
        if (head == nullptr) return nullptr;
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;
        while (current != nullptr && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next != nullptr) {
            head->next = reverseInGroupsUtil(next, k);
        }
        return prev;
    }

    void display() {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }
};

int main() {
    LinkedList list;
    list.insertAtStart(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtPosition(25, 3);

    cout << "Original List: ";
    list.display();

    list.findNthFromEnd(2);

    cout << "Reversing in groups of 2...\n";
    list.reverseInGroups(2);
    list.display();

    list.insertAtEnd(60);
    Node* loopNode = list.getHead()->next->next->next;
    if (loopNode != nullptr) {
        list.getHead()->next->next->next->next->next = loopNode;
    }

    list.removeLoop();

    cout << "List after loop removal: ";
    list.display();

    return 0;
}
