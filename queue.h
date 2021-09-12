#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> {
    public:
        QueueArray() : CircularArray<T>() {}

        QueueArray(int size) : CircularArray<T>(size) {}
        
        void enqueue(T value) : push_back(value) {}

        T dequeue() : pop_front() {}

        /*
        T front() {
            return array[front];
        }
        */

        ~QueueArray() : ~CircularArray<T>() {}
};