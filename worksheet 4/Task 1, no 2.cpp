#include <iostream>
using namespace std;

class CustomStack {
private:
    int arr[10];
    int top;
    int size;

public:
    CustomStack() {
        top = -1;
        size = 0;
    }


    void push(int value) {
        if (size >= 10) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        size++;
    }


    int pop() {
        if (size <= 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        size--;
        return arr[top--];
    }

    int findMiddle() {
        if (size == 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[size/2];
    }

    void reverseBottomHalf() {
        if (size < 2) return;

        int half = size/2;
        for (int i = 0; i < half/2; i++) {
            int temp = arr[i];
            arr[i] = arr[half - 1 - i];
            arr[half - 1 - i] = temp;
        }
    }


    void display() {
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CustomStack stack;

    for (int i = 1; i <= 10; i++) {
        stack.push(i);
    }

    cout << "Initial stack:" << endl;
    stack.display();

    cout << "\nMiddle element: " << stack.findMiddle() << endl;

    cout << "\nReversing bottom half:" << endl;
    stack.reverseBottomHalf();
    stack.display();

    cout << "\nPopping two elements:" << endl;
    stack.pop();
    stack.pop();
    stack.display();



    return 0;
}
