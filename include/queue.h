#ifndef QUEUE
#define QUEUE

#define MAX_SIZE 20

struct motionMove {
    uint8_t part, degree;
};

struct motion {
    float duration;
    float x1, y1, x2, y2;
    uint8_t len;
    motionMove motion_moves[8];
};

class Queue {
    motion items[MAX_SIZE]{};
    int front;
    int rear;

public:
    Queue();

    bool isEmpty() const;

    bool push(const motion &element);

    void pop();

    motion first() const;
};

#endif
