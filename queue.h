#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> {
    public:        
        void enqueue(T value){
            push_back(value);
        }
        
        T dequeue(){
            return pop_front();
        }
    
        T front() {
            return array[front];
        }
};