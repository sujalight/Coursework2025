#include <iostream>
using namespace std;

class CustomQueue {
private:
    int arr[10];
    int front;
    int rear;
    int size;

public:
    CustomQueue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int value) {
        if (size >= 10) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % 10;
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (size <= 0) {
            cout << "Queue Underflow!" << endl;
            return -1; // Return a default value when underflow occurs
        }
        int value = arr[front];
        front = (front + 1) % 10;
        size--;
        return value;
    }

    void reverseFirstK(int k) {
        if (k > size || k <= 0) {
            cout << "Invalid K value!" << endl;
            return;
        }

        for (int i = 0; i < k / 2; i++) {
            int left = (front + i) % 10;
            int right = (front + k - 1 - i) % 10;
            swap(arr[left], arr[right]);
        }
    }

    void interleaveHalves() {
        if (size % 2 != 0) {
            cout << "Queue size must be even for interleaving!" << endl;
            return;
        }

        int half = size / 2;
        int firstIndex = front;
        int secondIndex = (front + half) % 10;
        int temp[size];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[(front + i) % 10];
        }

        for (int i = 0; i < half; i++) {
            arr[(front + 2 * i) % 10] = temp[firstIndex];
            arr[(front + 2 * i + 1) % 10] = temp[secondIndex];
            firstIndex = (firstIndex + 1) % size;
            secondIndex = (secondIndex + 1) % size;
        }
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % 10] << " ";
        }
        cout << endl;
    }
};

int main() {
    CustomQueue queue;

    for (int i = 1; i <= 8; i++) {
        queue.enqueue(i);
    }

    queue.display();

    queue.reverseFirstK(5);
    queue.display();

    queue.interleaveHalves();
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.display();

    return 0;
}
