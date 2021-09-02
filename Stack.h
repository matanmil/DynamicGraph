



template <class T>
// Class for stack
class Stack {
    T *arr;
    int top;
    int capacity;

public:


    Stack(unsigned size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }


    ~Stack() {
        delete []arr;
    }


    void push(T x) {
        if (!isFull()) {

            arr[++top] = x;
        }


    }

// Utility function to pop top element from the stack
    T pop() {

        if (!isEmpty()) {



            return arr[top--];
        }
    }


    T peek() {
        if (!isEmpty())
            return arr[top];

    }


    int size() {
        return top + 1;
    }


    bool isEmpty() {
        return top == -1;    // or return size() == 0;
    }


    bool isFull() {
        return top == capacity - 1;
    }
};
