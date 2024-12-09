#include <iostream>
using namespace std;

int queuesize = 10;

struct Queue {
    int *arr;
    int front;
    int rear;
    int cnt;

    Queue(int d) {
        arr = new int[d];
        front = -1;
        rear = -1;
        cnt = 0;
    }

    void enqueue(int d);
    int sizee();
    bool emptyy();
    int frontElement();
    int dequeue();
};

void Queue::enqueue(int d) {
    if (sizee() < queuesize) {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % queuesize;
        arr[rear] = d;
        cnt++;
        cout << "Enqueued " << d << " into the queue\n";
    } else {
        cout << "Overflow\n";
    }
}

int Queue::sizee() {
    return cnt;
}

bool Queue::emptyy() {
    return front == -1;
}

int Queue::frontElement() {
    if (emptyy()) {
        cout << "Queue is empty\n";
        return -1;
    }
    return arr[front];
}

int Queue::dequeue() {
    if (emptyy()) {
        cout << "Underflow\n";
        return -1;
    } else {
        int dequeuedData = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % queuesize;
        }
        cnt--;
        return dequeuedData;
    }
}

int main() {
    Queue q(10);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.frontElement() << endl;
    cout << "Current size: " << q.sizee() << endl;

    cout << "Dequeuing: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.frontElement() << endl;

    cout << "Is queue empty? " << (q.emptyy() ? "Yes" : "No") << endl;

    delete[] q.arr;

    return 0;
}
