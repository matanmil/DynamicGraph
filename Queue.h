

#ifndef QUEUE_H
#define QUEUE_H

#include "Graph_Node.h"



template <class T>

// Class for queue
class Queue
{
    T* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:

Queue(unsigned size)
{
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
~Queue()
{

    delete []arr;

}
Queue(const Queue& q):arr(new T[q.capacity]),
    capacity(q.capacity),
    front(q.front),rear(q.rear),count(q.count){
        for(int i =0; i<count;i++)
        {
            arr[i] = q.arr[i];
        }
    }


void dequeue()
{

    if (!isEmpty())
    {
        front = (front + 1) % capacity;
        count--;
    }




}


void enqueue(T item)
{
    if (!isFull())
    {

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }



}

// Utility function to return front element in the queue
T peek()
{
    if (!isEmpty())
    {
        //cout << "UnderFlow\nProgram Terminated\n";
        return arr[front];
    }else{
        return NULL;
    }

}

// Utility function to return the size of the queue
int size()
{
    return count;
}

// Utility function to check if the queue is empty or not
bool isEmpty()
{
    return (size() == 0);
}

// Utility function to check if the queue is full or not
bool isFull()
{
    return (size() == capacity);
}
void print_queue(std::ostream &stream)
{
    while (!isEmpty())
    {
        stream << peek() << ",";
        dequeue();
    }

}
T pop()
{
    if (!isEmpty())
    {
        T temp = arr[front];
        dequeue();
        return temp;
    }

}


};
#endif
