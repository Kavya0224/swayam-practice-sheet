class MyCircularQueue {
public:
    // Vector to store elements in the circular queue
    vector<int> v;

    // Rear points to the index where the next element will be inserted
    // Front points to the index of the current front element
    int rear = 0;
    int front = 0;

    // n is the size of the circular buffer (k + 1 to distinguish full vs empty)
    int n;

    // Constructor: initialize the circular queue with capacity k
    MyCircularQueue(int k) {
        // Use k + 1 space to differentiate between full and empty
        v = vector<int>(k + 1);
        n = k + 1;
    }

    // Inserts an element into the circular queue
    bool enQueue(int value) {
        // If the queue is full, insertion fails
        if (isFull()) return false;

        // Place value at the rear position
        v[rear] = value;

        // Move rear pointer forward (circularly)
        rear = (rear + 1) % n;

        return true;
    }

    // Deletes an element from the circular queue
    bool deQueue() {
        // If the queue is empty, deletion fails
        if (isEmpty()) return false;

        // Move front pointer forward (circularly)
        front = (front + 1) % n;

        return true;
    }

    // Gets the front item from the queue
    int Front() {
        if (isEmpty()) return -1;

        // Return the element at the front pointer
        return v[front];
    }

    // Gets the last item from the queue
    int Rear() {
        if (isEmpty()) return -1;

        // Rear points to the next insertion position,
        // so the last item is one step behind rear
        int ele = (rear == 0) ? n - 1 : rear - 1;
        return v[ele];
    }

    // Checks whether the circular queue is empty
    bool isEmpty() {
        return front == rear;
    }

    // Checks whether the circular queue is full
    bool isFull() {
        // Queue is full when moving rear forward would meet front
        return (rear + 1) % n == front;
    }
};
