#include "main.h"

Queue::Queue() : front(-1), rear(-1) {
}

bool Queue::isEmpty() const {
    return front == -1;
}

bool Queue::push(const motion &element) {
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    items[rear] = element;
    return true;
}

void Queue::pop() {
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

motion Queue::first() const {
    return items[front];
}
