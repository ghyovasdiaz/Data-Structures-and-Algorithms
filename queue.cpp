#include <iostream>

using namespace std;

class Queue {
private:
    int frontIndex;
    int rearIndex;
    int capacity;
    int size;
    int *queue;

public:
    Queue(int queueCapacity) {
        capacity = queueCapacity;
        queue = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    void enqueue(int value) {
        // Check if the queue is full
        if (size == capacity) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        queue[rearIndex] = value;
        size++;
    }

    void dequeue() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    int front() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
            return -1; // or any other suitable default value
        }

        return queue[frontIndex];
    }

    bool isEmpty() {
        return (size == 0);
    }

    int getSize() {
        return size;
    }
};

int main() {
    cout << endl;
    Queue queue(3);

    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(7);

    cout << "Front element: " << queue.front() << endl;

    queue.dequeue();
    cout << "Front element after dequeue: " << queue.front() << endl;

    queue.dequeue();
    cout << "Front element after dequeue: " << queue.front() << endl;

    queue.dequeue();
    cout << "Front element after dequeue: " << queue.front() << endl;

    queue.enqueue(100);

    cout << "Queue size: " << queue.getSize() << endl;

    while (!queue.isEmpty()) {
        queue.dequeue();
    }
    cout << "Queue size after dequeue all: " << queue.getSize() << endl;

    return 0;
}
